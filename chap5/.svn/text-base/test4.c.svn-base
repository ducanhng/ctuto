#include <stdio.h>
void testfp(int);

int main(int argc, int **argv)
{
	void (*foo)(int);
	foo = &testfp;
	//foo(2);

	(*foo)(2);	
	return 0;
}

void testfp(int x)
{
	printf("value of x is %d\n",x);
}
