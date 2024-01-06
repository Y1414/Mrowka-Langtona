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


simulation generate_grid (int width, int height);
void print_grid(simulation simulation);
coordinates change_coordinates (coordinates coordinates, int direction);