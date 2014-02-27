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
#include <ctype.h>
#include <math.h>
#define MAXVAL 100
#define MAXLINE 100
#define NUMBER '0'
#define MAXBUFF 100

//function
double pop(void);
void push(double);
int getopt(char []);
int getch(void);
void ungetch(int c);

//Extendable variable
double mystack[MAXVAL];
int stack_index;
int buff[MAXBUFF];
int buffindex;
void printtop();

main()
{
	// Need a stack (an array) to store input
	int c;
	double result;
	stack_index = 0;
	buffindex = 0;
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
				printf("Print the stack:");
				while (mystack[ip] != '\0')
					printf("mystack[%i]: %f  ",ip,mystack[ip++]);
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


// getopt check whether is digit or operation
// 1. get input from user
// 2. if it's a digit then push to stack
// 3. if it's an operation, pop operand from stack and do operation
// 4. if it's EOF, exit.
int getopt(char s[])
{
	int c,index;
	int BLAH;
	BLAH = 0;
	index = 0;
	while ((s[0] = c = getch()) == ' ' && c == '\t')
		;// Do i must write isdigit function ?
	// assume already have isdigit function.
	// assume not digit but it's operation
	if (c == '-')
	{
		//if next input is digit, save as negative number in array
		if (isdigit(c = getch()))
		{
			s[++index] = c;
			//continue insert to string
			while(isdigit(s[++index] = c = getch()) );
			s[++index] = '\0';
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
		while (isdigit(s[++index] = c = getch()));
	}

	if (c == '.') 
	{
		while (isdigit(s[++index] = c = getch()))
			;	
	}

	s[index] = '\0';
	// Assume not digit but will be unknow command
	if (c != EOF)
	{
		ungetch(c);
	}
	return NUMBER;
	
}

double pop(void)
{
	if (stack_index > 0)
	{
		return mystack[--stack_index];
	}
	else
	{
		printf("error: My stack is empty\n");
		return 0.0000;
	}
}

void push(double f)
{
	if (stack_index > MAXVAL)
	{
		printf("error: My Stack is overflow\n");
	}
	else
	{
		mystack[stack_index++] = f;
	}
}

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

void printtop()
{
	printf("Top element in stack is: %f\n",mystack[stack_index-1]);
						
}
void clearstack()
{	
	stack_index = 0;

}

void duplicatetop()
{
	double temp = pop();
	push(temp);
	push(temp);
}

void swaptop()
{
	double temp1 = pop();
	double temp2 = pop();
	push(temp1);
	push(temp2);		
}
