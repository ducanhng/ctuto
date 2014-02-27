
// Program to count the occurrences of each C keyword.

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "getch.h"

#define MAXWORD 100


// Define keytab[] to store counting of keywords.
struct key {
	char *word;
	int count;
} keytab[] = {
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	/*...*/
	"double", 0,
	"int", 0,
	"void", 0,
	"volatile", 0,
	"while", 0
};

int binsearch(char *, struct key *, int);
int getword(char *, int);
#define NKEYS (sizeof keytab / sizeof(struct key))
int main()
{
	int n;
	char word[MAXWORD];
	while (getword(word,MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;
	for (n = 0;n < NKEYS;n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n",keytab[n].count, keytab[n].word);
		
	return 0;
}

// n is maxkey of keytab collection
int binsearch(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;
	low = 0;
	high = n-1;
	while (low <= high)
	{
		mid = (low+high) /2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid +1;
		else 
			return mid;
			
	}
	return -1;
}

// confuse: what the value returning is mean ?
int getword(char *word, int lim)
{
	int c;
	// by pass spacing
	while (isspace(c = getch()))
		;
	if (c != EOF)
		*word++ = c;
	
	// case comment, string constant, preprocessor control
	if (!isalpha(c))
	{
		// if found comment notation, by pass it.
		// There are two cases: // or /* ... */
		if (c == '/')
		{
			// in case comment notation is forward (//)
			if ((c = getch()) == '/')
				while ((c = getch()) != '\n')
					;
			// in case comment notation is */
			else if (c == '*')
				while ((c = getch()) != '*' && c != EOF)
					if (getch() == '*')
						if (getch() == '/')
							break;
		}
		// if found string constants 
		if (c == '"')
			while ((c = getch()) != '"' && c != '\n' && c != EOF)
				;
		// if found preprocessor. Found some bugs in this lines, but don't have time to fix them. Wait me later ...
		if (c == '#')
		{
			while ((c = getch()) != '\n' && c != EOF)
				*word++ = c;
		}
		*word = '\0';
		return c;
	}
	for (;--lim>0;word++)
	{
		if (!isalnum(*word = getch()) && *word != '_' )
		{
			ungetch(*word);
			break;
		}
	}
	*word = '\0';
	return word[0];
}
