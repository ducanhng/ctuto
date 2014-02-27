#include <stdio.h>
#define MAXLINE 1000
main()
{
	printf("Ex 1-18: Write a program to remove trailing blanks and tabs from each line of input, and to delete entire blank lines \n");
	int i,c,countblank,counttab,countchar;
	int linelength;

	linelength = countblank = counttab = i = countchar = 0;
	char buffer[MAXLINE];
	while ((c=getchar()) != EOF)
	{
		if (c == ' ')
		{
			++countblank;
			if (countblank == 1 && linelength >0)
			{
				buffer[i] = c;
				++i;
			}
		}
		if (c == '\t' && linelength >0)
		{
			++counttab;
			if (counttab == 1)
			{
				buffer[i] = c;
				++i;
			}
		}
		if (c != ' ' && c != '\t' && c !='\n')
		{
			++linelength;
			if (countblank >1 || counttab >1)
			{
				// reset count
				countblank = 0;
				counttab = 0;
			}
			buffer[i] = c;
			++i;
		}
		if (c == '\n') {
			if (linelength >1)
			{
				buffer[i] = c;
				++i;
			}
			//reset linelength
			linelength = 0;
			
		}
			
	}
	buffer[i] = '\0';
	printf("\nCustomize these line: %s\n", buffer);
	
}

