#include <stdio.h>

int main()
{
	struct coin
	{
		int numcoin;
	};
	struct coin o500;
	struct coin o100;
	struct coin o50;
	struct coin o10;

	int money;

	printf("input money : ");
	scanf("%d", &money);
	
	o500.numcoin = money / 500;
	money = money - (500 * o500.numcoin);

	o100.numcoin = money / 100;
	money = money - (100 * o100.numcoin);

	o50.numcoin = money / 50;
	money = money - (50 * o50.numcoin);

	o10.numcoin = money / 10;
	money = money - (10 * o10.numcoin);

	printf("# of 500 = %d\n# of 100 = %d\n# of 50 = %d\n# of 10 = %d\n", o500.numcoin, o100.numcoin, o50.numcoin, o10.numcoin);

	return 0;
}

