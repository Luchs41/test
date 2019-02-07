#include <stdio.h>

typedef struct
{
	struct
	{
		char Hall[3];
		int floor;
	} Where;
	struct
	{
		char menu[10];
		int num;
	} What;
} order;

int main()
{
	order order1;
	printf("Where? ");
	scanf("%s %d", order1.Where.Hall, &order1.Where.floor);
	printf("What? ");
	scanf("%s %d", order1.What.menu, &order1.What.num);


	printf("\n");
	printf("_________________________\n");
	printf("|	              	|\n");
	printf("|	I want		|\n");
	printf("|	%d %-10s	|\n", order1.What.num, order1.What.menu);
	printf("|	              	|\n");
	printf("|	Bring me on	|\n");
	printf("|	%dF, Hall %-3s	|\n", order1.Where.floor, order1.Where.Hall);
	printf("|	                |\n");
	printf("-----   -----------------\n");
	printf("    |  /                 \n");
	printf("    | /                  \n");
	printf("    |/                   \n");
	printf("\n");

	return 0;
}

