/*
Version 2: fix the bug in order by directory
Version 3: Use external variable, repair directory order. Add nature order option

Ex 5-14: Modify the sort program to handle a -r flag, which indicates sorting in reverse
(decreasing) order. Be sure that -r works with -n.

Ex 5-15. Add the option -f to fold upper and lower case together, so that case
distinctions are not made during sorting; for example, a and A compare equal.

Ex 5-16. Add the -d (``directory order'') option, which makes comparisons only on
letters, numbers and blanks. Make sure it works in conjunction with -f.

Ex 5-17. Add a field-searching capability, so sorting may bee done on fields within lines,
each field sorted according to an independent set of options. (The index for this book was
sorted with -df for the index category and -n for the page numbers.)

author: ducanhng
date created: 26 July 2011
*/


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "mysort.h"
#include "mystr.h"

#define MAXLENGTH 100
#define MAXLINES 100
#define ALLOCSIZE 10000
#define VALID_OPTION 1

int getline1(char *, int);
int readlines(char *[], int, char *);
void writelines(char *[], int);
int setopt(char *);
void youneedhelp();

//Global variables. They can be externed in mysort.c and mystr.c
int numberic, revert, fold, directory, nature, key, nfield;

int main(int argc, char **argv)
{
	int lines,c;
	// save lines inputed in a pointer array 
	fold = directory = nature = revert = key = nfield = 0;

	// Use dynamic allocation memory: Umm... maybe in the next time.
	char alloc[ALLOCSIZE];
	char *ptarr[MAXLINES];
	
	// Check argument
	while (--argc > 0 && (*++argv)[0] == '-')
	{
		char *p;
		p = argv[0];
		if ((c = setopt(p)) != VALID_OPTION)	
		{
			printf("Invalid option: -%c\n",c);
			youneedhelp();
			return EXIT_FAILURE;
		}
	}

	if ((lines = readlines(ptarr, MAXLINES, alloc)) > 0)
	{
		// any pointer can be cast to void * and back again without loss of information.
		int (*compare)(void *, void *);
		// It's better than version 2
		compare = (int (*)(void *, void *))(comp); 
		// sorting use quick sort algorithm.
		myqsort((void**)ptarr, 0, lines-1, compare);
		writelines(ptarr,lines);
	}
	return EXIT_SUCCESS;
}

int setopt(char *pstr)
{
	while (*++pstr != '\0')
	{
		if (*pstr == 'r')
			revert = 1;
		else if (*pstr == 'd')
			directory = 1;
		else if (*pstr == 'f')
			fold = 1;
		else if (*pstr == 'n')
			numberic = 1;
		else if (*pstr == 'h')
			nature = 1;
		else if (*pstr == 'k')
		{
			int d;
			// if not digit return failure
			if (!isdigit(*++pstr))
				return *pstr;	
			else
			{
				//get digits
				d = *pstr - '0';
				while (isdigit(*++pstr))
					d = d*10 + (*pstr - '0');
				while (*pstr != '\0')
				{
					if (*pstr == 'r')
						revert = 1;
					else if (*pstr == 'd')
						directory = 1;
					else if (*pstr == 'f')
						fold = 1;
					else if (*pstr == 'n')
						numberic = 1;
					else
						return *pstr;
					pstr++;
				}
			}
			nfield = d;
			key = 1;
			return VALID_OPTION;
		}
		else
		 	return *pstr;
	}

			printf("go here \n");
	return VALID_OPTION;
}

void youneedhelp()
{
	printf("Usage: qsort [OPTION]\n");
	printf("Sorting from input\n");
	printf(" -d\tdirectory order\n");
	printf(" -n\tnumberic order\n");
	printf(" -f\tignore case-sensitive\n");
	printf(" -h\tnature order\n");
	printf(" -r\trevert order\n");
	printf(" -k\t pos,option\n");
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
		printf("\tptarr[%d]:%s\n",i,ptarr[i]);
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
