#include <stdio.h>
int main(void)
{
	int n;
	int a,b,c,d;
	a = 1;
	int i,j;
	int k = 2;
	int e = 2;
	int f = -2;
	int g = -2;
	printf("Input: ");
	scanf("%d", &n);
	
	if(n%2==0)
	{
		while(a<=n/2)
		{
			b = n/2 - (a - 1);
			c = (a - 1) * 2;
			d = n/2 - (a - 1);
			for(;b>0;b--)
			{
				printf("*");
			}
			for(;c>0;c--)
			{
				printf(" ");
			}
			for(;d>0;d--)
			{
				printf("*");
			}
		printf("\n");
			a+=1;
		}
	
		while(a<=n)
		{
			b = a - n/2;
			c = 2*n - 2*a;
			d = a - n/2;
			for(;b>0;b--)
			{
				printf("*");
			}
			for(;c>0;c--)
			{
				printf(" ");
			}
			for(;d>0;d--)
			{
				printf("*");
			}
			printf("\n");
			a+=1;
		}
		
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			printf("*");
		}
		printf("\n");
		while(k<=n/2 + 1)
		{
			b = (n - ((k-1)*2-1))/2;
			c = (k - 1) * 2 - 1;
			d = b;
			for(;b>0;b--)
			{
				printf("*");
			}
			for(;c>0;c--)
			{
				printf(" ");
			}
			for(;d>0;d--)
			{
				printf("*");
			}
			printf("\n");
			k++;
		}
		while(k<n)
		{
			b = k - (n/2 + 1) + 1;
			c = n - 2*b;
			d = b;
			for(;b>0;b--)
			{
				printf("*");
			}
			for(;c>0;c--)
			{
				printf(" ");
			}
			for(;d>0;d--)
			{
				printf("*");
			}
			printf("\n");
			k++;
		}
		for(i=1;i<=n;i++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

