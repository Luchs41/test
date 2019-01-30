#include <stdio.h>
int biToDec(char binary[]);
int check(char binary[]);
int main(void)
{
	char binary[100];
	printf("Enter binary number : ");
	scanf("%s", binary);
	
	int fp = check(binary);
	if(fp == 0)
		printf("Invalid binary number\n");
	else
	{
		printf("Decimal number : %d\n", biToDec(binary));
	}
	return 0;
	
}

int check(char binary[])
{
	int i, x;
	for(i = 0; i < 100; i++)
	{
		if(binary[i] == '\0')
		{
			x = 1;
			break;
		}
		if((int)binary[i] != '0' && (int)binary[i] != '1')
		{
			x = 0;
			break;
		}
	}
	
	return x;
}

int biToDec(char binary[])
{
	int i=0, end=0, k, a=1, b=0;
	char s;
	while(1)
	{
		s = binary[i];
		if(a == '\0')
		{
			break;
		}
		i++;
		end++;
	}
	for(i = 0; k < end - i - 1; k++)
	{
		for(k = 0; k < end - i - 1; k++)
		{
			a = a * (int)(binary[i]-48) * 2;
		}
		b = b + a;
		a = 1;
	}
	b = b + (int)(binary[end - 1] - 48);

	return b;
}
