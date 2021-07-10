#ifndef map_rep_H
#define map_rep_H

#include "my_c_functions.h"
#include "my_readline.h"

#define BSQ_TLC_COL 0
#define BSQ_TLC_ROW 1
#define BSQ_TLC_SIZE 2

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