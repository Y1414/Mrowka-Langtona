#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/stat.h>
#include <errno.h>

#include "mrufka.h"



int main(int argc, char **argv){

    int option, direction = 0;
    int size_x = 100;
    int size_y = 25;
    int i = -1;
    double percentage = 0.0;
    char* filename = NULL;
    FILE*in = NULL;

    if (mkdir("tmp", 0755) == -1) {
        if (errno != EEXIST) {
            fprintf(stderr,"Błąd w tworzeniu folderu");
            return 1;
        }
    }
    if (mkdir("save", 0755) == -1) {
        if (errno != EEXIST) {
            fprintf(stderr,"Błąd w tworzeniu folderu");
            return 1;
        }
    }


    while ((option = getopt(argc, argv, "s:i:r:f:m:n:d:")) !=-1){
        switch (option){
            // random - procent przeskód
            case 'r' :
                percentage = atof(optarg);
                break;
            // file - wczytywanie z pliku 
            case 'f' :
                in = fopen(optarg, "r");
                if (in == NULL){
                    fprintf(stderr, "Błąd w cztyaniu %s\n", optarg);
                    return 1;
                }
                break;
            // save - plik do wypisywania  
            case 's' :
                filename = optarg;
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
            case 'd':
                direction = atoi(optarg);
                break;
            case '?':
                //fprintf(stderr, "Nieznana flaga -%s\n", optarg);
                return 1;
            default : 

        }
    }

    if (size_x <= 0){
        fprintf(stderr,"Nieprawidłowa szerokość planszy\n");
        return 1;
    }
    if (size_y <= 0){
        fprintf(stderr,"Nieprawidłowa wysokość planszy\n");
        return 1;
    }

    if (percentage > 100 || percentage < 0){
        fprintf(stderr,"Nieprawidłowy procent!\n");
        return 1;
    }
    if (direction > 3 || direction < 0){
        fprintf(stderr,"Nieprawidłowy kierunek!\n");
        return 1;
    }

    simulation simulation;
    if (in != NULL)
        simulation = generate_from_file ( in) ;
    else{
        simulation = generate_grid(size_x, size_y, (double)percentage/100);
        simulation->direction = direction;
        simulation->current_pos.x = (size_x/2);
        simulation->current_pos.y = (size_y/2);
    }
    
    ant_loop (simulation, i, filename);
    

    return 0;
}