#include <stdio.h>

int main(int argc, int *argv[])
{
	int i = 0;
	printf("There are %d argument\n",argc-1);
	while (--argc > 0 && i++)
	{
		printf("blah blah\n");
	}

	printf("i has value %d\n",i);
	int c;
	c=getchar();
	c = getchar();
	
	putchar(c);
	printf("\n");	
}
