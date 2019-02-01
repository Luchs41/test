#include <stdio.h>

int ternarySearch(int *arr, int size);

int main(void)
{
	int size = 13;
	int arr[13] = {1, 5, 17, 22, 40, 57, 78, 54, 33, 28, 19, 7, 2};
	int max;
	max = ternarySearch(arr, size);
	int maxIndex;
	for(int i = 0; i <= 12; i++)
	{
		if(*(arr + i) == max)
		{
			maxIndex = i;
			break;
		}
	}

	printf("Array: ");
	for(int i = 0; i <= 12; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\nThe MAX value is %d at index %d\n", max,maxIndex );

	return 0;
}
int ternarySearch(int *arr, int size)
{
	int L, R;
	int S = 0;
	int E = 12;
	for( ; ; )
	{
		L = (2*S + E+3 )/3;
		R = (S + 2*E+3 )/3;
		if(*(arr + L - 1 ) == *(arr + R - 1))
		{
			E = R ;
			S = L ;
		}
		else if(*(arr + L - 1) < *(arr + R - 1))
		{
			E = E;
			S = L - 1;
		}
		else if(*(arr + L - 1) > *(arr + R - 1))
		{
			E = R - 1;
			S = S;
		}
		if(E - S == 2)
		{
			break;
		}
	}
	return *(arr + E - 1 );

}
