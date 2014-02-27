#include <stdio.h>
#include <string.h>
int main(void)
{
	int a = 17;
	printf("a = %d at address %p\n", a, &a);
	a = 19;
	printf("a = %d at address %p\n", a, &a);
	char *arg = "hehe";
	char *pt1;
	pt1 = arg;
	printf("address of pointer pt1 is &pt1 = %p and it has value pt1 = %p, and it point to *pt1 =  %c\n", &pt1, pt1, *pt1);
	printf("address of first element in string pointed to pt1[0] = %c, has address &pt1[0] = %p\n", pt1[0], &pt1[0]);
	printf("address of first element in string pointed to pt1[1] = %c, has address &pt1[1] = %p\n", pt1[1], &pt1[1]);
	printf("arg is pointer to first element of string at address %p, has value %c\n", arg, *arg);	
	printf("arg[0] is value of first element arg pointed to, has value %c\n", arg[0]);
	char *pstr[] = {"hello", "world"};
	printf("pstr is pointer of first element in array of pointer: %p and value of pstr is %p\n", pstr, *pstr);	
	printf("pstr[0] is %p, has value %c or %p\n ", pstr[0], *pstr[0], &pstr[0]);
	printf("pstr[1] is %p, has value %c or %p\n ", pstr[1], *pstr[1], &pstr[1]);
	char blah[10];
	char strarg[4][10];
	strcpy(strarg[0], "hello");
	printf("strarg[0]: %s\n", strarg[0]);
	struct st1 {
		int age;
		int classes[];
	};
	struct st1 student1;
	char a1[] = "hello";
	a1[0] = 'c';
	printf("a1[]: %s\n", a1);
	char *p = "hello";
	p[0] = 'c';
	printf("p string: %s\n",p);
}

