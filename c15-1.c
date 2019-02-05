#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int hours;
	int minutes;
	int seconds;
} time;

int main()
{
	time start;
	time finish;
	time* startPtr;
	time* finishPtr;

	startPtr = &start;
	finishPtr = &finish;

	printf("Starting Time : ");
	scanf("%d %d %d", &start.hours, &start.minutes, &start.seconds);
	printf("Finishing Time : ");
	scanf("%d %d %d", &finish.hours, &finish.minutes, &finish.seconds);

	int hour, min, sec;
	hour = (*finishPtr).hours - (*startPtr).hours;
	min = (*finishPtr).minutes - (*startPtr).minutes;
	sec = (*finishPtr).seconds - (*startPtr).seconds;
	if(sec < 0)
	{
		sec += 60;
		min -= 1;
	}
	if(min < 0)
	{
		min += 60;
		hour -= 1;
	}

	printf("%02d : %02d : %02d\n", hour, min, sec);

	return 0;
}
