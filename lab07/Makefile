SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
CC=gcc
GFLAGS=-ansi -Wall -pedantic-errors -Werror -g -lm

lab07: $(OBJ)
	$(CC) $(GFLAGS) *.o -o main

%.o: %.c
	$(CC) $(GFLAGS) -c $< -o $@

clean:
	rm -f *.o