#include <stdio.h>
#include <ctype.h>
void checkp(int, char **);
main()
{
	int digitarr[2] = {1,2};
	digitarr[2] = 10;
	int i;

	for (i=0;i<=2;i++)
		printf(" %d",digitarr[i]);

	printf("\n");
	char *s[] = {"23","45","67"};
	//char *p;
	//p = s[1];
	//*++s[0];	
	//printf("print p: %s\n",p);
	//printf("print first element of p %c\n",p[0]);
	checkp(3,s);
}

void checkp(int count, char **s)
{
	// Copy into an array.
	int p[3];
	int c;
	int i;
	for (i=0;i<count;i++)
	{
		if (!isdigit(*s[0]))
		{
			printf("Invalid argument: %c\n",*s[0]);
			break;
		}
		else	
		{
			p[i] = atoi(*s);
			printf("p is %d\n", p[i]);
			/*c = *s[];
			printf("c is %c\n",c);
			while (isdigit(*++s[0]))
			{
				printf("next c is %c\n",*s[0]);
				c = c*10 + *s[0];
			}*/
		}

		++s;
	}
	printf("array p have:");

	for (i=0;i<3;i++)
		printf(" %d",p[i]);
//	printf("string s: %s\n",s);// Incorrect
//	printf("string s: %s\n", *s[1]);// Incorrect
//	printf("string s: %s\n", **s);//Incorrect
	printf("\n");
//	printf("string s: %c\n", *s[0]);
//	printf("string s: %c\n", **s);
//	printf("string s: %s\n", *s);// Value of pointer is a pointer :D
}
