#ifndef map_rep_H
#define map_rep_H

#include "my_c_functions.h"
#include "my_readline.h"

typedef struct bitmap
{
    int row_count;
    int col_count;
    int bsq_coord[3]; //holds biggest square info of the top left corner. Consists of [row, column, size]
    int** map;
    char** char_map;
}bitmap;

bitmap* map_rep(int fd);

#endif