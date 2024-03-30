CC = gcc
VALFLAGS = --tool=memcheck --leak-check=full
CFLAGS = -Wall -Wextra -std=c11
INCLUDES = -I../include

array: array.o poarray.o
	${CC} ${CFLAGS} -o array array.o poarray.o

array.o: array.c
	${CC} ${CFLAGS} ${INCLUDES} -c array.c

poarray.o: ../src/poarray.c ../include/poarray.h
	${CC} ${CFLAGS} ${INCLUDES} -c ../src/poarray.c	

check: array
	valgrind ${VALFLAGS} ./array

run: array
	./array

clean:
	rm -r array *.o
