#include <stdio.h>

int day_of_year(int,int,int);
void month_day(int,int, int *, int *);

static int daytab[2][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

main()
{
	int month, dayofyear;
	
	printf("show the day of year %d\n",day_of_year(1982, 11, 19));
	month_day(1982, 323, &month, &dayofyear);
	printf("show the month %d of day %d\n", month, dayofyear);	

}

int day_of_year(int year, int month, int day)
{
	if (year < 1000 && year > 10000)
		return -1;
	if (month < 1 && month > 12)
		return -1;
	if (day <1 && day >31)
		return -1;
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; i < month; i++)
	{
		day += daytab[leap][i];
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

	for (i=1;yearday > daytab[leap][i];i++)
	{
		yearday -= daytab[leap][i];
	}
	
	*pmonth = i;
	*pday = yearday;
}
