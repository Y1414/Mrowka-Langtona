#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mrufka.h"

int main(){
    
    simulation simulation = generate_grid(100, 100);
    

    simulation->current_pos.x = 50;
    simulation->current_pos.y = 50;
    simulation->direction = 2;

    int i;
    while (true){
        i++;
        print_grid(simulation);

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

        if (simulation->current_pos.x > simulation->size.x || simulation->current_pos.x < 0 || simulation->current_pos.y > simulation->size.y ||  simulation->current_pos.y < 0){
            break;
        }

    }
    print_grid(simulation);
    return 0;
}