#include <stdio.h>

void counting(char *arr, int *count);
int main(void)
{
	int count = 0;
	char arr[10] = {'I', 'L', 'I', 'K', 'E', 'C', 'L', 'A', 'N', 'G'};
	for(int i = 0; i < 10; i++)
	{
		printf("%c", *(arr + i));
	}
	counting(arr, &count);
	
	printf("Number of Target Char : %d\n", count);
	return 0;
}
void counting(char *arr, int *count)
{
	char x;
	printf("\nTarget Char : ");
	scanf("%c", &x);
	for(int i = 0; i < 10; i++)
	{
		if(*(arr + i) == x)
		{
			*count += 1;
		}
	}
	/*
	for(char*ptr = arr;ptr<arr+10;ptr++){
			if(*ptr = x)
				(*count)++;
	}
*/
}
