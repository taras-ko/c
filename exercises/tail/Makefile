SOURCES := tail.c _getline.c allocator.c
# Objs are all the sources, with .cpp replaced by .o
OBJS := $(SOURCES:.cpp=.o)
CFLAGS := -g

all: tail

# Compile the binary 't' by calling the compiler with cflags, lflags, and any libs (if defined) and the list of objects.
tail: $(OBJS)
	$(CC) $(CFLAGS) -o tail $(OBJS) $(LFLAGS) $(LIBS)

# Get a .o from a .cpp by calling compiler with cflags and includes (if defined)
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<
