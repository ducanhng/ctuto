#include <stdio.h>
#define MAXBUFF 100
#include "getch.h"

char buff[MAXBUFF];
int buffindex;


int getch(void)
{
	int c;
	if (buffindex > 0)
	{
		c = buff[--buffindex];
		printf("[buffer(%d)]: %c in number: %d \n",buffindex,c,c);
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
	printf("\tbuffer saving: %c in number:%d \n",c,c);
	// save to buffer
	if (buffindex > MAXBUFF) 
		printf("error: BUFFER IS LIMITED");
	else
		buff[buffindex++] = c;
}

