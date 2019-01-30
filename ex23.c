#include <stdio.h>
void func_gcd(int a, int b, int* gcd);
int main(void)
{
	int a, b, gcd;
	printf("Input ifrst number: ");
	scanf("%d", &a);
	printf("Input second number: ");
	scanf("%d", &b);
	func_gcd(a, b, &gcd);
	
	printf("GCD: %d\n", gcd);

	return 0;
}
void func_gcd(int a, int b, int* gcd)
{
	int n, a1, b1;
	
	for(n = a%b; n != 0; )
	{
		a = b;
		b = n;
		n = a%b;
	}

	*gcd = b;
}
