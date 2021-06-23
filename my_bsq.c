#include "my_bsq.h"

int main(int argc, char* argv[])
{   
    if (argc < 2 && argc > 3)
        return -1;
    else
    {
        int fd = open(argv[1], O_RDONLY); //open file to get fd
        bitmap* map = map_rep(fd);//read/extract txt file into 2d character array
        
        //transform 2d character array into to bitmap
        //find biggest square from bitmap
        //change 2d character array to show the largest square
        //print out final bitmap
    }

    return 0;
}