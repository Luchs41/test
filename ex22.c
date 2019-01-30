#include <stdio.h>
int func(int , int);
int main(void)
{
	int a, b,c=0, result;
	printf("Input first number: ");
	scanf("%d", &a);
	printf("Input second number: ");
	scanf("%d", &b);
	if(b > a)
	{
		c = b;
		b = a;
		a = c;
	}
	else
		a = a;
	if(a * b == 0)
	{
		printf("Input is less than 1\n");
	}
	else
	{	
		result = func(a, b);
		printf("Result: %d\n", result);
	}
	return 0;
}
int func(int a, int b)
{
	int i, sum=0;
	for(i = b; i <= a; i++)
	{
		if(i%2==0 || i%3==0)
			sum = sum + i;
		else
			sum = sum;
	}
	return sum;
}
