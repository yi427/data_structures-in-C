CC = gcc
VALFLAGS = --tool=memcheck --leak-check=full
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

list: main.o list.o
	${CC} ${CFLAGS} -o list main.o list.o

main.o: main.c
	${CC} ${CFLAGS} -c main.c	

list.o: src/polist.c include/polist.h
	${CC} ${CFLAGS} -o list.o -c src/polist.c	

check: list
	valgrind ${VALFLAGS} ./list

run: list
	./list

clean:
	rm -r list main.o list.o
