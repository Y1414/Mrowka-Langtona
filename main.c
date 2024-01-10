#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <getopt.h>
#include "mrufka.h"



int main(int argc, char **argv){

    int option;
    int size_x;
    int size_y;

    if (argc < 2){


    }

    while ((option = getopt(argc, argv, "s:i:r:f:m:n:")) !=-1){
        switch (option){
            // random - procent przeskód
            case 'r' :
            // file - wczytywanie z pliku 
            case 'f' :
            // save - plik do wypisywania  
            case 's' :
            // iteracja 
            case 'i' :
            // m - wysokość 
            case 'm' :
                size_x = atoi(optarg);
            // n - szerokość 
            case 'n' :
                size_y = atoi(optarg);
            default : 

        }
    }

    if (size_x == 0 || size_y == 0){
        printf("Błąd! Zły typ wywoływanych argumentów!\n");
        return 0;
    }

    simulation simulation = generate_grid(size_x, size_y);
    
    simulation->current_pos.x = (size_x/2);
    simulation->current_pos.y = (size_y/2);
    simulation->direction = 0;

    ant_loop (simulation);
    return 0;
}