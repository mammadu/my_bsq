# my_bsq

## Problem statement:
You must find the largest possible square on a board while avoiding obstacles. The board is represented by a file passed as the program’s argument, respecting those constraints:
• Its first line contains the number of lines on the board (and only that),
• . (representing an empty place) and "o" (representing an obstacle) are the only two allowed characters for the other lines
• All of the lines will be the same length (except the first one)
• There will always be at least one line
• Each line is terminated by \n.

You program must print the board, with some "." replaced by "x" to represent the largest square you found.

## How to run

To make the map, in the terminal type *make map*. The map dimensions can be modified in the makefile - they are:
- AGRV0 = column count
- ARGV1 = row count
- ARGV2 = density of obstacles

To compile the program, in the terminal type *make*

To run the program, in the terminal type *my_bsq map.txt*

## Credits
Thanks to Anastasia Z. for her my_readline.c leak free implementation, please check it out:

[Anastasia Zimina github](https://github.com/anastaszi/QWASAR_Projects/blob/master/my_readline/my_readline.c)

