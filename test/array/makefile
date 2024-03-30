CC = gcc
VALFLAGS = --tool=memcheck --leak-check=full
CFLAGS = -Wall -Wextra -std=c11
ROOT = ../..
INCLUDES = -I ${ROOT}/include

array: array.o poarray.o
	${CC} ${CFLAGS} -o array array.o poarray.o

array.o: array.c
	${CC} ${CFLAGS} ${INCLUDES} -c array.c

poarray.o: ${ROOT}/src/poarray.c ${ROOT}/include/poarray.h
	${CC} ${CFLAGS} ${INCLUDES} -c ${ROOT}/src/poarray.c	

check: array
	valgrind ${VALFLAGS} ./array

run: array
	./array

clean:
	rm -r array *.o
