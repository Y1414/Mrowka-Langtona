#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <getopt.h>
#include "mrufka.h"



int main(int argc, char **argv){

    int option;
    int size_x = 150;
    int size_y = 25;
    int i = -1;
    double percentage = 0.0;
    

    if (argc < 2){


    }

    while ((option = getopt(argc, argv, "s:i:r:f:m:n:")) !=-1){
        switch (option){
            // random - procent przeskód
            case 'r' :
                percentage = atof(optarg);
                break;
            // file - wczytywanie z pliku 
            case 'f' :
                break;
            // save - plik do wypisywania  
            case 's' :
                break;
            // iteracja 
            case 'i' :
                i = atoi(optarg);
                break;
            // m - wysokość 
            case 'm' :
                size_y = atoi(optarg);
                break;
            // n - szerokość 
            case 'n' :
                size_x = atoi(optarg);
                break;
            case '?':
                //fprintf(stderr, "Nieznana flaga -%s\n", optarg);
                return 1;
            default : 

        }
    }

    if (size_x == 0){
        printf("Nieprawidłowa szerokość planszy\n");
        return 1;
    }
    if (size_y == 0){
        printf("Nieprawidłowa wysokość planszy\n");
        return 1;
    }

    if (percentage > 100 || percentage < 0){
        printf("Nieprawidłowy procent!\n");
        return 1;
    }

    simulation simulation = generate_grid(size_x, size_y, (double)percentage/100);
    
    simulation->current_pos.x = (size_x/2);
    simulation->current_pos.y = (size_y/2);
    simulation->direction = 0;

    ant_loop (simulation,i);
    return 0;
}