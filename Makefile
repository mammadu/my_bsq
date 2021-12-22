CC = gcc
PL = perl
CFLAGS += -Wall -Wextra -g3 -Werror
CFLAGS_MEM = ${CFLAGS} -fsanitize=address

FILES = my_bsq map_rep my_c_functions my_readline transform_map show_bsq free_map
OBJECT_LOC = obj
OBJECT_FILES = $(patsubst %, ${OBJECT_LOC}/%.o, ${FILES})
SOURCE_LOC = src
SOURCE_FILES = $(patsubst %, ${SOURCE_LOC}/%.c, ${FILES})
HEADER_LOC = include
HEADER_FILES = $(patsubst %, ${HEADER_LOC}/%.h, ${FILES})

MAP_GENERATOR = map_generator.pl
MAP_DESTINATION = map.txt
AGRV0 = 10
ARGV1 = 10
ARGV2 = 3

NAME = my_bsq

all: ${NAME}

${NAME}: ${OBJECT_FILES}
	${CC} -o $@ $^ ${CFLAGS_MEM}

${OBJECT_LOC}/%.o: ${SOURCE_LOC}/%.c ${HEADER_LOC}/%.h
	${CC} -I ${HEADER_LOC} -c $< -o $@

clean:
	rm -rf ${OBJECT_LOC}/*.o core.* ${NAME}

map:
	 ${PL} ${MAP_GENERATOR} ${AGRV0} ${ARGV1} ${ARGV2} > ${MAP_DESTINATION}

re: clean ${NAME}