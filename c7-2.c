#include <stdio.h>
#include <stdlib.h>

void double_double(int **a, int *size);
void sort(int *a, int size);
void swap(int *a, int *b);

int main()
{
	int n;
	int i,j;
	int *arr;
	scanf("%d", &n);
	arr = (int *)calloc(n, sizeof(int));

	for(i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for(i = 0; i < 3; i++)
	{	
		double_double(&arr, &n);	
		for(j = 0; j < n; j++)
		{	
			printf("%d ", arr[j]);
		}
		printf("\n");
	}
	free(arr);
}

void double_double(int **a, int *size)
{
	int i;
	int orisize;
	orisize = *size;
	sort(*a, *size);
	*size = (*size) * 2;
	*a = (int *)realloc(*a, (*size) * sizeof(int));
	for(i = 0; i < orisize; i++)
	{
		*((*a) + i + orisize) = *((*a) + i) * 2;	
	}
	sort(*a, *size);
}

void sort(int *a, int size)
{
	int i,j;
	for(i = 0; i < size-1; i++)
	{
		for(j = 0; j < size-1; j++)
		{
			if(a[j] > a[j+1])
				swap(&a[j], &a[j+1]);
		}
	}

}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}
