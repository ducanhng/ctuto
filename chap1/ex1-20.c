/* Ex 1-20: Write a program detab that replaces tabs in the input 
with the proper number of blanks to space to the next tab stop. 
Assume a fixed set of tab stops, say every n columns. 
Should n be a variable or a symbolic parameter ?

Author: ducanhng */

#include <stdio.h>
#define TABSIZE 5
#define MAXLINE 1000

int getline1(char s[], int lim);
int count_available_spaces(int index);
main(int maxcolumn)
{
	printf("Get input from user: \n");
	int i,j,len,index;
	char bufferline[MAXLINE];
	char buffer[MAXLINE];
	j = 0;
	// Index is used to count only characters that are not \n, \t
	index = 0;
	// read each line and store in the buffer
	while ((len = getline1(bufferline,MAXLINE)) > 0)
	{
		i = 0;
		
		while (bufferline[i] != '\0' && bufferline[i] != '\n')
		{
			if (bufferline[i] != '\t')
			{
				// Calculate number of available spaces need to write char
				printf("max column is %d", maxcolumn);
				if (index < maxcolumn*TABSIZE)
					buffer[j] = bufferline[i];
				++j;++index;
			}
			if (bufferline[i] == '\t')
			{
				
				//printf("Available space is %d\n", count_available_spaces(j));
				// Must detab in here, calculate and fill spaces to replace tab
				if (count_available_spaces(index) > 0)
				{
					int k,nspaces;
					nspaces = count_available_spaces(index);
					printf("number of space is %d\n",nspaces);
					// Insert to buffer array
					for (k=0;k < nspaces ;++k)
					{	
						if (index < maxcolumn*TABSIZE)
						{
							buffer[j] = ' ';
							++j;++index;
						}
					}
				//	printf("index of buffer is: %d\n", j);
				}
			}
			++i;
		}
		
		// Problem is here, because new line is not a character, if index this characterd,space calculating is not correct
		// How can i solve this ? I must insert n to buffer but exclude n when it calculate space. 
		// That mean must have a number to count character, this number is depend to index. So index must be reset in the new line :)
		if (bufferline[i] == '\n')
		{
			
			buffer[j] = '\n';
			++j;++i;
			index = 0;// reset indexing
		}
	}
	// Finally, insert new line and end of line to new buffer
	buffer[j] = '\0';

	printf("\nRun detab program ............\n%s",buffer);
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
		s[i] = c;	
		++i;
	}
	s[i] = '\0';
	// return character of a line
	return i;
}
