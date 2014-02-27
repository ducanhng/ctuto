#include <stdlib.h>
#include <stdio.h>
#include "mystr.h"
#include <ctype.h>
// Copy string to other string
void strcp(char *s1, char *s2)
{
	while ((*s1++ = *s2++) != '\0');	
}

// Compare two string in lexicographic order. return < 0 if s1 < s2, equal 0 if s1 = s2, > 0 if s1 > s2 
/*int strcmp(char *s1, char *s2)
{
	// Write a function that upper character.
	for ( ;*s1 == *s2;s1++,s2++)
	{
		if (*s1 == '\0')
		return 0;	
	}
	return *s1 - *s2;
}*/

int strfcmp(char *s1, char *s2, int fold)
{
	int c1, c2;
	for (; (c1 = (fold ? myupper(*s1): *s1)) ==  (c2 = (fold ? myupper(*s2) : *s2)); s1++, s2++)
		if (*s1 == '\0')
			return 0;
	return c1 - c2;
}

/*
// This version is not correct
int strdcmp1(char *s1, char *s2)
{
	// 	rule: digit < blank < letter
	// 	if (both of the are digit)
	//		digit1 - digit2
	// 	if (the one is digit or the one is blank and the other is not blank or digit)
	//		return -1
	//	if (the one is blank and the other is not blank or digit)
	// 		return -1
	
	for (;*s1 == *s2; s1++, s2++)
	{

		if (isdigit(*s1) && isdigit(*s2))
			return atof(s1) - atof(s2);
		if (*s1 == '\0')
			return 0;
	}
	if ((isdigit(*s1) && !isdigit(*s2)) || (isdigit(*s1) && !isblank(*s2) && !isdigit(*s2)))
		return -1;
	else if (isdigit(*s1) && isdigit(*s2))
		return atof(s1) - atof(s2);
	else
		return *s1 - *s2;
}
// -df with upper case. This version is not correct.
int strdfcmp1(char *s1, char *s2)
{
	int c1, c2;	
	for (; (c1=myupper(*s1)) == (c2=myupper(*s2)); s1++, s2++)
	{
		if (isdigit(c1))
			return atof(s1) - atof(s2);
		if (c1 == '\0')
			return 0;
	}
	if ((isdigit(c1) && !isdigit(c2)) || (isdigit(c1) && !isblank(c2) && !isdigit(c2)))
		return -1;
	else if (isdigit(c1) && isdigit(c2))
		return atof(s1) - atof(s2);
	else
		return c1 - c2;
}

*/

/*int strdcmp(char *s1, char *s2)
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
			if (*s1 != *s2)
			{
				return *s1 - *s2;
			}
			s1++;s2++;
		}
	}
}*/

int strdfcmp(char *s1, char *s2, int fold)
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
	return atof(s1) - atof(s2);
}

// return the length of string
int strlen(char *s)
{
	int n = 0;
	while (*s++ != '\0')
		++n;
	return n;
}
