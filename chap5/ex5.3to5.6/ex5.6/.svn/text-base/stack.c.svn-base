#include <stdio.h>
#include "calc.h"
#define MAXVAL 100
double mystack[MAXVAL];
int stack_index = 0;

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
