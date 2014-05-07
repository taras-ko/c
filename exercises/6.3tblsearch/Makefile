PROGRAM := tblsearch
SOURCES := src/$(PROGRAM).c src/tblfun.c
OBJS := src/$(PROGRAM).o src/tblfun.o

LPATH := /home/x0170753/src/C/KR/lib

CFLAGS := -DDEBUG \
		  -g \
		  -Iinclude \
		  -I$(LPATH)/include \
		  -I$(LPATH)/libmystdio/include -L$(LPATH)/libmystdio \
		  -I$(LPATH)/libmystlib/include -L$(LPATH)/libmystdlib \
		  -I$(LPATH)/libctypelocal/include -L$(LPATH)/libctypelocal \
		  -I$(LPATH)/libstringlocal/include -L$(LPATH)/libstringlocal

LDFLAGS :=  -lmystdio -lctypelocal -lstringlocal \
		-Wl,-rpath=$(LPATH)/libctypelocal,-rpath=$(LPATH)/libmystdio \
		-Wl,-rpath=$(LPATH)/libstringlocal \
		-lmystdlib -Wl,-rpath=$(LPATH)/libmystdlib,-rpath=$(LPATH)/libmystdlib


all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJS) $(LDFLAGS)

clean:
	rm $(PROGRAM) $(OBJS)
