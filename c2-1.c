#include <stdio.h>

void gcd(int a, int b, int *c);
int main(void)
{
	int num1, num2, l, A, B;
	int g;
	printf("Enter two integers: ");
	scanf("%d %d", &num1, &num2);
	gcd(num1, num2, &g);
	
	A = num1 / g;
	B = num2 / g;
	l = A*B*g;
	if(A > B)
	{
		int temp = A;
		A = B;
		B = temp;
	}
	printf("GCD is %d\nLCM is %d\nIrreducible fraction is %d/%d\n", g, l, A, B);

	return 0;
}
void gcd(int a, int b, int *c)
{
	if(b > a)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	//a > b
	int nam;
	for( ; ; nam == 0)
	{
		nam = a % b;
		a = b;
		if(nam == 0)
			break;
		b = nam;
	}

	*c = b;
}
