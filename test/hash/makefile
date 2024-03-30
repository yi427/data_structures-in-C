CC = gcc
VALFLAGS = --tool=memcheck --leak-check=full
CFLAGS = -Wall -Wextra -std=c11
ROOT = ../..
INCLUDES = -I ${ROOT}/include

hash: hash.o poschash.o
	${CC} ${CFLAGS} ${INCLUDES} -o hash hash.o poschash.o

hash.o: hash.c
	${CC} ${CFLAGS} ${INCLUDES} -c hash.c ${ROOT}/src/poschash.c

poschash.o: ${ROOT}/src/poschash.c ${ROOT}/include/poschash.h
	${CC} ${CFLAGS} ${INCLUDES} -c ${ROOT}/src/poschash.c

check: hash 
	valgrind ${VALFLAGS} ./hash

clean:
	rm *.o hash
