#include "free_map.h"
#include <stdio.h>


void free_coord(int* bsq_coord)
{
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
    free_maps(map);
    free(map);
}