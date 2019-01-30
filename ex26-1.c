#include <stdio.h>
int value = 1;
int Digit(int num);
int palindrome(int num, int digit);
int main(void)
{
	int num, digit=1;
	printf("Input: ");
	scanf("%d", &num);
	if(num < 0)
	printf("Input number cannot be negative.\n");
	else if(palindrome(num, digit)==1)
	printf("%d is a palindrome number.\n", num);
	else if(palindrome(num, digit)==0)
	printf("%d is not a palindrome number.\n", num);
	
	return 0;
}
int Digit(int num)
{
	if(num / 10 == 0)
		return 1;
	return 10 * Digit(num / 10);
}
int palindrome(int num, int digit)
{
	if(value*value >= Digit(num))
	{
		value = 1;
		return 1;
	}
	else if(((num%(10*digit))-(num%digit))/digit != ((num%(10*(Digit(num)/digit)) - (num%(Digit(num)/digit)))/(Digit(num)/digit)))
	{
		value = 1;
		return 0;
	}
	else
	{
		value*=10;
		return palindrome(num, 10*digit);
	}
}
