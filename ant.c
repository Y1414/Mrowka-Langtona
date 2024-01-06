#include <stdio.h>
#include <stdlib.h>

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