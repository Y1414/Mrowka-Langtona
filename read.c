
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

#include "mrufka.h"

simulation generate_from_file (FILE* in, int width, int height) {
    setlocale(LC_ALL, "C.UTF-8");
    
    char* tempfile = "tmp/temp";

    wint_t ant_obejct[][4] = {{L'▲', L'▶', L'▼', L'◀'},{L'△', L'▷', L'▽', L'◁'}};
    FILE* newFile= fopen(tempfile, "w");
    if (newFile == NULL) {
        fprintf(stderr,"Błąd tworzenia pliku\n");
        exit(1);
    }
    wint_t character;
    int direction, rows = 0, columns = 0;

    int walls = 0;
    while ((character = fgetwc(in)) != WEOF) {
        if (character == L' ') {
            columns ++;
            fwprintf(newFile, L"0");
            
        } else if (character == L'█') {
            columns ++;
            fwprintf(newFile, L"1");
        } else if (character == L'│'){
            walls += 1;
            if (walls == 2){
                if (columns != width && width){
                    fprintf(stderr,"Nieprawidłowa szerokość!\n");
                    fclose(newFile);
                    remove(tempfile);
                    fclose(in);
                    exit(1);
                }
                
                columns = 0;
                rows ++;
                fwprintf(newFile, L"\n");
                walls = 0;
            }
        }else{
            for (int i =0;i<2;i++){
                for (int j=0;j<4;j++){
                    if (character == ant_obejct[i][j]){
                        columns ++;
                        direction = j;
                        if (i==0)
                            fwprintf(newFile, L"B");
                        else
                            fwprintf(newFile, L"W");
                    }
                }
            }
            fwprintf(newFile, L'\0');
        }
    }

    if (rows != height){
        fprintf(stderr,"Nieprawidłowa wysokość!\n");
        fclose(newFile);
        remove(tempfile);
        fclose(in);
        exit(1);
    }
    


    rewind(newFile);
    fclose(newFile);
    fclose(in);

    simulation new_simulation = malloc(sizeof(simulation));
    
    new_simulation->grid = malloc(height * sizeof(int*));
    newFile = fopen(tempfile, "r");
    
    if (newFile == NULL) {
        fprintf(stderr,"Błąd otwierania pliku\n");
        remove(tempfile);
        exit(1);
    }
    new_simulation->size.y = height;
    new_simulation->size.x = width;
    new_simulation->direction = direction;

    char line[width+2];

    for (int i=0;i<height;i++){
        new_simulation->grid[i] = malloc(width * sizeof(int));
        if (fgets(line, sizeof(line), newFile) != NULL)
            for(int j=0;j<width;j++){
                if (line[j] == '1')
                    new_simulation->grid[i][j] = 1;
                else if (line[j] == 'B' || line[j] == 'W'){
                    new_simulation->grid[i][j] = (line[j] == 'W') ? 1 : 0;
                    new_simulation->current_pos.x = j;
                    new_simulation->current_pos.y = i;
                }
                else
                    new_simulation->grid[i][j] = 0;
            }
    }
    fclose(newFile);
    remove(tempfile);
    return new_simulation;
}

