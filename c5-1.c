#include <stdio.h>
void add(int A[][100], int B[][100], int n);

int main(void)
{
	int A[100][100], B[100][100];
	int size;
	printf("행렬의 사이즈를 입력하세요 ");
	scanf("%d", &size);
	printf("첫번째 행렬을 입력하세요\n");
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			scanf("%d", &(*(*(A + i) + j)));
		}
	}
	printf("두번쨰 행렬을 입력하세요\n");
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			scanf("%d" ,&(*(*(B + i) + j)));
		}
	}
	
	add(A, B, size);
	printf("결과입니다\n");
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(j == size - 1)
			{
				printf("%d\n", *(*(A + i) + j));
			}
			else
			{
				printf("%d ", *(*(A + i) + j));
			}
		}
	}
	return 0;
}
void add(int A[][100], int B[][100], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			*(*(A + i) + j) = *(*(A + i) + j) + *(*(B + i) + j);
		}
	}
}
