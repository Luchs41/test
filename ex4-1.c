#include <stdio.h>
int main(void)
{
	int bir,year,mon,day,year2,age;
	printf("Birthday : ");
	scanf("%4d", &year);
	scanf("%2d", &mon);
	scanf("%2d", &day);


	printf("Your birthday is %4d / %1d / %2d", year, mon, day);
	printf("\nYear : ");
	scanf("%d", &year2);

	age = year2 - year + 1;

	printf("In %d, your age is %d\n", year2, age);
		
	return 0;

}
