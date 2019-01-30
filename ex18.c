#include <stdio.h>

float plus(float a, float b);
float minus(float a, float b);
float gob(float a, float b);
void WWW(float a, float b);


int main()
{
	float a, b, result;
	char op;
	printf("Please enter the formula. (ex : 12.3 + 5.5)\n");
	scanf("%f %c %f", &a, &op, &b);
	switch(op){
	 case '+': result = plus(a,b);
		printf("%.2f + %.2f = %.2f\n", a, b, result); break;
	 case '-': result = minus(a,b);printf("%.2f - %.2f = %.2f\n", a, b, result); break;
	 case '*': result = gob(a,b);printf("%.2f * %.2f = %.2f\n", a, b, result); break;
	 case '/': WWW(a,b); break;
	 default: printf("Invalid operator\n");

	return 0;
}
}
float plus(float a, float b)
{
	float c;
	c = a + b;
	return c;
}
float minus(float a, float b)
{
	float c;
	c = a - b;
	return c;
}
float gob(float a, float b)
{
	float c;
	c = a * b;
	return c;
}
void WWW(float a, float b)
{
	float c;
	int d;
	switch((int)b){
	 case 0: printf("%.2f / 0\nDivision by zero\n", a);break;
	 default: c = a / b; printf("%.2f / %.2f = %.2f\n", a, b, c);
}
}
