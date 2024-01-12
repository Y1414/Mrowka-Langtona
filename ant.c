#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "mrufka.h"

coordinates change_coordinates (coordinates coordinates, int direction){

    switch (direction)
    {
    case 0:
        coordinates.y -= 1;    
        break;
    case 1:
        coordinates.x += 1;
        break;
    case 2:
        coordinates.y += 1;
        break;
    case 3:
        coordinates.x -=1;
        break;
    default:
        printf("Nieznany kierunek");
        exit(1);
        break;
    }

    return coordinates;
}

void ant_loop (simulation simulation, int iterations, char*filename){
    int i = 1;
    while (iterations != 0){
        iterations--;
        printf("\033[H");
        
        system("clear");
        print_grid(simulation, i);
        if (filename)
            print_to_file(simulation, filename, i);
        i++;


        int* current = &simulation->grid[simulation->current_pos.y][simulation->current_pos.x];
        switch (simulation->grid[simulation->current_pos.y][simulation->current_pos.x])
        {
        case 0:
            //change direction
            if (simulation->direction < 3)
                simulation->direction += 1;
            else
                simulation->direction -= 3;

            //change color
            *current = 1;
            break;
        
        case 1:
            if (simulation->direction > 0)
                simulation->direction -= 1;
            else
                simulation->direction += 3;

            *current = 0;

            break;

        default:
            fprintf(stderr, "Kolor pola nieznany");
            break;
        }
        
        //move
        simulation->current_pos = change_coordinates(simulation->current_pos, simulation->direction);

        if (simulation->current_pos.x >= simulation->size.x || simulation->current_pos.x < 0 || simulation->current_pos.y >= simulation->size.y ||  simulation->current_pos.y < 0){
            break;
        }
        usleep(40000);
        
        
    }
    for (int i = 0; i < simulation->size.y; i++) 
        free(simulation->grid[i]);
    free(simulation);
}



