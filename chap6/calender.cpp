#include <iostream>
#include <stdio.h>
using namespace std;

void printMonth(int startDay, int Days);

int main()
{
	int daysInMonth = 31;
	int firstDayInWeek = 1;
	printf("\nPlease enter the days in the month: ");
	scanf_s("%d", &daysInMonth);
	if ((daysInMonth > 31) || (daysInMonth < 0))
	{
		printf("\nInvalid days in a month\n");
		system("pause");
		return(1);
	}
	else;

	printf("\nPlease enter the first day of the month in the week: ");
	scanf_s("%d", &firstDayInWeek);
	printf("\n\n\n");
	if ((firstDayInWeek > 7) || (firstDayInWeek < 0))
	{
		printf("\nInvalid firstDay in a week");
		system("pause");
		return(2);
	}
	else;
	printMonth(firstDayInWeek, daysInMonth);
	printf("\n\n\n");
	return 0;
}
//Function def
void printMonth(int startDay, int Days)
{
	int dayCount = 0;
	int weekDay = 1;
	printf("SUN MON TUE WEB THR FRI SAT\n");
	printf("--- --- --- --- --- --- ---\n");
	for (weekDay = 0; weekDay < startDay - 1; weekDay++)
	{
		printf("^^^^");
	}
	for (dayCount = 1; dayCount <= Days; dayCount++)
	{
		if (weekDay > 6)
		{
			printf("\n\n");
			weekDay = 1;
		}
		else
		{
			weekDay++;
			printf("%3d ", dayCount);
		}
	}
		printf("\n_______________________________\n");
		return;
}
