#include "my_bsq.h"

void map_reader(bitmap* map)
{
    int i = 0; 
    int j = 0;
    
    while (i < map->row_count)
    {
        while (j < map->col_count)
        {
            printf("%d",map->map[i][j]);
            j += 1;
        }
        printf("\n");
        j = 0; 
        i += 1;
    }
}

int main(int argc, char* argv[])
{   
    if (argc < 2 && argc > 3)
        return -1;
    else
    {
        
        int fd = open(argv[1], O_RDONLY); //open file to get fd
        
        bitmap* map = map_rep(fd);//read/extract txt file into 2d character array
        //transform 2d character array into to bitmap
        //find biggest square from bitmap
        //change 2d character array to show the largest square
        //print out final bitmap
        
        map->map = horizontal_filler_map(map);
        map_reader(map);
        printf("\nVERTICAL\n\n");
        map->map = vertical_filler_map(map);

        map_reader(map);
    }
   
    return 0;
}