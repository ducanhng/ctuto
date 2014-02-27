#include<stdio.h>
main()
{
	printf("Ex1.8: write a program to count blanks, tabs, and newline.Please input here ! \n");
	int c, countblank, counttab, countnewline;
	c = getchar();
	countblank=counttab=countnewline = 0;
	while (c != EOF)
	{
		if (c ==' ') countblank++;
		if (c =='\t') counttab++;
		if (c =='\n') countnewline++;
		c = getchar();
	}
	printf("Number of blanks: %d\n", countblank);
	printf("Number of tabs: %d\n", counttab);
	printf("Number of new line: %d\n",countnewline);
	
	printf("Ex1.9: Copy its input to its output, replacing each string of one or more blanks by a single blank\n");
	printf("Input string here\n");
	countblank = 0;
	while ((c=getchar()) != EOF)
	{
		if (c == ' ') countblank++;
		else countblank = 0;
		if (countblank <= 1)
		{ 
			putchar(c);
		}
	}
	printf("Ex1.10: Copy its input to its output, replacing each tab by \\t, each backspace by \\b, each backslash by \\ \n");
	printf("Input string here: \n");
	int d;
	while ((c=getchar())!=EOF)
	{
		d = 0;
		if (c=='\t')
		{
			putchar('\\'); 
			putchar('t');
			d = 1;
		}
		if (c=='\b')
		{
			putchar('\\');
			putchar('b');
			d = 1;
		}
		if (c=='\\')
		{
			putchar('\\');
			putchar('\\');
			d = 1;
		}
		if (d==0)
		{
			putchar(c);
		}
	}
}
