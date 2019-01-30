#include <stdio.h>

int main()
{
	int a,b,c,d,e,f;
	printf("input two: ");
	scanf("%1d%1d%1d %1d%1d%1d", &a,&b,&c,&d,&e,&f);
	int sum1 = a+d;
	int sum2 = b+e;
	int sum3 = c+f;
	
	if(sum1 >= 10 && sum2 >= 10 && sum3 >= 10)
		printf("3 carry operations\n");
	else
		if((sum1 >= 10 && sum2 < 10 && sum3 < 10) || (sum1 < 10 && sum2 >= 10 && sum3 < 10) || (sum1 < 10 && sum2 < 10 && sum3 >= 10))
		printf("1 carry operation\n");
		else
			if(sum1 < 10 && sum2 < 10 && sum3 < 10)
				printf("0 carry operations\n");
			else
				printf("2 carry operations\n");

	return 0;
}
