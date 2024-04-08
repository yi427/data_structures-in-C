CC = gcc
VALFLAGS = --tool=memcheck --leak-check=full
CFLAGS = -Wall -Wextra -std=c11
ROOT = ../..
INCLUDES = -I../../include

list: list.o polist.o
	${CC} ${CFLAGS} -o list list.o polist.o

list.o: list.c
	${CC} ${CFLAGS} ${INCLUDES} -c list.c

polist.o: ${ROOT}/src/polist.c ${ROOT}/include/polist.h
	${CC} ${CFLAGS} ${INCLUDES} -c ${ROOT}/src/polist.c	

check: list
	valgrind ${VALFLAGS} ./list

test: test.cpp
	g++ -I.. -c ../tester.cpp 
	g++ -c ${INCLUDES} ${ROOT}/src/polist.c 
	g++ -c ${INCLUDES} test.cpp
	g++ -o test test.o tester.o polist.o
	valgrind ${VALFLAGS} ./test
	rm -r test *.o

run: list
	./list

clean:
	rm -r list *.o
