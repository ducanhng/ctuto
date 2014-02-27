#include <stdio.h>
int strlen(char *);
void strcat1(char *, char *);
void strcp(char *, char *);
int strend(char *, char *);
void strncp(char *, char *, int );
void strncat1(char *, char *, int);
main()
{
	char s[] = "Blah Blah";
	char t[] = "ducanhng";
	int n = 3;
//	strncp(s,t,n);
//	printf("s after copy %d chars of t: %s\n ",n,s);
	strcat1(s,t);
/*	int i = 0;*/
	printf("Concat s by t: %s\n",s);
/*	char s1[] = "123ducanhng";
	if (strend(s1,t) == 0)
		printf("t is not the same as end of s1\n");
	else 
		printf("found t in s !\n");*/
}

int strlen(char *s)
{
	int n;
	n = 0;
	while (*s++ != '\0')
		++n;
	return n;	
}
// Ex 5.3
void strcat1(char *s, char *t)
{
	// get the end of string s
	int n;
	n = strlen(s);
	
	printf("n is %d",n);
//	while (*s != '\0')
//	++s;
	s = s+n;
//	strcp(s,t);		while (s++
}

void strcp(char *s, char *t)
{
	while ((*s = *t) != '\0')
	{
		s++;	
		t++;
	}
}
// Ex 5.4
int strend(char *s, char *t)
{
	// compare t with the end of string
	// if t > s return 0
	// if t < s
	// 	get position of s that start by t to compare
	// 		while ( is not equal t)
	//			return 0
	//		return 1
	 
	if (strlen(s) < strlen(t))
		return 0;
	int n = strlen(s) - strlen(t);
	while (n > 0)
	{
		s++;
		n--;
	}
	while (*t != '\0')
	{
		if (*s != *t)
			return 0;
		else
		{
			s++;
			t++;
		}
		
	}
	return 1;

}

// Ex 5.5
// Vua met vua chan nen lam linh tinh. Mai chinh lai.
void strncp(char *s, char *t, int n)
{
	while ((*s = *t) != '\0' && n > 1 )
	{
		s++;	
		t++;
		n--;
	}
}
void strncat1(char *s, char *t, int n)
{
	// get the end of string s
	while (*s != '\0')
	++s;
//	strcp(s,t,n);	
}

