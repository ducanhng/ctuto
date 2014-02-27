#include <stdlib.h>
#include <stdio.h>
#include "mystr.h"
#include <ctype.h>
// Copy string to other string
extern int numberic, revert, fold, directory, nature, key, nfield;
void strcp(char *s1, char *s2)
{
	while ((*s1++ = *s2++) != '\0');	
}

int comp(char *s1, char *s2)
{
	int d;
	if (key)
		// call compare field function
		d = comp_field(s1,s2,nfield);
	else if (numberic)
		d = numcmp(s1,s2);
	else if (directory)
		d = dircmp(s1,s2);
	else if (nature)
		d = natcmp(s1,s2);
	else
		d = strcmp(s1,s2);

	if (revert)
		return -d;
	else
		return d;
}

// return pointer to first element of field
char *ptofield(char *s, int nfield)
{
	while (--nfield > 0)
	{
		while (isblank(*s))
			s++;
		while (!isblank(*s) && *s != '\0')
			s++;
		if (*s == '\0')
			return NULL;
	}
	return s;
	/*int i;
	for (i=0;i<nfield && *s != '\0';)
	{
		if (!isblank(*s) && isblank(*(s+1)))
		{
			i++;
		}
		s++;
	}
	return s;*/
}

int comp_field(char *s1, char *s2, int nfield)
{
	int d;
	char *p1;
	char *p2;
	p1 = ptofield(s1,nfield);
	p2 = ptofield(s2,nfield);
	// will add nature option later
	if (numberic)
	{
		d = numcmp(p1,p2);
	}
	else if (directory)
	{
		while (1)
		{
			// Increase pointer when is blank (tab or space) and !isdir
			// Only accept alpha and digit
			while (isblank(*p1) && !isdir(*p1))
				p1++;
			while (isblank(*p2) && !isdir(*p2))
				p2++;
			// Start to compare
			d = (fold ? myupper(*p1) : *p1) - (fold ? myupper(*p2) : *p2);
			if (d != 0)
				return d;
			p1++;p2++;
			// if end of field p1 or p2 is blank
			if (isblank(*p1) && isblank(*p2))
			{
				return *p1 - *p2;
			}
		}
	}
	// default
	else
	{
		while (isblank(*p1))
			p1++;
		while (isblank(*p2))
			p2++;
		while(1)
		{
			d = *p1 - *p2;
			if (d != 0)
				return d;
			p1++;p2++;
			if (isblank(*p1) && isblank(*p2))
				return *p1 - *p2;
		}
	}
	
}

int strcmp(char *s1, char *s2)
{
	int c1, c2;
	for (; (c1 = (fold ? myupper(*s1) : *s1)) ==  (c2 = (fold ? myupper(*s2) : *s2)); s1++, s2++)
		if (*s1 == '\0')
			return 0;
	return c1 - c2;
}
// Nature comparision.
int natcmp(char *s1, char *s2)
{
	int c1,c2;
	while (1)
	{
		c1 = *s1;	
		// Numberic case
		if (isdigit(c1))
		{
			c2 = *s2;
			// chap1 vs chap 1
			if (isblank(c2))
				return -1;
			// chap1 vs chapa
			if (!isdigit(c2))
			{
				if (c2 == '\0')
					return 1; 
				return 1;
			}
			// get numberic
			c1 = *s1 -'0';
			c2 = *s2 -'0';
			// Check next input is digit.
			while (isdigit(*++s1))
				c1 = c1*10 + *s1-'0';
			while (isdigit(*++s2))
				c2 = c2*10 + *s2-'0';
			// compare two number: s1 and s2
			if (c1 != c2)
				return c1 - c2;
		}
		//blank case
		else if (isblank(*s1))
		{
			// chap 1 vs chap1
			if (isdigit(*s2))
				return 1;
			// chap 1 vs chapa
			if (!isblank(*s2))
				return -1;
			s1++;s2++;
		}
		// alphabet, end of line ...
		else
		{
			if (*s1 == '\0' && *s2 == '\0')
				return 0;
			if (*s1 == '\0'&& *s2 != '\0')
				return -1;
			if (isdigit(*s2))
				return 1;
			// chapa vs chap 1
			if (isblank(*s2))
				return -1;
			//case: chap1a vs chap1b
			c1 = fold ? myupper(*s1) : *s1;
			c2 = fold ? myupper(*s2) : *s2;
			if (c1 != c2)
			{
				return c1 - c2;
			}
			s1++;s2++;
		}
	}
}

// Sort by directory order, sort only by letter, digit, and blank
int dircmp(char *s1, char *s2)
{
	int d;
	while (1)
	{
		while (!isdir(*s1) && *s1 != '\0')
			s1++;
		while (!isdir(*s2) && *s2 != '\0')
			s2++;

		d = (fold ? myupper(*s1) : *s1) - (fold ? myupper(*s2) :*s2);
		
		if (d != 0)
			return d;
		if (*s1 == '\0' && *s2 == '\0')
			return 0;
		s1++;s2++;
	}
}

static int isdir(char c)
{
	return isalpha(c) || isdigit(c) || isblank(c);
/*	if (isalpha(s) || isdigit(s) || isblank(s))
		return 1;
	else 
		return 0;*/
}

int myupper(char s)
{
	// from 97 - 122 is the range of a - z in ASCII
	if (s >= 97 && s <= 122)
	{
		return s-32;
	}
	return s;
}

int numcmp(char *s1, char *s2)
{
	double d1 = atof(s1);
	double d2 = atof(s2);
	if (d1 > d2)
		return 1;
	if (d1 < d2)
		return -1;
	if (d1 == d2)
		return 0;
}

// return the length of string
int strlen(char *s)
{
	int n = 0;
	while (*s++ != '\0')
		++n;
	return n;
}
