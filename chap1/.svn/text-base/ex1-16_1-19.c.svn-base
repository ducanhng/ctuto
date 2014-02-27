#include <stdio.h>
#define MAXLINE 1000

int getline1(char s[], int lim);
void copy(char to[], char from[]);

main()
{
	printf("Ex 1-17: Write a program to print all input lines that are longer than 80 characters:\n");
	char line80[MAXLINE];
	char linebuffer[MAXLINE];
	int len,c,i;
	i = 0;
	while ((c=getchar()) !=EOF)
	{
		linebuffer[i] = c;
		if (i>10)
		{
			if (c == '\n')
			{
				// append end of line
				linebuffer[i+1] = '\0';
				//store to buffer 80
				copy(line80,linebuffer);
				// reset i,reset buffer
				i=0;
			}
		}
		++i;
		if (c == '\n')	i=0;
	}
	
	printf("Lines have more than 10 characters: \n %s", line80);
	return 0;
		
}

void copy(char to[], char from[])
{
	//get current postion index in array
	int i,j;
	i=0;j=0;
	while (to[i] != '\0')//count the index
		++i;

	if (i==1) i=0;
	while ((to[i] = from[j]) != '\0')
	{
		++j;
		++i;
	}
}
