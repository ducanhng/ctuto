/* Ex 1-20: Write a program detab that replaces tabs in the input 
with the proper number of blanks to space to the next tab stop. 
Assume a fixed set of tab stops, say every n columns. 
Should n be a variable or a symbolic parameter ?

Ex 5-11. Modify the program entab and detab (written as exercises in Chapter 1) to
accept a list of tab stops as arguments. Use the default tab settings if there are no arguments.

note: this version is refactored. It's shorter than version in ex1-20(107LOC). Array is used to store line inputed.

Author: ducanhng
Date created: 26 July 2011.

 */

#include <stdio.h>
#define TABSIZE 5
#define MAXLINE 1000

int getline1(char s[], int lim);
int main(int argc, int **argv)
{
	printf("Pls, input...... \n");
	int i,nspaces,c;
	char bufferline[MAXLINE];
	nspaces = 0;
	
	while ((len = getline1(bufferline,MAXLINE)) > 0)
	{
		i = 0;
		while ((c = bufferline[i++]) != '\0' && c != '\n')
		{
			if (c == ' ')
				nspaces++;
			if (c != ' ')
				nspaces = 0;
			if (nspaces == TABSIZE)
			{
				i = i - TABSIZE;
				len = len - TABSIZE+1;
				// Replace them with tab
				bufferline[i] = '\t';
				// Move characters
				int t;
				for (t = i+1;t < len;t++)
					bufferline[t] = bufferline[t+TABSIZE-1];
				nspaces = 0;
				bufferline[len] = '\0';
			}
		}
		printf("Run entab program ............\n%s\n",bufferline);
//		printf("Run show string in program ............\n");
		// These lines are for testing string.
	/*	for (i = 0; i< len;i++)
		{
			if (bufferline[i] == '\t')
			{
				putchar('\\');
				putchar('t');
			}
			else
				putchar(bufferline[i]);
			
		}*/
	}
	return 0;
}


int getline1(char s[], int lim)
{
	int i,c;
	for (i=0;i<lim && (c=getchar()) != '\n' && c != EOF;++i)
	{
		s[i] = c;
	}
	if (c == '\n')
	{
		s[i++] = c;	
	}
	s[i] = '\0';
	// return length of the line
	return i;
}
