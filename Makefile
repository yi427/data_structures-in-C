CC = gcc
VALFLAGS = --tool=memcheck --leak-check=full
CFLAGS = -Wall -Wextra -std=c11
INCLUDES = -Iinclude

list: list.o main.o
	${CC} ${CFLAGS} -o list main.o list.o

main.o: main.c
	${CC} ${CFLAGS} -c main.c	src/polist.c

list.o: src/polist.c include/polist.h
	${CC} ${CFLAGS} ${INCLUDES} -o list.o -c src/polist.c	

check: list
	valgrind ${VALFLAGS} ./list

run: list
	./list

clean:
	rm -r list main.o list.o
