#include <stdio.h>
int main()
{
	int cut, num;
	int o, temp;
	int fail, a;
	float sum,aver;
	o = 0;
	sum = 0;
	fail = 0;
	printf("Number of class: ");
	scanf("%d", &num);
	printf("Cutline: ");
	scanf("%d", &cut);
	temp = num;	
	while(temp > 0)
	{
		
		printf("Input score #%d: ", o);
		scanf("%d", &a);
		temp = temp - 1;
		o = o + 1;
		sum = sum + a;
		if(a < cut)
			fail = fail + 1;
	}

	aver = sum / num;
	printf("Average score: %.2f\n", aver);
	printf("Number of failures: %d\n", fail);
	return 0;
}
