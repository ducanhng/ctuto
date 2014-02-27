#include <stdio.h>
#include "getch.h"
#define MAXBUFF 100
char buff[MAXBUFF];
int buffindex;

int getch(void)
{
	int c;
	if (buffindex > 0)
		c = buff[--buffindex];
	else
		c = getchar();
	return c;
}

void ungetch(int c)
{
	// save to buffer
	if (buffindex > MAXBUFF) 
		printf("buffer error: BUFFER IS LIMITED\n");
	else
		buff[buffindex++] = c;
}

