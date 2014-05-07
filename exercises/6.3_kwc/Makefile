SOURCES := src/kwc.c
OBJS := src/kwc.o

CFLAGS := -g \
		  -Iinclude

PROGRAM := kwc

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJS)

clean:
	rm kwc src/*.o
