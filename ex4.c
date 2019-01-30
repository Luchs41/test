#include <stdio.h>
int main(void)
{
	int price;
	float pay1, pay2;
	float dap1, dap2;
	int mon1, mon2;

	mon1 = 3;
	mon2 = 6;
	printf("Price : ");
	scanf("%d", &price);
	pay1 = price;
	pay2 = price*1.157625;
	dap1 = pay1/3;
	dap2 = pay2/6;
	printf("\n-----------------------output---------------------");
	printf("\nMonth		:	%10d	%10d\n",mon1, mon2);
	printf("Payment		:	%10.0f	%10.0f", pay1, pay2);
	printf("\n--------------------------------------------------");
	printf("\nPay/month	:	%10.2f	%10.2f\n", dap1, dap2);

	return 0;
}
	
