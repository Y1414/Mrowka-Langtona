typedef struct 
{
    int y;
    int x;
}coordinates;

typedef struct{
    int** grid;
    coordinates size;
    coordinates current_pos;
    int direction;
}*simulation;


simulation generate_grid (int width, int height, double percentage);
void print_grid(simulation simulation, int counter);
coordinates change_coordinates (coordinates coordinates, int direction);
void ant_loop (simulation simulation,int iterations, char*filename);
void print_to_file (simulation simulation, char* filename, int iteration);
int change_to_numeric(FILE* in, FILE* newFile);
simulation generate_from_file (FILE* in, FILE* newFile, int width, int height);