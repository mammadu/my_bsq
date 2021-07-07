#ifndef my_readline_H
#define my_readline_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "my_c_functions.h"

char* my_readline(int fd);

#endif