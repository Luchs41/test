#include <stdio.h>

int main()
{
	int year;
	printf("Enter the year to be tested: ");
	scanf("%d", &year);
	
	if( year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		printf("It is a leap year. \n");
	else
		printf("It is not a leap year. \n%d is a leap year. \n", year - (year % 4));
	
	return 0;
}
