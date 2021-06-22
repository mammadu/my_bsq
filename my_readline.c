// #include <unistd.h>
// #include <stdlib.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// #include <stdio.h>
// #include "my_c_functions.h"

#include "my_readline.h"

#define READLINE_READ_SIZE 16
#define FILE_DESCRIPTORS_NUM 1024

// int my_strlen(char* string)
// {
//     int i = 0;
//     while(string[i] != '\0')
//         i++;
//     return i;
// }

// char* my_strdup(char* param_1)
// {
//     char* str_copy;
 
//     int length = my_strlen(param_1);
//     str_copy = malloc((length + 1) * sizeof(char));
//     int i = 0;
//     while (i < length)
//     {
//         str_copy[i] = param_1[i];
//         i++;
//     }
//     str_copy[i] = '\0';
//     return str_copy;
// }

char* null_filler(int size)
{
    char* str = malloc(sizeof(char) * size + 1);

    for (int i = 0; i < size; i += 1)
        str[i] = '\0';
    return str;
}

// char* combine_strings(char* s1, char* s2)
// {
//     char* combined;
//     char* tmp;
//     int i = 0;
//     int j = 0;

//     if (!s1 || !s2)
//         return (NULL);
//     while (s1[i])
//         i += 1;
//     while (s2[j])
//         j += 1;
//     combined = null_filler(i + j);
//     tmp = combined;
//     while (*s1 != '\0')
//         *tmp++ = *s1++;
//     while (*s2 != '\0')
//         *tmp++ = *s2++;
//     *tmp = '\0';
//     return (combined);
// }

int read_remainder(char** remainder, char** line)
{
    char* tmp;
    char* remainder_pos;
    int i;

    i = 0;
    remainder_pos = *remainder;
    while (remainder_pos[i] != '\n')
        if (!remainder_pos[i++])
            return (0);
    tmp = &remainder_pos[i];
    *tmp = '\0';
    *line = my_strdup(*remainder);
    *remainder = my_strdup(tmp + 1);
    return (1);
}

int read_file(int fd, char** remainder, char** line)
{
    int read_bytes;
    char* tmp;
    char* buffer = null_filler(READLINE_READ_SIZE);

    while ((read_bytes = read(fd, buffer, READLINE_READ_SIZE)) > 0)
    {
        buffer[read_bytes] = '\0';
        if (*remainder)
        {
            tmp = *remainder;
            *remainder = combine_strings(tmp, buffer);
            free(tmp);
            tmp = NULL;
        }
        else
            *remainder = my_strdup(buffer);
        if (read_remainder(remainder, line))
            break;
    }
    free(buffer);
    return (read_bytes);
}

char* my_readline(int fd)
{
    static char* remainder[FILE_DESCRIPTORS_NUM];
    char* line = NULL;
    int read_bytes;

    if (fd < 0 || fd >= FILE_DESCRIPTORS_NUM || (read(fd, remainder[fd], 0) < 0))
        return NULL;
    if (remainder[fd] && read_remainder(&remainder[fd], &line))
        return line;
    read_bytes = read_file(fd, &remainder[fd], &line);
    if (read_bytes != 0 || remainder[fd] == NULL || remainder[fd][0] == '\0')
    {
        if (read_bytes == 0 && line)
            return NULL;
        return line;
    }
    line = remainder[fd];
    remainder[fd] = NULL;
    return line;
}
