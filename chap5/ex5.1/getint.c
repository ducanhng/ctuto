/*
	author:ducanhng
	date created: 30/5/2011
	description: get integer from input, 
	return EOF if end of file, zero if is not a number, positive number if is a number
	note: there is a case that the function don't work correctly.
	 exp: input 23 334s 33443, the third number is not recorgnize as a valid number
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "getint.h"
#include "getch.h"

int getint(int *p)
{
	int c;
	int sign = 1;
	// Ignore space or tab, can use isspace function in ctype.h
	while((c = getch()) == ' '|| c == '\t')
	;	
	// check if not digit
	if (!isdigit(c) && c != EOF && c != '-' && c != '+')
	{
		// not work in case there are some invalid number
		ungetch(c);
		return 0;
	}
	if (c == '-' || c == '+')
	{
		sign = (c == '-') ? -1 : 1;
	//
		c = getch();
		
		// Fix the case return zero if - or + not followed by a digit
		if (!isdigit(c))
		{
			ungetch(c);
			return 0;
		}
	}
	//If *p has no value to assign, they will get automatic number.
	*p = 0;
	if (isdigit(c))
	{
		*p = c - '0';
		while (isdigit(c=getch()))
		{
			*p = 10 * *p + (c-'0');
		}
		*p *= sign; 
	}
	/*In K&R book, they use this line
	 It will guarantee all *pn is 0 when return. 
	 But if the input is 0, how can identify the number they input manual with the automatic number */
	/* for (*pn = 0; isdigit(c), c = getch()) 
		*pn = 10 * *pn + (c - '0');*/
	
	if (c != EOF)
		ungetch(c);
	return c;
}
