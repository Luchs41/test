#include <stdio.h>

int a,b;
void fourMath(int*c, int*d);
void printResult(int*c, int*d);

int main(void)
{
	int a,b;
	printf("Input two number : ");
	scanf("%d %d", &a, &b);
	fourMath(&a,&b);
	
	return 0;
}

void fourMath(int *c, int *d)
{
	a = *c;
	b = *d;
	*c = a + b;
	*d = a - b;
	a = (*c - b)*b;
	b = (*c-b)/b;
	
	printResult(c,d);

}
void printResult(int *c, int *d)
{
	printf("Result : a+b=%d, a-b=%d, a*b=%d, a/b=%d\n", *c, *d, a, b);

}
