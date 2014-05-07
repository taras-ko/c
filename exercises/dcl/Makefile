SOURCES := src/dcl.c src/dclfun.c src/gettoken.c
OBJS := src/dcl.o src/dclfun.o src/gettoken.o

LPATH := /home/x0170753/src/C/KR/lib
# Objs are all the sources, with .cpp replaced by .o
CFLAGS := -g \
		  -Iinclude \
		  -I$(LPATH)/libmystdio/include -L$(LPATH)/libmystdio \
		  -I$(LPATH)/libstringlocal/include -L$(LPATH)/libstringlocal \
		  -I$(LPATH)/libctypelocal/include -L$(LPATH)/libctypelocal

LDFLAGS :=  -lmystdio -lctypelocal -lstringlocal \
			-Wl,-rpath=$(LPATH)/libctypelocal,-rpath=$(LPATH)/libstringlocal,-rpath=$(LPATH)/libmystdio

PROGRAM := dcl

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJS) $(LDFLAGS)

clean:
	rm dcl src/*.o
