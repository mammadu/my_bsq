#include "my_bsq.h"

void map_reader(bitmap* map)
{
    int i = 0; 
    int j = 0;
    
    while (i < map->row_count)
    {
        while (j < map->col_count)
        {
            //printf("%d ",map->map[i][j]);
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
    size -= 1; //The starting point of size in foo biggest_sqare and this lines of code do not make sense 
    int tlc = map[tlc_row][tlc_col];
    int trc = map[tlc_row][tlc_col + size];
    int blc = map[tlc_row + size][tlc_col];
    int brc = map[tlc_row + size][tlc_col + size];

    if (tlc == -1 || trc == -1 || blc == -1 || brc == -1) //Would it be a easy as flagging here as well the total size of x and y as a boundary?
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

    while (!(x + size >= map->col_count && y + size >= map->row_count))
    {
        //printf("x + size = %d\ny + size = %d\n",x + size, y + size);
        //printf("is_valid_square(map, %d, %d, %d) = %d\n", x, y, size, is_valid_square(map->map, x, y, size));
        if (x + size > map->col_count)
        {
            y += 1;
            x = 0;
        }
        else if (is_valid_square(map->map, x, y, size) == 0)
        {
            map->bsq_coord[BSQ_TLC_COL] = x;
            map->bsq_coord[BSQ_TLC_ROW] = y;
            map->bsq_coord[BSQ_TLC_SIZE] = size;
            size += 1;
            x = 0;
            y = 0;
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
        map->char_map = coordinates_to_bsq(map);
         map_reader(map);
    }
   
    return 0;
}