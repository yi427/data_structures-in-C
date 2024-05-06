CC = gcc
CFLAGS = -Wall -Wextra -std=c11
INCLUDES = -Iinclude
FILES = src/poarray.c src/polist.c src/poschash.c src/podisplay.c src/potree.c

generate:
	${CC} ${CFLAGS} ${INCLUDES} -c ${FILES}

clean:
	rm *.o
