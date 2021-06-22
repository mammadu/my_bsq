CC = gcc
PL = perl
CFLAGS += -Wall -Wextra -g3 #-Werror
CFLAGS_MEM = ${CFLAGS} -fsanitize=address
NAME = my_bsq
TEST = read_map
TESTFILES = read_map.o my_c_functions.o my_readline.o
MAP_GENERATOR = map_generator.pl
MAP_DESTINATION = map.txt
AGRV0 = 10
ARGV1 = 10
ARGV2 = 3

all: my_bsq

${NAME}: my_bsq.o my_c_functions.o
	${CC} -o $@ $^ ${CFLAGS}

test: ${TESTFILES}
	${CC} -o ${TEST} $^ ${CFLAGS}

%.o: %.c %.h
	${CC} ${CFLAGS} -c $< 

clean:
	rm -f *.o core.* 

map:
	 ${PL} ${MAP_GENERATOR} ${AGRV0} ${ARGV1} ${ARGV2} > ${MAP_DESTINATION}

re: clean ${NAME}