#include <stdio.h>
double user_define(char[]);
double exp(int num);
int main(void)
{
	char num[12] = { 0 };
	int i;
	for (i = 0; i < 12; i++)
	{
		scanf("%c", &num[i]);
		if (num[i] == '\n')
			break;
	}
	printf("Result : %.6lf\n", user_define(num));
	for(i=0;i<12;i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
}
double exp(int num)
{
	int i;
	double tmp;
	tmp = 1;
	if (num > 0)
	{
		for (i = 0; i < num; i++)
			tmp *= 10;
	}
	else if (num < 0)
	{
		for (i = 0; num < i; i--)
			tmp /= 10;
	}
	else
		return tmp;
	return tmp;
}
double user_define(char num[])
{
	int i;
	double tmp;
	int point, buh, chk;
	buh = 0;
	tmp = 0;
	chk = 0;
	if (num[0] == '-')
		buh = 1;
	for (i = buh; i < 12; i++)
	{
		if (num[i] == '.')
		{
			point = i;
			chk++;
		}
	}
	if (chk == 0)
	{
		for (i = buh; i < 12; i++)
			if (num[i] == '\n')
				point = i-1;
	}
	for (i = buh; i < point; i++)
	{
		if (num[i] == '\n')
			break;
		tmp += (num[i]-'0')* exp(point - i-1);
	}
	for (i = point + 1; i < 12; i++)
	{
		if (num[i] == '\n')
			break;
		tmp += (num[i]-'0') * exp(point - i);

	}
	if (buh == 1)
		return -tmp;
	else
		return tmp;
}
