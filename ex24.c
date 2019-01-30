#include <stdio.h>
int fibo(int);
int main()
{
	int n,result;
	printf("Input n: ");
	scanf("%d", &n);
	if(n>=0){
	result = fibo(n);
	printf("fib(%d) = %d\n", n, result);
	}
	else
	{printf("n cannot be negative number. \n");}
	return 0;
}
int fibo(int n)
{
	int i, result,a,b;
	i = n;
	a = 1;
	b = 0;
	do
	{
		if(n==0)
		{
			result = b;
			i = 0;
		}
		else
		{
			result = a + b;
			b = a;
			a = result;
			i = i - 1;
		}
	}while(i > 1);
	return result;
}
