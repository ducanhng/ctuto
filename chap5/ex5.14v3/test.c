#include <stdio.h>
#include <stdlib.h>
main()
{
	char s[] = "54";
	double d1;
	d1 = atof(s);
	printf("d1 is %f\n",d1);	
	char s1 ='a';
	printf("upper s is: %c", s1-32);
	
	int c; c = 0;
	int b = 0;
	int d;
	d = c ? 3 : (b ? 1 : 2);
	printf("d is %d\n",d);
	if (isdigit('\0'))
		printf("end of line in AsciII is %d\n",'\0');	
	int c1 = 80;
	int c2 = 90;
	if (c1 != c2)
		printf("FUCK");
}

