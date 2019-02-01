#include <stdio.h>
void *smaller(void *ptr1, void *ptr2, char option);

int main(void)
{
	char option;
	float a, b;
	printf("Enter the type of numbers: ");
	scanf("%c", &option);
	printf("Enter the 1st number: ");
	scanf("%f", &a);
	printf("Enter the 2nd number: ");
	scanf("%f", &b);
	smaller(&a, &b, option);

	return 0;
}
void *smaller(void *ptr1, void *ptr2, char option)
{

	if(option == 'i')
	{
		int *pint1;
		int *pint2;
		pint1 = ptr1;
		pint2 = ptr2;
		if(ptr1 - ptr2 > 0)
		{
			printf("Smaller value is %d\n", *pint2);
		}
		else
		{
			printf("Smaller value is %d\n", *pint1);
		}
	}
	else if(option == 'f')
	{
		float *pfloat1;
		float *pfloat2;
		pfloat1 = ptr1;
		pfloat2 = ptr2;
		if(*pfloat1 - *pfloat2 > 0)
		{
			printf("Smaller value is %.2f\n", *pfloat2);
		}
		else
		{
			printf("Smaller value os %.2f\n", *pfloat1);
		}
	}
}

