#include <stdio.h>

main()
{
	enum status { NO, YES };
	const int lim = 10;
	char s[lim], c;
	signed char toExit = NO;		
	
	int i = 0;
	do
		if (i > lim - 1) 
			toExit = YES; 
		else if ( (c = getchar()) == '\n' )
				toExit = YES;
		else if ( c == EOF) 
				toExit = YES;
		else
			s[i++] = c;
	while ( !toExit ); 

	printf("%s\n", s);
}
