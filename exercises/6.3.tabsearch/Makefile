CC = g++

sources := $(wildcard src/*.c)
sources := $(filter-out src/tabfun.c, $(sources))
objects := $(sources:.c=.o)

LPATH := ../../libc

CFLAGS := -DDEBUG \
		-std=c++0x \
		-g \
		-Iinclude \
		-I$(LPATH)/include


.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

tabsearch: $(objects)
	$(CC) $(CFLAGS) -o $@ $(objects)

all: tabsearch

clean:
	rm tabsearch $(objects)
