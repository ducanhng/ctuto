#include "mystr.h"

// Copy string to other string
void strcp(char *s1, char *s2)
{
	while ((*s1++ = *s2++) != '\0');	
}

// Compare two string. return < 0 if s1 < s2, equal 0 if s1 = s2, > 0 if s1 > s2 
int strcmp(char *s1, char *s2)
{
	for ( ;*s1 == *s2;s1++,s2++)
	{
		if (*s1 == '\0')
		return 0;	
	}
	return *s1 - *s2;
}

// return the length of string
int strlen(char *s)
{
	int n = 0;
	while (*s++ != '\0')
		++n;
	return n;
}
