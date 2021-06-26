#ifndef my_bsq_H
#define my_bsq_H

#include <sys/stat.h>
#include <fcntl.h>
#include "map_rep.h"
#include "transform_map.h"
#include "my_c_functions.h"
#include "show_bsq.h"

void map_reader(bitmap* map);
void biggest_square(bitmap* map);


#endif