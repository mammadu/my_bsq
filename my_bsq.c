#include "my_bsq.h"

int open_map(char* file_name)
{
    int fd = open(file_name);
    return fd;
}


int main(int argc, char* argv[])
{   
    if (argc < 2 && argc > 3)
        return -1;
    else
    {
        fd_map = open_map(file_name);
        // int_map int_mapped = read_map(fd_map);
    }

    return 0;
}