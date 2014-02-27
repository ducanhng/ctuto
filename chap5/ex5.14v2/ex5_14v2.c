/*
Exercise 5-16. Add the -d (``directory order'') option, which makes comparisons only on
letters, numbers and blanks. Make sure it works in conjunction with -f.
Note: still a few bugs, I'll fix
Version2: fix the bug in order by directory

Ex 5-15. Add the option -f to fold upper and lower case together, so that case
distinctions are not made during sorting; for example, a and A compare equal.

Ex 5-14: Modify the sort program to handle a -r flag, which indicates sorting in reverse
(decreasing) order. Be sure that -r works with -n.

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

int getline1(char *, int);
int readlines(char *[], int, char *);
void writelines(char *[], int);
int setopt(char *, int *, int *,int *);
void youneedhelp();
int main(int argc, char **argv)
{
	// save lines inputed in a pointer array 
	int lines, revert, fold, directory;
	fold = directory = 0;
	revert = 1;

	// Use dynamic allocation memory: Umm... maybe in the next time.
	char alloc[ALLOCSIZE];
	char *ptarr[MAXLINES];
	// Check argument
	while (--argc > 0 && (*++argv)[0] == '-')
	{
		char *p;
		p = argv[0];
		if (!setopt(p,&directory, &revert, &fold))	
		{
			youneedhelp();
			return EXIT_FAILURE;
		}
	}

	while ((lines = readlines(ptarr, MAXLINES, alloc)) > 0)
	{
		// any pointer can be cast to void * and back again without loss of information.
		int (*comp)(void *, void *, int);
		// Is it too long :(
		comp = (int (*)(void *, void *, int))(directory ? strdfcmp : strfcmp); 
		// sorting use quick sort algorithm.
		myqsort((void**)ptarr, 0, lines-1, comp, fold, revert);
		writelines(ptarr,lines);
	}
	return EXIT_SUCCESS;
}

int setopt(char *pstr, int *directory, int *revert, int *fold)
{
	while (*++pstr != '\0')
	{
		if (*pstr == 'r')
			*revert = -1;
		else if (*pstr == 'd')
			*directory = 1;
		else if (*pstr == 'f')
			*fold = 1;
		else
		 	return 0;
	}
	return 1;
}

void youneedhelp()
{
	printf("Invalid option:\n");
	printf("Usage: qsort [OPTION]\n");
	printf("Sort the list by choosing option\n");
	printf(" -d\tSort the list by directory order\n");
	printf(" -f\tSort the list by fold\n");
	printf(" -r\tSort the list by revert order\n");
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

