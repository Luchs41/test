#include <stdio.h>
#include <stdlib.h>

int* calculate_next(int*pascal_tr, int current_level);
int main()
{
	int level, current_level, i, j;
	int*pascal_tr;
	printf("Input the level of Pascal's triangle: ");
	scanf("%d", &level);
	
	pascal_tr = (int*)malloc(sizeof(int)*current_level);
	for(i = 0; i < level; i++)
	{
		current_level = i + 1;
		pascal_tr = calculate_next(pascal_tr, current_level);
		for(j = 0; j < current_level; j++)
		{
			printf("%d ", *(pascal_tr+j));
		}
		printf("\n");
	}

	return 0;
}

int* calculate_next(int*pascal_tr, int current_level)
{
	int i;
	int* next_level;
	if(current_level == 1)
	{
		pascal_tr[0] = 1;
	}
	next_level = (int*)malloc(sizeof(int)*(current_level + 1));
	for(i = 0; i < current_level; i++)
	{
		if(i == 0 || i == current_level-1)
		{
			next_level[i] = 1;
		}
		else
		{
			next_level[i] = pascal_tr[i-1] + pascal_tr[i];
		}
	}
	free(pascal_tr);
	return next_level;
}
	

