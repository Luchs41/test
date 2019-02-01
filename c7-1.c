#include <stdio.h>
#include <stdlib.h>

int solve(int*original, int*pat, int N);
//메모리 할당한 함수 내에서 free 해야한다
int main()
{
	int size, shift ;
	scanf("%d", &size);
	int*ori;
	int*pattern;

	ori = (int*)malloc(sizeof(int) * size);
	// ori: 0x0000
	pattern = (int*)malloc(sizeof(int) * size);
	
	int i;
	for(i = 0; i < size; i++)
	{
		scanf("%d", &ori[i]);
	}
	for(i = 0; i < size; i++)
	{
		scanf("%d", &pattern[i]);
	}
	
	shift = solve(ori, pattern, size);
	

	free(pattern);

	printf("%d\n", shift);

	return 0;
}
int solve(int*original, int*pat, int N)
{
	int shift = 0;
	int count = 0;
	// original: 0x0100
	original = (int*)realloc(original, sizeof(int) * 2 * N);
	int i, j;
	for(i = 0; i < N; i++)
	{
		original[i + N] = original[i];
	}
	
	for(shift = 0; shift < N; shift++)
	{
		for(i = 0; i < N; i++)
		{
			if(original[shift + i] == pat[i])
			{
				count += 1;
			}
			else
			{
				break;
			}
		}
		if(count == N)
		{
			break;
		}
		else
		{
			count = 0;
		}
		if(shift == N - 1)
		{
			shift = 0;
			free(original);
			return -1;
			break;
		}
	}

	free(original);

	return shift;
}
