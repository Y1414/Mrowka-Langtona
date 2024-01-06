#include <stdlib.h>
#include <stdio.h>
#include "mrufka.h"



simulation generate_grid (int width, int height){
    simulation new_simulation = malloc(sizeof(simulation));
    
    new_simulation->grid = malloc(height * sizeof(int*));

    new_simulation->size.y = height;
    new_simulation->size.x = width;

    for (int i = 0;i<height;i++){
        new_simulation->grid[i] = malloc(width*sizeof(int));
        for (int j = 0;j<width;j++)
            new_simulation->grid[i][j] = 0;
    }
    return new_simulation;
}


void print_grid(simulation simulation){

    int i;

    printf("┌");

    for (i = 0;i<simulation->size.x;i++){
        printf("─");
    }

    printf("┐\n");

    for (int i = 0;i<simulation->size.y;i++){
        printf("│");
        for (int j = 0;j<simulation->size.x;j++){
            if (simulation->grid[i][j] == 0)
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

    printf("┘");


    printf("current ant position: (%d, %d)\n", simulation->current_pos.x, simulation->current_pos.y);


}