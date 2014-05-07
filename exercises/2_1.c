#include <stdio.h>
#include <limits.h>

main()
{
	unsigned long ul, ul2; 
	ul = (unsigned long) LONG_MAX;

    ul2 = (unsigned long) LONG_MIN;
	printf("%lu %lu\n", ul, ul2); 
	printf("%ld %ld\n", (long)ul, (long)ul2);
//	printf("%ld",ULONG_MAX ); 

	return 0;
}
