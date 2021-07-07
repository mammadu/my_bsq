#ifndef my_readline_H
#define my_readline_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_c_functions.h"
#include <errno.h>

#define READLINE_READ_SIZE 16

char *my_readline(int fd);

void split_string(char* destination_string, char** source_string, char delimiter);

int is_newline_in_string(char* string);

#endif