#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "mrufka.h"


simulation generate_grid (int width, int height, double percentage){
    simulation new_simulation = malloc(sizeof(simulation));
    
    new_simulation->grid = malloc(height * sizeof(int*));

    new_simulation->size.y = height;
    new_simulation->size.x = width;
    new_simulation->direction = 0;

    int cells_to_set = (int)(percentage * width * height);

    srand(time(NULL));

    for (int i = 0; i < height; i++) {
        new_simulation->grid[i] = malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) 
            new_simulation->grid[i][j] = 0;
    }

    while (cells_to_set > 0){
        int i = rand()%height;
        int j = rand()%width;
        if (new_simulation->grid[i][j] == 0){
            new_simulation->grid[i][j] = 1;
            cells_to_set--;
        }
    }

    return new_simulation;
}


void print_grid(simulation simulation, int counter){
    char* ant_obejct[][4] = {{"▲", "▶", "▼", "◀"},{"△", "▷", "▽", "◁"}};
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

    printf("Pozycja mrówki: (%d, %d), Iteracja: %d\n", simulation->current_pos.x, simulation->current_pos.y,counter);
}

