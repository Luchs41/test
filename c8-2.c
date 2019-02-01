#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int **sizeup(int **A, int m, int n);

int main()
{
	srand(time(NULL));

	int** mat;
	int m, n;
	int i, j;
	printf("Input the size of m and n : ");
	scanf("%d %d", &m, &n);
	printf("\n");
	
	mat = (int**)malloc(sizeof(int*) * m);
	for(i = 0; i < m; i++)
	{
		mat[i] = (int*)malloc(sizeof(int) * n);
	}


	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			mat[i][j] = rand()%100;
		}
	}

	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int** mat2;
	mat2 = sizeup(mat, m, n);

	for(i = 0; i < 2*m; i++)
	{
		for(j = 0; j < 2*n; j++)
		{
			printf("%d ", mat2[i][j]);
		}
		printf("\n");
	}
	//free 추가해라	
	for(i = 0; i < m; i++)
	{
		free(mat[i]);
	}
	free(mat);
	for(i = 0; i < m; i++)
	{
		free(mat2[i]);
	}
	free(mat2);
	return 0;
}

int **sizeup(int **A, int m, int n)
{
	int **B;
	int i, j;

	B = (int**)malloc(sizeof(int*) * 2*m);
	for(i = 0; i < 2*m; i++)
	{
		B[i] = (int*)malloc(sizeof(int) * 2*n);
	}
	
	for(i = 0; i < m ; i++)
	{
		for(j = 0; j < n; j++)
		{
			B[i][j] = A[i][j];
			B[i+m][j+n] = A[i][j];
			B[i][j+n] = A[i][j];
			B[i+m][j] = A[i][j];
		}
	}
	return B;
}
