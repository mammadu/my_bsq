#include "my_bsq.h"

#define BSQ_TLC_COL 0
#define BSQ_TLC_ROW 1
#define BSQ_TLC_SIZE 2

void map_reader(bitmap* map)
{
    int i = 0; 
    int j = 0;
    
    while (i < map->row_count)
    {
        while (j < map->col_count)
        {
            printf("%3d ",map->map[i][j]);
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

    // printf("tlc_coord = [%d][%d]\ntrc_coord = [%d][%d]\nblc_coord = [%d][%d]\nbrc_coord = [%d][%d]\n", tlc_row, tlc_col, tlc_row, tlc_col + size, tlc_row + size, tlc_col, tlc_row + size, tlc_col + size);

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

    while (!(x + size > map->col_count && y + size > map->row_count)) //x+size and y+sizze are going out of bounds, why?
    {
        printf("x + size = %d\ny + size = %d\n",x + size, y + size);
        printf("is_valid_square(map, %d, %d, %d) = %d\n", x, y, size, is_valid_square(map->map, x, y, size));
        if (is_valid_square(map->map, x, y, size) == 0)
        {
            map->bsq_coord[BSQ_TLC_COL] = x;
            map->bsq_coord[BSQ_TLC_ROW] = y;
            map->bsq_coord[BSQ_TLC_SIZE] = size;
            size += 1;
        }
        else if (x + size > map->col_count)
        {
            y += 1;
            x = 0;
        }
        else
        {
            x += 1;
        }
    }
}


int main(int argc, char* argv[])
{   
    if (argc < 2 && argc > 3)
        return -1;
    else
    {
        
        int fd = open(argv[1], O_RDONLY); //open file to get fd
        
        bitmap* map = map_rep(fd);//read/extract txt file into 2d character array
        map->map = transform_map(map); //transform 2d character array into to bitmap
        biggest_square(map);//find biggest square from bitmap
        //change 2d character array to show the largest square
        //print out final bitmap

        printf("biggest square coord: x = %d, y = %d, size = %d\n", map->bsq_coord[BSQ_TLC_COL], map->bsq_coord[BSQ_TLC_ROW], map->bsq_coord[BSQ_TLC_SIZE]);
        
         map_reader(map);
    }
   
    return 0;
}