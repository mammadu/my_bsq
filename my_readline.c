#include "my_readline.h"
#include <errno.h>

#define READLINE_READ_SIZE 16

int is_newline_in_string(char* string)
{
    int i = 0;
    while (string[i] != '\0')
    {
        if (string[i] == '\n')
        {
            return 1;
        }
        i++;
    }
    return 0;
}

//Copy contents of source_string into destination_string upto delimiter character.
void split_string(char* destination_string, char** source_string, char delimiter)
{
    int i = 0;
    while(source_string[0][i] != delimiter && i < my_strlen(source_string[0]))
    {
        destination_string[i] = source_string[0][i];
        i++;
    } 
    destination_string[i] = '\0';
    source_string[0] = &source_string[0][i + 1];
}

char *my_readline(int fd) 
{
    static char* string_storage_block = "\0";    
    
    char* return_val;
    
    int characters_read;
    
    if (string_storage_block[0] != '\0' && is_newline_in_string(string_storage_block) == 1)
    {        
        return_val = malloc(my_strlen(string_storage_block) * sizeof(char));
        split_string(return_val, &string_storage_block, '\n');
        return return_val;
    }

    char* temp_string_storage_block = malloc(READLINE_READ_SIZE * sizeof(char));
    characters_read = read(fd, temp_string_storage_block, READLINE_READ_SIZE);
    
    if (errno == EBADF)
    {
        free(temp_string_storage_block);
        return NULL;
    }
    
    if (characters_read == 0 && string_storage_block[0] == '\0')
    {
        free(temp_string_storage_block);
        return NULL;
    }
    
    char* temp_combined_string = combine_strings(string_storage_block, temp_string_storage_block);
    string_storage_block = temp_combined_string;
    free(temp_string_storage_block);
    
    while (is_newline_in_string(string_storage_block) == 0 && characters_read > 0)
    {
        temp_string_storage_block = malloc(READLINE_READ_SIZE * sizeof(char));    
        characters_read = read(fd, temp_string_storage_block, READLINE_READ_SIZE);
        string_storage_block = combine_strings(string_storage_block, temp_string_storage_block);
        free(temp_string_storage_block);
    }
    
    return_val = malloc(my_strlen(string_storage_block) * sizeof(char));
    split_string(return_val, &string_storage_block, '\n');
    
    return return_val;
}