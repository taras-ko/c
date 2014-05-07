#include "tail.h"

#define ALLOCSIZE MAX_TAIL_LINES * MAXLEN

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n) { /* we have space */
		allocp += n;
		return allocp - n;
	}
		else /* no space */
			return 0;
}

void afree(char *p)
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
