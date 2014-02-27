/*
	POLISH CALCULATION.
	
	4.3 Given the basic framework, it's straightforward to extend the calculator.
	Add the modulus (%) operator and provisions for negative numbers

	4.4  Add the commands to print the top elements of the stack without popping, to
	duplicate it, and to swap the top two elements. Add a command to clear the stack.

	4.6 Add commands for handling variables. (It's easy to provide twenty-six variables
	with single-letter names.) Add a variable for the most recently printed value.

	Author: ducanhng
	Created date: 9 May 2011
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"
#define MAXLINE 100
main()
{
	// Need a stack (an array) to store input
	int c;
	double result;
	char s[MAXLINE];
	double op;
	int ip;
	ip = 0;
	printf("POLISH CALCULATION \n");
	// Get input, if it's a digit, push to stack
	// If input is operator, pop from stack and do operation

	// getopt is used to check whether is digit or operation
	// getopt return an operation
	while ((c=getopt(s)) != EOF)
	{	
		// in each case, have different action
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
				printtop();		
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
			case '\n':
				printf("\t\tResult is : %f\n",pop());
				break;
			case ' ':
				break;

			default:
				printf("Unknown command ! \n");
				break;
		}
	
	}
}
