entab : entab.o
		cc -o entab entab.o 
entab.o: entab.c 
		cc -c entab.c -g
clean :
	find -name *.o -o -type f -executable | xargs rm -f
