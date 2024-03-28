CC = gcc
VALFLAGS = --tool=memcheck --leak-check=full
CFLAGS = -Wall -Wextra -std=c11
INCLUDES = -I../include

hash: hash.o poschash.o
	${CC} ${CFLAGS} ${INCLUDES} -o hash hash.o poschash.o

hash.o: hash.c
	${CC} ${CFLAGS} ${INCLUDES} -c hash.c ../src/poschash.c

poschash.o: ../src/poschash.c ../include/poschash.h
	${CC} ${CFLAGS} ${INCLUDES} -c ../src/poschash.c

check: hash 
	valgrind ${VALFLAGS} ./hash

clean:
	rm *.o hash
