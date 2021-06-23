#include "transform_map.h"
#include "map_rep.h"

//zero filler function
    //goal is to fill all the rows with zeroes

//row manipulation based on obstacles
    // we will add +1 for every obstacle in a given row
        //+1 will accumulate but it will start again at +0 per each row

//Column manipulation
    //same operation as in row manipulation but with colums 
        //chanllenge is that 

/*
............  000000000000
.......x....  000000011111
............  000000011111
....x...x...  000011123333
......x.....  000011234444
............  000011234444


............  000000000000 
.......x....  000000011111 accum += 1
............  000000000000 column[n] = accum 
....x...x...  000011122222 accum += 2
......x.....  000000111111
............  000000000000

............  000000000000 accum = 0
.......x....  000000011111 accum += column[n]; column[n] = accum 
............  000000000001 if collumn[n] > 0 : accum += collumn[n] ... collumn[n] = accum, collumn[n] = accum. 
....x...x...  000011122223
......x.....  000000111114
............  000000000004

*/
