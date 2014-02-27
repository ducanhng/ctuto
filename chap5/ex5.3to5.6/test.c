void strcp(char *, char *);
main()
{
	char s[10];
	int n[10];

	char s1[] = "ducanhng";
	char s2[] = "hello world, blah blah";
	printf("s1 before copying: %s\n",s1);	
	strcp(s1,s2);
//	printf("s1: %s",s1);	
}


void strcp(char *s, char *t)
{
	while ((*s++ = *t++) != '\0');
}
