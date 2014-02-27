#include <stdio.h>
#include "calc.h"
#define MAXBUFF 100
char buff[MAXBUFF];
int buffindex;


int getch(void)
{
	int c;
	if (buffindex > 0)
	{
		c = buff[--buffindex];
		printf("[buffer(%d)]: %c\n",buffindex,c);
	}
	else
	{
		c = getchar();
		printf("[input]: %c\n",c);
	}
	return c;
}

void ungetch(int c)
{
	printf("\tbuffer saving: %c\n",c);
	// save to buffer
	if (buffindex > MAXBUFF) 
		printf("error: BUFFER IS LIMITED");
	else
		buff[buffindex++] = c;
}

