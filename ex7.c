#include <stdio.h>

float solvex(int,int,int,int);
float solvey(int,int,int,int,float);

int main(void)
{
	int a,b,c,d;
	float x,y;
	printf("1st equation: y = ax - b, input 'a' and 'b'\na = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	printf("2nd equation: y = cx - d, input 'c' and 'd'\nc = ");
	scanf("%d", &c);
	printf("d = ");
	scanf("%d", &d);
	
	x = solvex(a,b,c,d);
	y = solvey(a,b,c,d,x);

	printf("x is %f", x);
	printf("\ny is %f\n", y);
	
	return 0;
}

float solvex(int a, int b, int c, int d)
{
	float x;
	x = (b - d)/(a - c);
	return x;
}

float solvey(int a, int b, int c, int d, float x)
{
	float y;
	y = a * x - b;
	return y;
}
