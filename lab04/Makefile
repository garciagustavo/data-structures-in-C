CC=gcc
GFLAGS=-ansi -Wall -pedantic-errors -g -lm -Werror

all: lab04

lab04: lab04.c fila.o
	$(CC) lab04.c fila.o -o lab04 $(GFLAGS)

fila.o: fila.c fila.h
	$(CC) fila.c -c $(GFLAGS)
clean:
	rm -f *.o
