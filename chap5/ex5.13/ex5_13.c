/* Ex 5.13 K&R v2
Write the program tail, which prints the last n lines of its input. By default, n
is set to 10, let us say, but it can be changed by an optional argument so that
tail -n
prints the last n lines. The program should behave rationally no matter how unreasonable the
input or the value of n. Write the program so it makes the best use of available storage; lines
should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of
fixed size.

Base on 5.7.
Rewrite readlines to store lines in an array supplied by main, rather than
calling alloc to maintain storage. How much faster is the program?
Answear: I dunno :(


author: ducanhng
date created: 26 July 2011
*/


#include <stdio.h>
#include <ctype.h>
#include "mysort.h"
#include "mystr.h"

#define MAXLENGTH 100
#define MAXLINE 100
#define ALLOCSIZE 10000
#define DEFAULT_TAILLINES 10
#define NO_ARGS 1
#define HAS_ARGS 2
int getline1(char *, int);
int readlines(char *[], int, char *);
void writelines(char *[], int);
void writelastlines(char **,int,int);
int main(int argc, char **argv)
{
	// save lines inputed in a pointer array 
	int lines;int i;
	int c;
	char alloc[ALLOCSIZE];
	char *ptarr[MAXLINE];
	int lastlines = 0;
	switch (argc)
	{
		case NO_ARGS:
			lastlines = DEFAULT_TAILLINES;// default value
			break;
		case HAS_ARGS:
			if ((*++argv)[0] == '-')
			{
				if (isdigit(c = *++argv[0]))
				{
					lastlines = c - '0';
					while (isdigit(c = *++argv[0]))
					{
						printf("here \n");
						lastlines = lastlines * 10 + (c - '0');
					}
					if (!isdigit(c) && c != '\0') 
					{
						lastlines = 0;
						printf("Invalid option: %c\n",c);	
						break;
					}
				}
				else
				{
					lastlines = 0;
					printf("Invalid option: %c\n",*argv[0]);
					break;
				}
			}
			break;
		default:	
			printf("Usage: tail -n\n");
			break;
	}
	if (lastlines)
	{
		if ((lines=readlines(ptarr,MAXLINE,alloc)) > 0)
		{
			printf("Before sorting...\n");
			writelines(ptarr,lines);
			printf("After sorting...\n");
			heapsort(ptarr,lines-1);
			writelines(ptarr,lines);

			printf("Print lastline ... \n");
			writelastlines(ptarr,lines, lastlines);
		}
	}

	return 0;
}

// Save lines inputed in a pointer array and return number of lines
int readlines(char *ptarr[],int maxlines, char *alloc)
{
	int nlines,i;
	nlines = i = 0;
	int len;
		
	char line[MAXLENGTH];
	char *p;
	p = alloc;
	while ((len=getline1(line, MAXLENGTH)) > 0)
	{
		printf("len is %d\n",len);
		// Check available in storage
		if (ALLOCSIZE - (strlen(alloc) + len) > 0)
		{
			line[len-1] = '\0';
			strcp(p,line);
		}
		else 
		{
			printf("Error: Not enough storage !!!!");
		}
		nlines++;
		ptarr[i++] = p;
		p += len;
	}

	return nlines;
}

void writelines(char *ptarr[], int nlines)
{
	int i;
	for (i=0; i<nlines;i++)
	{
		printf("\tptarr[%d]:%s(%d chars)\n",i,ptarr[i], strlen(ptarr[i]));
	}
}

void writelastlines(char *ptarr[], int nlines, int lastlines)
{
	int i;
	if (lastlines >= nlines)
		lastlines = nlines;
	for (i = nlines - lastlines;i<nlines;i++)
	{
		printf("\tptarr[%d]:%s(%d chars)\n",i,ptarr[i], strlen(ptarr[i]));
	}	
} 

// return length of the line input and save in an array
int getline1(char *s, int maxlength)
{
	int c,len;
	len = 0;
	while ((c=getchar()) != EOF && c != '\n' && len < maxlength)
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

