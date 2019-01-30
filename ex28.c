#include <stdio.h>
void func(char arr[]);
int main()
{
	char x[50];
	int i;
	for(i=0;i<50;i++)
	{
		scanf("%c",&x[i]);
	}
	func(x);
	for(i=0;i<50;i++)
	{
		printf("%c",x[i]);
	}
	printf("\n");
	return 0;
}
void func(char x[])
{
	int i;
	for(i=0;i<50;i++)
	{
		if(x[i]>=97)
		x[i]=x[i]-('a'-'A');
	}
}
