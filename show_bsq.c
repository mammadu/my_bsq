#include "show_bsq.h"

char** coordinates_to_bsq(bitmap* map)
{
    int i = map->bsq_coord[BSQ_TLC_ROW];
    int j = map->bsq_coord[BSQ_TLC_COL];

    while (i < (map->bsq_coord[BSQ_TLC_ROW] + map->bsq_coord[BSQ_TLC_SIZE] ))
    {
        printf("i = %d", i);
        while (j < (map->bsq_coord[BSQ_TLC_ROW] + map->bsq_coord[BSQ_TLC_SIZE] ))
        {
            map->char_map[i][j] = 'X';
            j += 1;
        }
        j = map->bsq_coord[BSQ_TLC_COL];
        i += 1;
    }

    return map->char_map;
}