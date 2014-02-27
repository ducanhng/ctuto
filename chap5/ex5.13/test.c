#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char *, char *);
void swap2(char *,char *);
void swap3(char *[], int, int);
int strcmp1(char *, char *);
main()
{
	
	int year,leap;
	year = 2012;
	leap = year%4 == 0;
	printf("leaf is %d\n",leap);
	printf("i is %d\n",1/2);
	char s1[] = "alsl";
	char s2[] = "ducanhng";
	printf("length of s2: %d\n",strlen(s2));	
	printf("value compare return is %d\n",strcmp(s1,s2));	
	if (strcmp(s1,s2) > 0)
		printf("s1 is greater than s2\n");
	if (strcmp(s1,s2) < 0)
		printf("s1 is less than s2\n");
	if (strcmp(s1,s2) == 0)
		printf("Two string is equal\n");	




	char a[] = "abcd";
	char b[] = "ef";
	char c[] = "ghiklmn";
	char *p,*q,*r;
	p = a;
	q = b;
	r = c;

	char x = 'g';
	char y = 'd';
	if (x == y)
		printf("is equal \n");
	else
		printf("not equal \n");
	int z = x - y;
	printf("x(%d) - y(%d) is : %d\n", x,y,z);
	// store p,q,c in an array.
	char *parr[100];
	// When work with character array, alway have number of element that intend to input.
	parr[0] = p;
	parr[1] = q;
	parr[2] = r;
	parr[1] = parr[0];
	int i = 0;
	for (i=0;i<3;i++)
		printf("parr[%d](%p): %s\n",i,parr[i],parr[i]);
	// Want to be swap a and b
	swap3(parr,0,1);	
	// After swap, print element
	for (i=0;i<3;i++)
		printf("parr[%d](%p): %s\n",i,parr[i],parr[i]);
	
}

int strcmp1(char *s1, char *s2)
{
	for (;*s1 == *s2;s1++,s2++)
	{
		printf("Go here \n");
		if (*s1 == '\0')
			return 0;
	}
	printf("s1 is");
	return *s1 - *s2;
}

void swap(char *s1, char *s2)
{
	char temp;
	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void swap2(char *s1, char *s2)
{
	char *temp;
//	*temp = *s1;
	//*temp = *s1;
//	*s1 = *s2;
//	*s2 = *temp;
}

void swap3(char *parr[], int i, int j)
{
	char *temp;
	// Need a loop from left to right
	temp = parr[i];
	parr[i] = parr[j];
	parr[j] = temp;
}
