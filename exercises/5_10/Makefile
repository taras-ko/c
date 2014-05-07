expr : main.o argeval.o stackop.o
		cc -o expr main.o argeval.o stackop.o
main.o: main.c expr.h
		cc -c main.c
argeval.o: argeval.c
		cc -c argeval.c
stackop.o: stackop.c
		cc -c stackop.c
clean :
		rm expr main.o argeval.o stackop.o
