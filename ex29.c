#include <stdio.h>
float fun(int a, int *b);
int main(void){

	int n;
	int x[100][100];
	int i,j;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d", &x[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%.2f ", fun(n, &x[i][0]));
	}
	printf("\n");
	return 0;
}
float fun(int n, int *b)
{
	float c=0;
	int i;
	for(i=0;i<n;i++)
	{
		c=c+b[i];
	}
	c=c/n;
	return c;
}
