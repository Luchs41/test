#include <stdio.h>
int total_cost(float price, float tax, float discount);
int main() {
	float total,price,tax,dis;
	printf("Enter the price: ");
	scanf("%f", &price);
	printf("Enter the tax rate as a percentage: ");
	scanf("%f", &tax);
	printf("Enter the discount as a percentage: ");
	scanf("%f", &dis);
	total = total_cost(price, tax, dis);
	

	printf("-------------------------------------------\nTotal cost : %.0f\n", total);
}

int total_cost(float price, float tax, float discount)
{
	float total;
	int a,b,c,d;
	discount = discount / 100;
	tax = tax / 100;
	total = (price * (1 - discount))*(1 + tax);

	a = ((int)total / 10000) * 10000;
	b = (((int)total - a) / 1000) * 1000;
	c = (((int)total-a-b) / 100) * 100;
	d = (((int)total-a-b-c) / 10) * 10;

	if ((int)total - a - b - c - d >= 5)
			total = total - ((int)total - a - b - c - d) + 10;
	

	return total;
}