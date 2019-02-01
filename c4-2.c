#include <stdio.h>

int main(void)
{
	int firstday;
	int cal[6][7] = {0};
	printf("SUN-0, MON-1, TUE-2, WED-3, THU-4, FRI-5, SAT-6\nEnter the first day of the month:");
	scanf("%d", &firstday);
	printf("Generated calendar:\n");
	printf("  S  M  T  W  T  F  S\n");
	
	int date =1;
	for(int i=0;i<firstday;i++)
	{
		printf("%3c",' ');
	}
	for(int i=firstday;i<7;i++)
	{
		printf(" %2d", date++);
	}
	for(int i=1;i<6;i++)
	{
		for(int j=0;j<7;j++)
		{
			*(*(cal + i) + j) = date++;
		}
	}
	printf("\n");
	int i=0, j=0;
	for(i=1;i<6;i++)
	{
		for(j=0;j<7;j++)
		{
			if(*(*(cal + i) + j )== 32)break;
			printf(" %2d",cal[i][j]);
		}
		printf("\n");
		if(*(*(cal + i) + j)  == 32)break;
	}
	return 0;
}
