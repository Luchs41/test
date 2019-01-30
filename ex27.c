#include <stdio.h>
void swap(int x[]);
int Max(int x[]);
int Min(int x[]);
int main(void)
{
	int a,b,c,d,e,f,g,h,i,j;
	int max,min;
	printf("Input (10 numbers): ");
	scanf("%d %d %d %d %d %d %d %d %d %d", &a,&b,&c,&d,&e,&f,&g,&h,&i,&j);
	int x[10] = {a,b,c,d,e,f,g,h,i,j};
	swap(x);
	max = Max(x);
	min = Min(x);
	
	printf("%d %d %d %d %d %d %d %d %d %d\n",x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9] );	
	printf("Max: %d, Min: %d\n", max,min);
	return 0;
}

void swap(int x[])
{
	int i;
	for(i=0; i<5; i++)
	{
		int temp;
		temp = x[i];
		x[i]=x[9-i];
		x[9-i]=temp;
	}
}
int Max(int x[])
{
	int a = x[0];
	int i;
	for(i=0;i<10;i++)
	{
		if(a < x[i])
		a = x[i];
	}
	return a;
}
int Min(int x[])
{
	int a = x[0];
	int i;
	for(i=0;i<10;i++)
	{
		if(a > x[i])
		a = x[i];
	}
	return a;
}
