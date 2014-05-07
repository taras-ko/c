CFLAGS = -g
SOURCES := calc.c stack.c
OBJECTS := $(SOURCES:.c=.o)
PROGRAM := calc

all: $(SOURCES) $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
