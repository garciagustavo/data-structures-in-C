SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
CC=gcc
GFLAGS=-ansi -Wall -pedantic-errors -Werror -g -lm

all: lab09

lab09: $(OBJ)
	$(CC) $(GFLAGS) *.o -o lab09

%.o: %.c
	$(CC) $(GFLAGS) -c $< -o $@

clean:
	rm -f *.o
