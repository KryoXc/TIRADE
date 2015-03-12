CC=gcc
CFLAGS=-g -Wall -lncurses 

SOURCES=$(wildcard src/*.c)

game:
	$(CC) -o client $(SOURCES) $(CFLAGS) 

.PHONY: clean

clean:
	rm client
