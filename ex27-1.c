#include <stdio.h>
int main()
{
	int x[5], y[5];
	scanf("%d %d %d %d %d", &x[0], &x[1], &x[2], &x[3], &x[4]);
	scanf("%d %d %d %d %d", &y[0], &y[1], &y[2], &y[3], &y[4]);
	if(x[0]==y[0]&&x[1]==y[1]&&x[2]==y[2]&&x[3]==y[3]&&x[4]==y[4])
	printf("true\n");
	else
	printf("false\n");

	return 0;
}
