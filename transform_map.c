#include "transform_map.h"
#include "map_rep.h"

int** zero_filler_map(bitmap* map)
{
    int i = 0;
    int j = 0;
    map->map = malloc(sizeof(int*) * map->row_count);
    
    
    while(i <= map->row_count)
    {   
        map->map[i] = malloc(sizeof(int) * map->col_count);
        while (j <= map->col_count)
        {
            map->map[i][j] = 0;
            j += 1;
        }
        j = 0;
        i += 1;
    }
    return map->map;
}

//row manipulation based on obstacles
    // we will add +1 for every obstacle in a given row
        //+1 will accumulate but it will start again at +0 per each row

int** horizontal_filler_map(bitmap* map)
{
    // map->map = zero_filler_map(map);
    int i = 0;
    int j = 0;
    int accum = 0;

    while(i < map->row_count)
    {   
        while (j < map->col_count)
        {
            if(map->char_map[i][j] == 'o')
                accum += 1;
            map->map[i + 1][j + 1] = accum;
            j += 1;
        }
        accum = 0;
        j = 0;
        i += 1;
    }

    return map->map;
}

int** vertical_filler_map(bitmap* map)
{
    // map->map = horizontal_filler_map(map);
    int i = 0;
    int j = 0;
    int accum = 0;

    while(i < map->col_count)
    {   
        while (j < map->row_count)
        {
            if(map->map[j + 1][i + 1] > 0)
                accum += map->map[j + 1][i + 1];
            map->map[j + 1][i + 1] = accum;
            j += 1;
        }
        accum = 0;
        j = 0;
        i += 1;
    }

    return map->map;
}

int** obstacle_filler_map(bitmap* map)
{
    // map->map = zero_filler_map(map);
    int i = 0;
    int j = 0;

    while(i < map->row_count)
    {   
        while (j < map->col_count)
        {
            if(map->char_map[i][j] == 'o')
                map->map[i][j] = -1;
            j += 1;
        }
        j = 0;
        i += 1;
    }

    return map->map;
}

int** transform_map(bitmap* map)
{
    map->map = zero_filler_map(map);
    map->map = horizontal_filler_map(map);
    map->map = vertical_filler_map(map);
    // map->map = obstacle_filler_map(map);
    return map->map;
}

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
