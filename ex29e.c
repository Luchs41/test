#include <stdio.h>
void func(int (*a)[4][4]);
int main(void)
{
	int x[3][4][4];
	int i,j;
	printf("First matrix:\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d", &x[0][i][j]);
		}
	}

	printf("Second matrix:\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d", &x[1][i][j]);
		}
	}
	func(x);
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t", x[2][i][j]);
			if(j==3)
			{
				printf("\n");
			}
		}
	}

	printf("\n");
	
	return 0;
}
void func(int (*a)[4][4])
{
	int x,y,i;
	for(x=0;x<4;x++)
	{
		for(y=0;y<4;y++)
		{
			a[2][x][y] = a[0][x][0]*a[1][0][y] + a[0][x][1]*a[1][1][y] + a[0][x][2]*a[1][2][y] + a[0][x][3]*a[1][3][y];
		}
	}
}
