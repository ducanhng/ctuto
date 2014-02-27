#include <stdio.h>
#define MAXLENGTH 1000
void reverse1(char s[], int max);
main()
{
	printf("Ex 1-19: Write a function reverse that reverse the character string s. Use it to write a program that reverses its input a line at a time\n");
	// get a line
	printf("input a line\n");
	int len;
	
	char line[MAXLENGTH];
	// Get a line
	while ((len = getline1(line)) > 1)
	{
		// reverse the line
		reverse1(line, len);	
		printf("The reverse line is %s\n",line);	
	}
	
}

int getline1(char s[])
{
	int c,i;
	i=0;
	while ((c=getchar()) != EOF && c != '\n')
	{
		s[i] = c;
		++i;
	}
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	// append end of line 
	s[i] = '\0';
	return i;
}

void reverse1(char s[], int maxlen)
{
	int i,j;
	i=0;
	
	char buffer[MAXLENGTH];
	printf("Write string input %s",s);
	
	//copy in reverse from s[] to buffer[]
	for (i=0; i<=maxlen; ++i)
	{
		if (s[i] != '\n' && s[i] !='\0')
		{	
			buffer[maxlen-2-i] = s[i];
		}
	}
	buffer[maxlen-1] = '\n';
	buffer[maxlen] = '\0';

	for (i=0;i<=maxlen;++i)
	{
		s[i] = buffer[i];
	}

}
