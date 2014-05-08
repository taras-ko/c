sources := $(wildcard src/*.c)
objects := $(sources:.c=.o)

CC = gcc

CFLAGS = -g \
		-Iinclude

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: kwc

kwc: $(objects)
	$(CC) $(CFLAGS) -o kwc $(objects)

clean:
	rm kwc src/*.o
