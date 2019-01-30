#include <stdio.h>
void func(int a[], int b[], int c[]);
int main(void)
{
	int i;
	int arrayA[5],arrayB[5],arrayMerge[10];
	printf("Input arrayA: ");
	
	for(i=0;i<5;i++)
	{
		scanf("%d", &arrayA[i]);
	}
	printf("Input arrayB: ");
	for(i=0;i<5;i++)
	{
		scanf("%d", &arrayB[i]);
	}
	
	func(arrayA,arrayB,arrayMerge);
	
	printf("Merged array: ");
	
	for(i=0;i<10;i++)
	{
		printf("%d ", arrayMerge[i]);
	}
	printf("\n");
	
	return 0;
}
void func(int a[],int b[], int c[])
{
	int i;
	int temp;
	for(i=0;i<5;i++)
	{
		c[i] = a[i];
	}
	for(i=0;i<5;i++)
	{
		c[i+5] = b[i];
	}
	for(i=0;i<9;i++)
	{
		for(int j=0;j<9-i-1;j++)
		{
			if(c[j]>c[j+1])
			{
				temp = c[j];
				c[j] = c[j+1];
				c[j+1] = temp;
			}
		}
	}
}
