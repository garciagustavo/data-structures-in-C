CC=gcc
GFLAGS=-ansi -Wall -pedantic-errors -Werror -g -lm

all: lab06

lab06: lab06.c fila_prioridade.o
	$(CC) lab06.c fila_prioridade.o -o main $(GFLAGS)
fila_prioridade.o: fila_prioridade.h
	$(CC) fila_prioridade.c -c $(GFLAGS)
clean:
	rm -f *.o