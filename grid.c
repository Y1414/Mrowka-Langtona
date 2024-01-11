#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "mrufka.h"

char* ant_obejct[][4] = {{"▲", "▶", "▼", "◀"},{"△", "▷", "▽", "◁"}};



simulation generate_grid (int width, int height, double percentage){
    simulation new_simulation = malloc(sizeof(simulation));
    
    new_simulation->grid = malloc(height * sizeof(int*));

    new_simulation->size.y = height;
    new_simulation->size.x = width;

    int total_cells = width * height;
    int ones_to_set = (int)(percentage * total_cells);

    srand(time(NULL));

    for (int i = 0; i < height; i++) {
        new_simulation->grid[i] = malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            if (ones_to_set > 0 && rand() % total_cells < ones_to_set) {
                new_simulation->grid[i][j] = 1;
                ones_to_set--;
            } else {
                new_simulation->grid[i][j] = 0;
            }
            total_cells--;
        }
    }

    while (ones_to_set > 0){
        int i = rand()%height;
        int j = rand()%width;
        if (new_simulation->grid[i][j] == 0){
            new_simulation->grid[i][j] = 1;
            ones_to_set--;
        }
    }





    return new_simulation;
}


void print_grid(simulation simulation, int counter){
    
    int i;

    printf("┌");

    for (i = 0;i<simulation->size.x;i++){
        printf("─");
    }

    printf("┐\n");

    for (int i = 0;i<simulation->size.y;i++){
        printf("│");
        for (int j = 0;j<simulation->size.x;j++){
            if (i == simulation->current_pos.y && j == simulation->current_pos.x)
                printf("%s", ant_obejct[simulation->grid[i][j]][simulation->direction]);
            
            else if (simulation->grid[i][j] == 0)
                printf(" ");
            else
                printf("█");
        }

        printf("│\n");
    }

    printf("└");

    for (i = 0;i<simulation->size.x;i++){
        printf("─");
    }

    printf("┘\n");


    printf("current ant position: (%d, %d), Step: %d\n", simulation->current_pos.x, simulation->current_pos.y,counter);
}

