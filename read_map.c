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
//

//map_rep will return the array of characters as it is 

// int column_size(char* filename)
// {
//     int fd = open(filename, O_RDONLY);
//     my_readline(fd);
//     int width = my_strlen(my_readline(fd));
//     close(fd);
//     return width;

// }


char** map_rep(int fd, int rows){
    
    int i = 0;
    char** character_map = malloc(sizeof(char*) * rows);
    printf("%d ", rows);
    while(i < rows)
    {
        character_map[i] = my_strdup(my_readline(fd));
        i+= 1;
    }
    return character_map;
}


char** char_map(int fd)
{
    //First readline to get row count
    //convert row_count to an integer
    //second readline to get column count
    //strlen to get integer value of column count
    //
    char* str_row_count = my_readline(fd);
    int row_count = my_atoi_base(str_row_count, 10);
    
    char** marimapa = map_rep(fd, row_count);
    
    
    char** return_val = malloc(sizeof(char*) * row_count);
    return return_val;
}

//char* my_readline(int fd);

int main(int argc, char* argv[])
{
    //int file_width = column_size(argv[1]);
//    printf("file width  = %d \n", file_width);
    int fd = open(argv[1], O_RDONLY);
    char** test = char_map(fd);
}