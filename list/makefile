CC = gcc
VALFLAGS = --tool=memcheck --leak-check=full
CFLAGS = -Wall -Wextra -std=c11
INCLUDES = -I../include

list: list.o polist.o
	${CC} ${CFLAGS} -o list list.o polist.o

list.o: list.c
	${CC} ${CFLAGS} ${INCLUDES} -c list.c

polist.o: ../src/polist.c ../include/polist.h
	${CC} ${CFLAGS} ${INCLUDES} -c ../src/polist.c	

check: list
	valgrind ${VALFLAGS} ./list

run: list
	./list

clean:
	rm -r list *.o
