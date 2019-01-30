#include <stdio.h>
int main(void)
{
	int x[20][20]={0,0};
	int n;
	printf("input size of triangle : ");
	scanf("%d", &n);
	int i,j,k=1;
	x[0][0] = 1;

	for(i=1;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(j==0||j==i)
			x[i][j]=1;
			else
			x[i][j]=x[i-1][j-1] + x[i-1][j];
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("%d ",x[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
