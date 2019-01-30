#include <stdio.h>
int main()
{
	int n,i;
	scanf("%d", &n);
	int a[n];
	for(i=0;i<n;i++)
	{
		a[i] = i+1;
	}
	for(i=0;i<n;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		a[i]=a[i]*a[i];
		printf("%d ",a[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		a[i]=a[i]*a[i];
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
