#include "my_bsq.h"

int is_valid_row(int** map, int x, int y, int size)
{
    int total_x = x + size; 
    int total_y = y + size;
    int buffer_x = x;
    
    while(y < total_y)
    {    
        while(x < total_x)
        {
            if(map[y][x] == -1)
                return - 1;
            
            x += 1;
        }
        x = buffer_x;
        y += 1;
    }    
    return 0;
}

void map_reader(bitmap* map)
{
    int i = 0; 
    int j = 0;

    while (i < map->row_count)
    {
        while (j < map->col_count)
        {
            printf("%c",map->char_map[i][j]);
            j += 1;
        }
        printf("\n");
        j = 0;
        i += 1;
    }
}

int is_valid_square(int** map, int tlc_col, int tlc_row, int size)
{
    size -= 1;
    int tlc = map[tlc_row][tlc_col];
    int trc = map[tlc_row][tlc_col + size];
    int blc = map[tlc_row + size][tlc_col];
    int brc = map[tlc_row + size][tlc_col + size];

    if (tlc == -1 || trc == -1 || blc == -1 || brc == -1)
    {
        return -1;
    }
    else
    {
        return brc - blc - trc + tlc;
    }
}

void biggest_square(bitmap* map)
{
    //start at top left: x = 0, y = 0 size = 2
    int x = 0;
    int y = 0;
    int size = 1;

    while (!(x + size > map->col_count && y + size >= map->row_count))
    {
        if (x + size > map->col_count)
        {
            y += 1;
            x = 0;
        }
        else if (is_valid_square(map->map, x, y, size) == 0 && is_valid_row(map->map, x, y, size) == 0)
        {
            map->bsq_coord[BSQ_TLC_COL] = x;
            map->bsq_coord[BSQ_TLC_ROW] = y;
            map->bsq_coord[BSQ_TLC_SIZE] = size;
            size += 1;
            x = 0;
            y = 0;
        }
        else
            x += 1;
    }
}


int main(int argc, char* argv[])
{   
    if (argc < 2 || argc > 3)
        return -1;
    else
    {
        int fd = open(argv[1], O_RDONLY); //open file to get fd
        
        bitmap* map = map_rep(fd);//read/extract txt file into 2d character array
        map->map = transform_map(map); //transform 2d character array into to bitmap
        biggest_square(map);//find biggest square from bitmap
        map->char_map = coordinates_to_bsq(map);//change 2d character array to show the largest square
        map_reader(map);//print out final bitmap
        free_map(map);//free memory
        close(fd);//close file descriptor
    }
   
    return 0;
}