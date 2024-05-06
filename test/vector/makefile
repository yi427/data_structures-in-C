CC = gcc
VALFLAGS = --tool=memcheck --leak-check=full
CFLAGS = -Wall -ggdb -Wextra -std=c11
HEADER = ../../include/povector.h
SOURCE = ../../src/povector.c
INCLUDES = -I ../../include

vector.o: main.c
	${CC} ${CFLAGS} ${INCLUDES} -o vector.o -c main.c

povector.o: ${HEADER} ${SOURCE}
	${CC} ${CFLAGS} ${INCLUDES} -c ${SOURCE}

vector: vector.o povector.o
	${CC} ${CFLAGS} ${INCLUDES} -o vector vector.o povector.o

check: vector
	valgrind ${VALFLAGS} ./vector

clean:
	rm *.o
	rm vector
