#ifndef transform_map_H
#define transform_map_H

#include "my_c_functions.h"
#include "map_rep.h"

int** zero_filler_map(bitmap* map);
int** horizontal_filler_map(bitmap* map);
int** vertical_filler_map(bitmap* map);
int** transform_map(bitmap* map);
int** obstacle_filler_map(bitmap* map);



#endif