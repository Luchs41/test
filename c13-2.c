#include <stdio.h>
#include <string.h>

enum Day{mon = 1, tue, wed, thu, fri, sat, sun};
struct Calendar
{
	int year, month, date;
	enum Day day;
	char* dayString;
};
enum Day getDay(int year, int month, int date);
char* getStringDay(enum Day currDay);

int main()
{
	int year, month, date;
	enum Day day;
	char* dayString;

	struct Calendar inputday;

	printf("Input year: ");
	scanf("%d", &inputday.year);
	printf("Input month: ");
	scanf("%d", &inputday.month);
	printf("Input date: ");
	scanf("%d", &inputday.date);

	day = getDay(inputday.year, inputday.month, inputday.date);
	
	dayString = getStringDay(day);

	printf("%d-%d-%d is %s\n", inputday.year, inputday.month, inputday. date, dayString);

	return 0;

}

enum Day getDay(int year, int month, int date)
{
	return (year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + date) % 7;
}

char* getStringDay(enum Day currday)
{
	if(currday == 1)
	{
		char* day = "Monday";
		return day;
	}
	if(currday == 2)
	{
		char* day = "Tuesday";
		return day;
	}
	if(currday == 3)
	{
		char* day = "Wednesday";
		return day;
	}
	if(currday == 4)
	{
		char* day = "Thursday";
		return day;
	}
	if(currday == 5)
	{
		char* day = "Friday";
		return day;
	}
	if(currday == 6)
	{
		char* day = "Saturday";
		return day;
	}
	if(currday == 7)
	{
		char* day = "Sunday";
		return day;
	}
}
