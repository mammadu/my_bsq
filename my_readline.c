#include "my_readline.h"

#define READLINE_READ_SIZE 16
#define FILE_DESCRIPTORS_NUM 1024

char* null_filler(int size)
{
    char* str = malloc(sizeof(char) * size + 1);

    for (int i = 0; i < size; i += 1)
        str[i] = '\0';
    return str;
}


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