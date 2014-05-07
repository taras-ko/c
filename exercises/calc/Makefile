LIBPATH := /home/x0170753/src/C/KR/lib

CFLAGS := -g \
		  -I$(LIBPATH)/libmystdio/include

LDFLAGS :=  -lm \
			-L$(LIBPATH)/libmystdio -Wl,-rpath=$(LIBPATH)/libmystdio -lmystdio

SOURCES := stack.c getop.c calc.c

OBJECTS := $(SOURCES:.c=.o)

EXECUTABLE := calc


all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
