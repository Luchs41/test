#include <stdio.h>

void swap (float *x, float *y);
int main(void)
{
	float x,y;
	
	printf("Input two Number\n\tx : ");
	scanf("%f", &x);
	printf("\ty : ");
	scanf("%f", &y);
	printf("----------------------------------------------");
	printf("\nBefore : x [%f] y [%f]", x, y);
	
	swap(&x, &y);
	printf("\n----------------------------------------------");
	printf("\nAfter  : x [%f] y [%f]\n", x, y);

	return 0;
}
void swap(float *x, float *y)
{
	float a, b;
	a = *y;
	b = *x;
	*x = a;
	*y = b;
}	
