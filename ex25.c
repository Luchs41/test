#include <stdio.h>
int isDivisor(int m, int n);
int isPrime(int m);

int main()
{
	int a;
	int m = 2;
	printf("Input : ");
	scanf("%d", &a);
	while(m <= a)
	{
		if(isDivisor(a, m)==1 && isPrime(m)==1)
		{
			printf("%d\t",m);
			m++;
		}
		else
		m++;
	}
	printf("\n");
	return 0;
}
int isDivisor(int a, int m)
{
	int n;
	if(a%m==0)
	n = 1;
	else
	n = 0;

	return n;
}
int isPrime(int m)
{
	int a, b;
	for(a = 2; a < m; a++)
	{
		if(m%a==0)
		{b=0;
		break;}
		else
		b=1;
	}
	return b;
}
