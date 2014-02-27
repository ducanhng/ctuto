/* Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing. Good possibilities include getline, atoi, itoa, reverse, strindex, getop

Ex5.10: Write the program expr, which evaluates a reverse Polish expression from the
command line, where each operator or operand is a separate argument. For example,
expr 2 3 4 + *
evaluates 2 * (3+4).


author: ducanhng
date created: 10 June 2011
date modified: 20 July 2011( more than one month later :(( )
date modified: 4 August 2011. 
	1. Check more on arguments.
	2. Improve getopt function. Fix bug "after digit"
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"
#define MAXLINE 100
int getline1(char *, int);
main(int argc, char **argv)
{
	int c;
	double result, op;//op is used for store value of stack.
	// Store input.
	char s[MAXLINE];

	// Get input, if it's a digit, push to stack
	// If input is operator, pop from stack and do operation
	// getopt is used to check whether is digit or operation
	// getopt return an operation
	if (argc == 1)
	{
		printf("Usage: expr [operator | number]\n");
		return 0;
	}
	printf("POLISH CALCULATION: \n");
	while (--argc > 0)
	{
		c = getopt(s,(++argv)[0]);	
		// process input
		switch(c)
		{
			case NUMBER:
				// atof is used to convert string to double. double atof(const * char)
				printf("\t\t...pushed %s to stack\n",s);
				push(atof(s));
				break; 
			case '+':
				// do operation then push back
				printf("\t\tADD OPERATION\n");
				result = pop() + pop();
				push(result);
				break;
			case '-':
				printf("\t\tSUBTRACT OPERATION\n");
				op = pop();
				result = op - pop(); 
				push(result);
				break;
			case '*':
				printf("\t\tMULTIPLY OPERATION\n");
				push(pop() * pop());
				break;
			case '/':
				printf("\t\tDIVIDE OPERATION\n");
				op = pop();
				if (op != 0.0)
					result = op / pop();
				else
					printf("error: division by zero !\n");	
				push(result);
				break;
			case '%':
				printf("\t\tMODULO OPERATION\n");
				// Use fmod function in math.h
				op = pop();
				// Use math.h library
				result = fmod(op,pop());
				push(result);
				break;
			/*case '\n':
				printf("\t\tResult is : %f\n",pop());
				break;*/
			case ' ':
				break;

			default:
				printf("Unknown command: %c\n",c);
				break;
		}
	}	
	printf("\t\tResult: %f\n",pop());
	return 0;
	
}

// return length of the line input and save in an array
int getline1(char *s, int MAXLENGTH)
{
	int c,len;
	len = 0;
	while ((*s++ = c =getchar()) != EOF && c != '\n'&& len++ <= MAXLENGTH)
		;
	if (c == EOF)
		return c;
	if (c == '\n')
	{
		*s++ = c;
		len++;
	}
	*s = '\0';
	return len;	
}

