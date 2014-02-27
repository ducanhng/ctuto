#include <stdio.h>
#include <ctype.h>
#include "calc.h"

// Version 2: use pointer
// getopt check whether digit or operation
// 1. get input from user
// 2. if it's a digit then push to stack
// 3. if it's an operation, pop operand from stack and do operation
// 4. if it's EOF, exit.
int getopt(char *s, char *p)
{
	int c;
	//*s = c = *p;
	printf("p point to value %c\n",*p);	
	// assume not digit but it's operation

	// case -2 -
	if ((*s++ = c = *p++) == '-')
	{
		//check if next input is digit, save as negative number in array
		if (isdigit(*p))
		{
			 *s++ = *p++;
			//continue insert to string
			while (isdigit(*s++ = *p++));
			if (!isdigit(*p) && *p != '\0')
			{
				printf("Invalid argument: %c\n",*p);
				// Still error here in case 3+.
				return *p;	
			}
			*(++s)  = '\0';
			return NUMBER;
		}
		else
		{
			return c;
		}		
	}
	
	if (!isdigit(c) && c != '.' && c != '-')
	{
		return c;
	}

	// assume c is 1,2,3...
	if (isdigit(c))
	{
		while (isdigit(*++s = c = *++p));
	}

	if (c == '.') 
	{
		while (isdigit(*++s = c = *++p));
	}

	*s = '\0';
	return NUMBER;
}
