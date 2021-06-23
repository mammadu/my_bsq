#include "map_rep.h"

bitmap* map_rep(int fd)
{    
    bitmap* return_val = malloc(sizeof(bitmap));

    int i = 0;
    char* str_rows = my_readline(fd);
    return_val->row_count = my_atoi_base(str_rows, DEC);
    return_val->char_map = malloc(sizeof(char*) * return_val->row_count);
    while(i < return_val->row_count)
    {
        return_val->char_map[i] = my_strdup(my_readline(fd));
        i += 1;
    }
    return_val->col_count = my_strlen(return_val->char_map[i - 1]);
    return return_val;
}

// int main(int argc, char* argv[])
// {
//     //int file_width = column_size(argv[1]);
//     //printf("file width  = %d \n", file_width);
//     int fd = open(argv[1], O_RDONLY);
//     bitmap* map = map_rep(fd);
//     for (int i = 0; i < map->row_count; i++)
//     {
//         printf("%s\n", map->char_map[i]);
//     }
// }