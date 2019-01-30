#include <stdio.h>

int sqr(int);
int printOne(int);

int main(void)
{
	int input;
	int result;

	printf("Input : ");
	scanf("%d", &input);
	
	result = sqr(input);

	printOne(result);

	return 0;
}

int sqr(int input)
{
	int result;
	result = input * input;
	return result;
}

int printOne(int result)
{
	printf("Result : %d\n", result);
	return 0;
}
