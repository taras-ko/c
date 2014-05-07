#include <stdio.h>
#define YEAR 2011
#define MONTH 10
#define DAY 17
#define DAY_OF_YEAR 365

main ()
{
	int d, m;
	int day_of_year(int, int, int);
	void month_day(int, int, int *, int *);

	printf("day_of_year: %d\n", day_of_year(YEAR, MONTH, DAY));
/**/
	month_day(YEAR, DAY_OF_YEAR, &m, &);

	printf("month_day: %d month, %d day\n", m, d);

	return 0;
}

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
	int i, leap;

	if (year < 1 || month < 1  || day < 1 \
		         || month > 12 || day > 31)
	{
		printf("Illegal date\n");
		return -1;
	}

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];

	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	if (year < 1 || yearday < 1  || yearday > 366) \
	{
		printf("Illegal date\n");
		return ;
	}

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

	if (!leap && yearday == 366)
	{
		printf("nonleap year mustn't have %d days\n", yearday);
		return ;
	}

	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}
