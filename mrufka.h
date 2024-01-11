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
void ant_loop (simulation simulation,int iterations);