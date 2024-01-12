#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "mrufka.h"

char* ant_obejct[][4] = {{"▲", "▶", "▼", "◀"},{"△", "▷", "▽", "◁"}};

void print_to_file (simulation simulation, char* filename, int iteration){

    int temp = iteration;
    int iteration_len = 0;

    while (temp != 0) {
        iteration_len++;
        temp /= 10;
    }


    int len = strlen("save/_") + 1 + strlen(filename) + iteration_len;
    char* full_filename = malloc(len);
    if (full_filename == NULL) {
        printf("Błąd pamięci!\n");
        exit(1);
    }
    snprintf(full_filename, len, "save/%s_%d", filename, iteration);
    
    FILE *out = fopen(full_filename, "w");
    if (out == NULL) {
        printf("Nie można otworzyć pliku do zapisu\n");
        free(full_filename);
        exit(1);
    }
    int i;

    fprintf(out,"┌");

    for (i = 0;i<simulation->size.x;i++){
        fprintf(out,"─");
    }

    fprintf(out,"┐\n");

    for (int i = 0;i<simulation->size.y;i++){
        fprintf(out,"│");
        for (int j = 0;j<simulation->size.x;j++){
            if (i == simulation->current_pos.y && j == simulation->current_pos.x)
                fprintf(out,"%s", ant_obejct[simulation->grid[i][j]][simulation->direction]);
            
            else if (simulation->grid[i][j] == 0)
                fprintf(out, " ");
            else
                fprintf(out,"█");
        }

        fprintf(out,"│\n");
    }

    fprintf(out,"└");

    for (i = 0;i<simulation->size.x;i++){
        fprintf(out,"─");
    }

    fprintf(out,"┘\n");


    fclose(out);
    free(full_filename);
}