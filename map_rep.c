#include "map_rep.h"
bitmap* map_rep(int fd)
{    
    bitmap* return_val = malloc(sizeof(bitmap));

    int i = 0;
    char* str_rows = my_readline(fd);
    char* line;
    return_val->row_count = my_atoi_base(str_rows, DEC);
    free(str_rows);
    return_val->char_map = malloc(sizeof(char*) * return_val->row_count);
    while(i <= return_val->row_count)
    {
        line = my_readline(fd);
        
        if (line != NULL)
        {
            printf("[debug]line is good, i = %d\n", i);
            return_val->char_map[i] = my_strdup(line);
            free(line);
            i += 1;
        }
        else
        {
            break;
        }
    }
    return_val->col_count = my_strlen(return_val->char_map[i - 1]);
    return return_val;
}
