SOURCES := qsort.c sort.c cmp.c

LPATH := /home/x0170753/src/C/KR/lib
# Objs are all the sources, with .cpp replaced by .o
CFLAGS := -g \
		  -I$(LPATH)/libctypelocal/include -L$(LPATH)/libctypelocal \
		  -I$(LPATH)/librwlines/include -L$(LPATH)/librwlines \
		  -I$(LPATH)/libstringlocal/include -L$(LPATH)/libstringlocal

LDFLAGS := -lrwlines -lstringlocal -lctypelocal -Wl,-rpath=$(LPATH)/librwlines,-rpath=$(LPATH)/libstringlocal,-rpath=$(LPATH)/libctypelocal

OBJS := $(SOURCES:.c=.o)
PROGRAM := sort

all: $(PROGRAM)

# Compile the binary 't' by calling the compiler with cflags, lflags, and any libs (if defined) and the list of objects.
$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJS) $(LDFLAGS)

# Get a .o from a .cpp by calling compiler with cflags and includes (if defined)
.c.o:
	$(CC) $(CFLAGS) -c $<
