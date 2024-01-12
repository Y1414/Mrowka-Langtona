#include <stdio.h>
#include <stdlib.h>

#include "mrufka.h"

int main() {
    FILE *originalFile; 
    FILE* newFile = tmpfile();

    // Open the original file for reading
    originalFile = fopen("save/neiweim_4", "r");
    if (originalFile == NULL) {
        perror("Error opening the original file");
        return EXIT_FAILURE;
    }

    // Open a new file for writing
    

    // Replace spaces with zeros and write to the new file


    // Close the files

    
    simulation simulation = generate_from_file (originalFile, newFile, 11, 11);


    print_grid(simulation, 1);
    remove("temp");

    return EXIT_SUCCESS;
}