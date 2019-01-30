#include <stdio.h>

int plus(int, int);
int main(void)
{
	int num1, num2;
	plus(num1, num2);

	return 0;
}

int plus(int num1, int num2)
{
	int result;
	printf("Input first number: ");
	scanf("%d", &num1);
	printf("Input second number: ");
	scanf("%d", &num2);
	
	result = num1 + num2;
	
	printf("%d + %d = %d\n", num1, num2, result);

	return result;
}
