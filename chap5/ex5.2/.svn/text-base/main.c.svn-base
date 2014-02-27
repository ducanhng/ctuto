#include <stdio.h>
#include "getfloat.h"
#define SIZE 5

main()
{
	int n;
	int result;
	float arr[SIZE];	
	for (n=0;n < SIZE && (result = getfloat(&arr[n])) != EOF;++n)
	{
		switch (result)
		{
			case 0:
			printf("Not valid number\n");
			break;
			case EOF:
			printf("End of File !\n");
			break;
			default:
			printf("%d valid number:\n",n+1);
			break;	
		}
	}
	printf("print the array of integer \n");
	for (n=0;n<SIZE;++n)
	{
		printf("arr[%d]=%.5f\n ",n,arr[n]);
	}
}
