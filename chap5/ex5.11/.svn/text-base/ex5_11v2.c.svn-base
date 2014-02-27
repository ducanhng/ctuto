/* Ex 1-20: Write a program detab that replaces tabs in the input 
with the proper number of blanks to space to the next tab stop. 
Assume a fixed set of tab stops, say every n columns. 
Should n be a variable or a symbolic parameter ?

Ex 5-11. Modify the program entab and detab (written as exercises in Chapter 1) to
accept a list of tab stops as arguments. Use the default tab settings if there are no arguments.

Version 2: use pointer and command line arguments. For exp: detab 3 4, that mean tapstop at 3th column, 4th column and the next one is default 4+5=9th column.

Author: ducanhng
Date created: 26 July 2011.

 */

#include <stdio.h>
#define TABSIZE 5
#define MAXLINE 1000
#define MAXLENGTH 100
void gettabstops(int, int *, char **);
int getlinedetab(char *, int , int *, int);

int main(int argc, char **argv)
{
	// Copy argv into an array
	int tabargs[argc];
	gettabstops(argc, tabargs, argv);	
	// Check argumnent
	printf("Pls, input...... \n");
	int len;
	char bufferline[MAXLINE];
	while ((len = getlinedetab(bufferline,MAXLENGTH,tabargs, argc)) > 0)
	{
		printf("%s",bufferline);
	}
	return 0;
}

// It's not correct in case argument is not digit like 9s. Will repair in next version.
void gettabstops(int count, int *p, char **s)
{
	while (--count > 0)
	{
		if (!isdigit((*++s)[0]))
		{
			printf("Invalid argument: %c\n",*s[0]);
			break;
		}
		*p++ = atoi(*s);
	}
}
int tabstop(int index, int *s, int count)
{
	int tabstop = 0;
	while (--count > 0)
	{
		if (index < *s)
			return *s;
		tabstop = *s++;
	}

	while (index > tabstop)
		tabstop += TABSIZE;
	return tabstop;
}

// detab and return length of the line input.
int getlinedetab(char *s, int lim, int *tabstops, int count)
{
	int c,len,index,nspaces,stop;
	index = len = 0;
	while ((c=getchar()) != EOF && c != '\n'&& len++ <= lim)
	{
		if (c=='\t')
		{
			stop = tabstop(index,tabstops,count);
			printf("index is %d, stop is %d\n",index,stop);
			nspaces = stop - index;
			printf("nspaces: %d\n",nspaces);
			while (nspaces-- > 0)
			{
				*s++ = ' ';
				index++;
			}
		}
		else
		{
			*s++ = c;
			index++;
		}
	}
	if (c == EOF)
		return c;
	if (c == '\n')
	{
		*s++ = c;
		len++;
	}
	*s = '\0';
	return len;	
}
