#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **transpose(int **A, int m, int n);

int main()
{
	srand(time(NULL));
	int m, n;
	int **mat;
	int i, j;
	printf("Input the size of m and n : ");
	scanf("%d %d", &m, &n);printf("\n");
	mat = (int **)malloc(sizeof(int *) * m);
	for(i = 0; i < m; i++)
	{
		mat[i] = (int *)malloc(sizeof(int) * n);
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
	int **mat2;
	mat2 = transpose( mat,  m,  n);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			printf("%d ", mat2[i][j]);
		}
		printf("\n");
	}
	
	for(i = 0; i < m; i++)
	{
		free(mat[i]);
	}
	free(mat);
	
	for(i = 0; i < n; i++)
	{
		free(mat2[i]);
	}
	free(mat2);

	return 0;
}

int **transpose(int** A, int m, int n)
{
	int **B;
	int i, j;
	B = (int **)malloc(sizeof(int *) * n);
	for(i = 0; i < n; i++)
	{
		B[i] = (int *)malloc(sizeof(int) * m);
	}
	for(i=0;i<m;i++)
	{
		for(j = 0; j < n; j++)
		{
			B[j][i]=A[i][j];
		}
	}
	return B;
}
