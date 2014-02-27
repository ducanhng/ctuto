#include <stdio.h>
#include <ctype.h>
#include "calc.h"

// Version 2: use pointer
// getopt check whether is digit or operation
// 1. get input from user
// 2. if it's a digit then push to stack
// 3. if it's an operation, pop operand from stack and do operation
// 4. if it's EOF, exit.
int getopt(char *s)
{
	int c,index;
	int BLAH;
	BLAH = 0;
	while ((*s = c = getch()) == ' ' && c == '\t')
		;// Do i must write isdigit function ?
	// assume already have isdigit function.
	// assume not digit but it's operation
	if (c == '-')
	{
		//if next input is digit, save as negative number in array
		if (isdigit(c = getch()))
		{
			 *(++s) = c;
			
			//continue insert to string
			while(isdigit(*(++s) = c = getch()) );
			*(++s)  = '\0';
			return NUMBER;
		}
		else
		{
			return '-';
		}		
	}
	
	if (!isdigit(c) && c != '.' && c != '-')
	{
		return c;
	}

	// assume c is 1,2,3...
	if (isdigit(c))
	{
		while (isdigit(*(++s) = c = getch()));
	}

	if (c == '.') 
	{
		while (isdigit(*(++s) = c = getch()))
			;	
	}

	*s = '\0';
	// Assume not digit but will be unknow command
	if (c != EOF)
	{
		ungetch(c);
	}
	return NUMBER;
	
}
