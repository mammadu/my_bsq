#include "my_c_functions.h"
#include "my_readline.h"

typedef struct int_map
{
    int x_horiz;
    int y_vert;
    int** map;
}int_map;

// int_map* read_map(int fd)
// {
//     char* my_readline(int fd);
//     return int_map;
// }

char** char_map(int fd)
{
    //First readline to get row count
    //convert row_count to an integer
    //second readline to get column count
    //strlen to get integer value of column count
    //
    char* str_row_count = my_readline(fd);
    int row_count = my_atoi_base(str_row_count, 10);
    printf("[debug] row count = %d\n", row_count);
    char* first_line = my_readline(fd);
    char** return_val = malloc(sizeof(char*) * row_count);
    return return_val;
}

char* my_readline(int fd);

int main(int argc, char* argv[])
{
    int fd = open(argv[1], O_RDONLY);
    char** test = char_map(fd);
}