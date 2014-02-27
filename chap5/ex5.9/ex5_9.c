/*

Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers instead of indexing

Author:ducanhng
Created date: 18 July 2011.
Modified date: 5 Aug 2011

*/


#include <stdio.h>

int day_of_year(int,int,int);
void month_day(int,int, int *, int *);
char *month_name(int);

static int daytab[2][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31}, {0,31,29,31,30,31,30,31,31,30,31,30,31} };

// Return month name from n-th
char *month_name(int n)
{
	static char *name[] = {"Illegal month","January","February","March","April","June","July","August","September","November","December"};
	return (n<1 || n>12) ? name[0] : name[n];
}

main()
{
	int month, dayofyear;
	printf("show the day of year %d\n",day_of_year(1982, 11, 19));
	month_day(1982, 323, &month, &dayofyear);
	printf("show the month %s of day %d\n", month, dayofyear);	
}

int day_of_year(int year, int month, int day)
{
	if (year < 1000 || year > 10000)
		return -1;
	if (month <1 && month >12)
		return -1;
	if (day <1 && day >31)
		return -1;
	int i, leap;
	int *p;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	// daytab[leap] is the address of first element of first column in multidimesion array.
	p = daytab[leap]+1;
	
	for (i=1;i < month; i++,p++)
	{
	
		day += *p;
	}

	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	if (year < 1000 && year > 10000)
	{
		*pmonth = -1;
		*pday = -1;
	}

	if (yearday <1 && yearday >365)
	{
		*pmonth = -1;
		*pday = -1;
	}

	int i,leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	int *p;
	p = daytab[leap]+1;
	for (i=1;yearday > *p;p++,i++)
	{
		yearday -= *p;
	}
	
	*pmonth = i;
	*pday = yearday;
}
