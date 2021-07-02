CC = gcc
PL = perl
CFLAGS += -Wall -Wextra -g3 #-Werror
CFLAGS_MEM = ${CFLAGS} -fsanitize=address
NAME = my_bsq
OBJECT_FILES = my_bsq.o map_rep.o my_c_functions.o my_readline.o transform_map.o show_bsq.o
TEST = read_map
TEST_OBJECT_FILES = map_rep.o my_c_functions.o my_readline.o 
MAP_GENERATOR = map_generator.pl
MAP_DESTINATION = map.txt
AGRV0 = 10
ARGV1 = 3
ARGV2 = 2

all: my_bsq

${NAME}: ${OBJECT_FILES}
	${CC} -o $@ $^ ${CFLAGS}

test: ${TEST_OBJECT_FILES}
	${CC} -o ${TEST} $^ ${CFLAGS}

%.o: %.c %.h
	${CC} ${CFLAGS} -c $< 

clean:
	rm -f *.o core.* 

map:
	 ${PL} ${MAP_GENERATOR} ${AGRV0} ${ARGV1} ${ARGV2} > ${MAP_DESTINATION}

re: clean ${NAME}