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
int count_available_spaces(int index);
main()
{
	printf("Pls, input...... \n");
	int i,j,len,index,nspaces,c;
	char bufferline[MAXLINE], buffer[MAXLINE];
	i = j = index = 0;
	// Index is used to count only characters that are not \n, \t
	while ((len = getline1(bufferline,MAXLINE)) > 0)
	{
		i = 0;
		while ((c = bufferline[i++]) != '\0' && c != '\n')
		{
			if (c == '\t')
			{
				nspaces = count_available_spaces(index);
				// Insert properly spaces (or detab) to buffer array
				while (nspaces-- > 0)
				{	
					buffer[j++] = ' ';
					++index;
				}
			}
			else
			{
				// Calculate number of available spaces need to write char
				buffer[j++] = c;
				++index;
			}
		}
		
		// Because new line is not a character so space calculating is not correct
		// How can i solve this ? I must insert n to buffer but exclude n when need to calculate spacing. 
		// That mean must have a number to count character, this number depend on index. So index must be reset in the new line :)
		if (c == '\n')
		{
			buffer[j++] = '\n';
			index = 0;// reset indexing
		}
	}
	// Finally, insert end of line to buffer of lines
	buffer[j] = '\0';
	printf("Run detab program ............\n%s\n",buffer);
}

int count_available_spaces(int index)
{	
	int i;
	i = TABSIZE - (index % TABSIZE);
	return i;
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
