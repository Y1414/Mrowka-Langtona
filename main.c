#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mrufka.h"



int main(){
    
    simulation simulation = generate_grid(2, 2);
    
    simulation->current_pos.x = 1;
    simulation->current_pos.y = 1;
    simulation->direction = 0;

    ant_loop (simulation);
    return 0;
}