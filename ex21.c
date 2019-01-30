#include <stdio.h>

int main()
{
	int line,b,c,d=1,e;

	printf("Input :");
	scanf("%d", &line);
	
	while(line > 0)
	{
		b = line - 1;
		while(b > 0)
		{
			printf(" ");
			b--;
		}
		e = 1;
		while(e <= d)
		{
			printf("*");
			e++;
		}
		d = d + 2;
		
		c = line - 1;
		while(b < 0 && c > 0);
		{
			printf(" \n");
			c--;
		}
		line--;
	}
	return 0;
}
