#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	char a[16];
	char b[16];
	char c[31];
	int sizea, sizeb, sizec;

	scanf("%s", a);
	scanf("%s", b);

	
	strcat(c, a);
	strcat(c, b);
	int count;
	int temp = 0;
	count = strlen(c);
	for(int i = 0; i < count - 1; i++)
	{
		for(int j = 0; j < count - 1; j++)
		{
			if(c[j] > c[j+1])
			{
				temp = c[j];
				c[j] = c[j + 1];
				c[j + 1] = temp;
			}
		}
	}
	printf("%s\n", c);
	return 0;
}



