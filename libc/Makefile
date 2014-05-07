LIBNAME := lib_c

SOURCES = $(wildcard src/*.c)
OBJS := $(SOURCES:.c=.o)

CFLAGS := -g -fPIC

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -Iinclude

default: $(OBJS)
	$(CC) $(CFLAGS) -o $(LIBNAME).so $(OBJS) -shared

clean:
	rm $(LIBNAME).so src/*.o
