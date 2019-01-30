#include <stdio.h>
void swap(int*, int*);
int absValue(int);
int main()
{
	
	int a1,b1,c1;
	int a,b,c;
	printf("Input: ");
	scanf("%d %d %d", &a, &b, &c);
	a = absValue(a);
	b = absValue(b);
	c = absValue(c);
	a1 = a;
	b1 = b;
	c1 = c;
	if(a >= b && b >= c)
	a = a;
	else 
	if(a >= c && c >= b)
	swap(&b,&c);
	else 
	if(b >= a && a >= c)
	swap(&b,&a);
	else 
	if(b >= c && c >= a)
	swap(&b,&a), swap(&b,&c);
	else
	if(c >= a && a >= b)
	swap(&c,&a), swap(&b,&c);
	else 
	if (c >= b && b >= a)
	swap(&a,&c);
	
	
	
	
	printf("Result: %d %d %d\n", a, b, c);

	return 0;
}
void swap(int *f, int *g)
{
	int k = *f;
	*f = *g;
	*g = k;
}
int absValue(int one)
{
	if(one >= 0)
	one = one;
	else if(one < 0)
	one = (-1) * one;
	return one;
}
