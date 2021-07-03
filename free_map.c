#include "free_map.h"
#include <stdio.h>


void free_coord(int* bsq_coord)
{
    // int i = 0;
    // int array_size = 3;

    // while (i < array_size)
    // {
    //     free(bsq_coord[i]);
    //     i += 1;
    // }

    free(bsq_coord);
}

void free_maps(bitmap* map)
{
    int i = 0;

    while(i < map->row_count)
    {
        free(map->map[i]);
        free(map->char_map[i]);
        i += 1;
    }
    free(map->map);
    free(map->char_map);
}

void free_map(bitmap* map)
{
    //free_coord(map->bsq_coord);
    free_maps(map);
    free(map);
}

/*
typedef struct bitmap
{
    int row_count;
    int col_count;
    int bsq_coord[3]; //holds biggest square info of the top left corner. Consists of [row, column, size]
    int** map;
    char** char_map;
}bitmap;
*/