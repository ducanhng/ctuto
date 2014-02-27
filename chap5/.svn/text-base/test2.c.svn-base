#include <stdio.h>
#include <string.h>
#define MAXLINE 100
// pattern find -nx pattern
int getline1(char *, int);

main(int argc, char *argv[])
{
	// Steps to solve
	// 1. Identify loop to check, limited of the loop 
	// 2. check argc > 0. 
	// 3.

	int c, number = 0, except = 0, lineno = 0, found = 0;
	char line[MAXLINE];
	// Assure loop run when argc always greater than 1.
	while (--argc > 0 && (*++argv)[0] == '-')
	{
		// Do something in loop.
		while (c = *++argv[0])
		{
			switch (c)
			{
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("Illegal option %c\n",c);
					argc = 0;
					found = 0;
					break;
			}
		}
	}

	if (argc != 1)
	{
		printf("Usage: find -x -n pattern\n");
	}
	// When the loop finished, argc = 1
	else
	{
		//OK. Got right expression. Let to use something gain from loop. Present the result
		while (getline1(line,MAXLINE) > 0)
		{
			lineno++;
			if ((strstr(line,*argv) != NULL) != except)
			{
				if (number) 
				// print number of lines.
					printf("%d: ",lineno);
				// print line
				printf("%s\n",line);
				found++;
			}
		}	
	}
	return found;	
}

// return length of the line input and save in an array
int getline1(char *s, int maxlength)
{
	int c,len;
	len = 0;
	while ((c=getchar()) != EOF && c != '\n' && len <= maxlength)
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
