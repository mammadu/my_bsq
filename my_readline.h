#ifndef my_readline_H
#define my_readline_H

# include <unistd.h>
# include <stdlib.h>
# define READLINE_READ_SIZE 512

typedef struct s_list {
    void *data;
    size_t dataSize;
    struct s_list *next;
} t_list;

void my_memset(void *data, int c, size_t size);

void my_memcpy(void *dst, const void *src, size_t dataSize);

int my_strchr(char*str, char a, size_t size); 

size_t my_strlen_size(const char *str); 

char *my_strnadd(char *dst, char *src, size_t len);

int countSize(t_list *lst); 

void create_left(char *temp, size_t size, int index, char *left);

char *str_from_left(char *str, int index);

char *my_readline(int fd); 

#endif