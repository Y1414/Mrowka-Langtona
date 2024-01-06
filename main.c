#include <stdio.h>
#include <stdlib.h>

#include "mrufka.h"

int main(){
    
    simulation simulation = generate_grid(21, 5);
    
    
    
    print_grid(simulation);
    printf("X");

    return 0;
}