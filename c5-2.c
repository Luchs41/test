#include <stdio.h>
void func(int A[], int B[][5]);
int main(void)
{
	int A[5], B[5][5];
	printf("숫자 5개를 입력하세요\n");
	for(int i = 0; i < 5; i++)
	{
		scanf("%d", &(*(A + i)));
	}
	func(A, B);
	printf("결과입니다\n");
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(j == 4)
			{
				printf("%d\n", *(*(B + i) + j));
			}
			else
			{
				printf("%d ", *(*(B + i) + j));
			}
		}
	}
	return 0;
}
void func(int A[], int B[][5])
{

	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			int temp = i + j;
			if(temp > 4)
			{
				temp = temp - 5;
			}
			*(*(B + i) + j) = *(A + temp);
		}
	}
}
