/* Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing. Good possibilities include getline, atoi, itoa, reverse, strindex, getop

author: ducanhng
date created: 10 June 2011
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"
#define MAXLINE 100
int getline1(char *, int);
int strlen(char *);
void strreverse(char *);
int strindex(char *,char);
void itoa(int, char *);
int atoi1(char *);
main()
{
	// Test getline function
	char s[MAXLINE];
	int len;
	printf("Please input here: \n");
	while ((len=getline(s,MAXLINE)) > 0)
		printf("the line has %d characters: %s\n",len,s);


	/*test getop() function
	
	 
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
	
	*/

	/* Reverse string function */
	/*char s[] = "ducanhng";
	strreverse(s);
	printf("reverse string: %s",s);	*/

	/* String index function */
	/*char s[] = "ducanhng blah blah";
	int pos;
	if ((pos = strindex(s, 'a')) != -1)
		printf("Found the character ! in position %d",pos);	
	else 
		printf("NOT FOUND !");		*/


	
}

void itoa(int number, char *s)
{
	// Toi lam :D	
}

int atoi1(char *s)
{
	// Toi lam :D
	return 0;
}

// return the position of the rightmost occurence of t in s, -1 if not valid
int strindex(char *s, char t)
{
	int len = strlen(s);
	int pos = 1;
	int NUMBER1 = 0;
	while (*s++ != '\0')
	{
		if (*s == t)
		{
			return len-pos;
		}
		pos++;
	}
	if (NUMBER1 == 0)
		return -1;
}

void strreverse(char *s)
{
	int i,j;
	char temp;
	i = 0;
	j = strlen(s);
	printf("lengh of string: %d",j);
	while (*s != '\0')
	{
		// exchange element in opposite position	
		if (j>i)
		{
		temp = *(s+i);
		*(s+i) =  *(s+j);
		*(s+j) = temp;
		--j;++i;
		printf("blah ");
		}
		++s;	
	}
	printf("reverse: %s",s);
}


int strlen(char *s)
{
	int len = 0;
	while (*s !='\0' && *s != '\n')
	{
		s++;
		++len;
	}
	return len;
}


// return length of the line input and save in an array
int getline1(char *s, int MAXLENGTH)
{
	int c,len;
	len = 0;
	while ((c=getchar()) != EOF && c != '\n')
	{
		*s = c;
		++s;
		len++;
	}
	if (c == EOF)
		return c;
	if (c == '\n')
	{
		*s = c;
		++s;
		len++;
	}
	*s = '\0';
	return len;	
}

