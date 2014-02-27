#include <stdio.h>
void arr_test(char x[1]);
void wrfin(int, int, int);
int fi(int);
void printf_fi(int);
main(int argc, char **argv)
{
	//char arr[10];
	//arr_test(arr);
	char *p;
	// before assignment
	printf("sizeof pointer to char before assign: %d\n",sizeof(p));
	char x = 'b'; 
	p = &x; 
	printf("value of pointer:p(size:%d): %c\n",sizeof(p),*p); 
	printf("First argv: %s(%p)\n",argv[0],argv[0]); 
	int count;
	char *arr2[] = {"hello","blah","ballo"};
	printf("sizeof arr: %d sizeof element: %d\n",sizeof(arr2),sizeof(arr2[0]));
	count = sizeof(arr2)/sizeof(arr2[0]);
	printf("count: %d\n",count);
	/*while (--argc > 0 && (*++argv)[0] == '-')
	{
		
	}*/
//	int x1 = sizeof((++argv)[0]);
	++argv;
	int x1 = sizeof(argv[0]);
	printf("Next argv: %s(%p-size:%d)\n",argv[0],argv[0],x1);
	//printf("first string(%d): %s\n", x1, argv[0]);
	char a[] = "-n3";
	int x2 = sizeof(a);
	printf("test size of string: %d\n",x2);
	printf("size of char %d\n",sizeof(char));
	printf("finabocci nth: %d\n", fi(6)); 
	wrfin(0,1,50);
	printf_fi(10);
	return 10;
}

void arr_test(char x[1])
{
	printf(""); 
}
void arr_test2(char **p)
{

}
int fi(int n)
{
	int x;
	if (n == 1)
	{	
		x = 0;
	//	printf("%4d\n",x);
		return x;
	}
	if (n == 2)
	{ 
		x = 1;
	//	printf("%4d\n",x);
		return x;
	}
	else if (n>2)
	{
		x = fi(n-1) + fi(n-2);
	//	printf("%4d\n",x);
	}
	return x;
}

// write finabocci numbers
// n: number of nth finabocci.
void wrfin(int previous, int last, int n)
{
	if (previous == 0)
	{
		printf("%5d\n",0);
		printf("%5d\n",1);
		n = n - 2;
	}

	int temp;
	if (n > 0)
	{
		temp = last;
		last = previous + last;
		printf("%5d\n", temp);
		n--;
		wrfin(temp, last, n);
	}
}

int wrfin1(int n)
{	
	int previous, last, temp;
	previous = 0;
	last = 1;
	temp = previous + last;
	if (temp = 1)
	{
		
	}
}

void printf_fi(int n)
{
	int num1, num2, num;
	num1 = 0;
	num2 = 1;
	for (int i = 0; i < n - 1; i++)
	{
		num = num1 + num2;
		if (num == 1 )
		{
			printf("0\n");
			printf("1\n");
		}
		else
			printf("%5d\n", num);
		num1 = num2;
		num2 = num;
	}
}
