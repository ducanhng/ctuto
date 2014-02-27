/* Ex 5.7 K&R v2
Rewrite readlines to store lines in an array supplied by main, rather than
calling alloc to maintain storage. How much faster is the program?

author: ducanhng
date created: 15 June 2011
*/


#include <stdio.h>
#include "mysort.h"
#include "mystr.h"

#define MAXLENGTH 100
#define MAXLINE 100
#define ALLOCSIZE 10000

int getline1(char *, int);
int readlines(char *[], int, char *);
void writelines(char *[], int);

main()
{
	// save lines inputed in a pointer array 
	int lines;int i;
	char alloc[ALLOCSIZE];
	char *ptarr[MAXLINE];
	
	if ((lines=readlines(ptarr,MAXLINE,alloc)) > 0)
	{
		printf("Before sorting...\n");
		writelines(ptarr,lines);
		printf("After sorting...\n");
		//qsort(ptarr, 0, lines-1);
		selectionsort(ptarr,lines-1);
		//insertionsort(ptarr,lines-1);
		//bubblesort(ptarr,lines-1);
		//shellsort(ptarr,lines-1);
		//mergesort(ptarr,0,lines-1);
		//heapsort(ptarr,lines-1);
		writelines(ptarr,lines);
	}
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

// return length of the line input and save in an array
int getline1(char *s, int maxlength)
{
	int c,len;
	len = 0;
	while ((c=getchar()) != EOF && c != '\n')
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

