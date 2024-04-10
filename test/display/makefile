CC = gcc
CFLAGS = -std=c11
INCLUDES = -I../../include

list.o: ../../src/polist.c
	${CC} -ggdb ${INCLUDES} ${CFLAGS} -o list.o -c ../../src/polist.c

display.o: ../../src/podisplay.c
	${CC} -ggdb ${INCLUDES} ${CFLAGS} -o display.o -c ../../src/podisplay.c

result.o: display.c
	${CC} -ggdb ${INCLUDES} ${CFLAGS} -o result.o -c display.c

display: list.o display.o result.o
	${CC} -ggdb ${CFLAGS} -o display list.o display.o result.o

clean:
	rm -f *.o
	rm -rf ./DotFiles/
	rm -f display
