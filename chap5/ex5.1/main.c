#include <stdio.h>
#include "getint.h"
#define SIZE 5

main()
{
	int n, result;
	int arr[SIZE];	
	for (n=0;n < SIZE && (result = getint(&arr[n])) != EOF;++n)
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
		printf("arr[%d]=%d\n ",n,arr[n]);
	}


}
