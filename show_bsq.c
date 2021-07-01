#include "show_bsq.h"

char** coordinates_to_bsq(bitmap* map)
{
    int i = map->bsq_coord[BSQ_TLC_ROW];
    int j = map->bsq_coord[BSQ_TLC_COL];
    int size = 0;
    int size_x = 0;
    while (size_x < map->bsq_coord[BSQ_TLC_SIZE])
    {
        while (size < map->bsq_coord[BSQ_TLC_SIZE])
        {
            map->char_map[i][j] = 'X';
            j += 1;
            size += 1;
        }
        j = map->bsq_coord[BSQ_TLC_COL];
        size = 0;
        size_x += 1;
        i += 1;
    }

    return map->char_map;
}