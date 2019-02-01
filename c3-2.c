#include <stdio.h>

void move_oreder(int* arr);
int main(void)
{
	int arr[10];

	printf("Input 10 integer : ");
	for(int i = 0; i < 10; i++)
	{
		scanf("%d", (arr + i));
	}
	printf("\nBefore\t: ");
	for(int i = 0; i < 10; i++)
	{
		printf("%d ", *(arr + i));
	}
	move_order(arr);
	printf("\nAfter\t: ");
	for(int i = 0; i < 10; i++)
	{
		printf("%d ", *(arr + i));
	}
	return 0;
}
void move_order(int* arr)
{
	int arr2[11];
	for(int i = 0; i < 10; i++)
	{
		*(arr2 + i) = *(arr + i);
	}
	*(arr2 + 10) = *(arr + 0);
	for(int i = 0; i < 10; i++)
	{
		*(arr + i) = *(arr2 + i + 1);
	}
}
