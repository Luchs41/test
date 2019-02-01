#include <stdio.h>

int main(void)
{
	char str[100];
	
	int i = 0;
	int count = 0;

	printf("Enter a string : ");
	fgets(str, sizeof(str), stdin);
	
	while(str[i] == ' ')
	{
		i++;
	}


	while(str[i] != '\n')
	{
		if(str[i] != ' ')
		{
			i++;
		}
		if(str[i] == ' ')
		{
			if((str[i - 1] == ' ' && str[i] == ' ') || str[i - 1] == ' ' && str[i] == '\n')
			{
				i++;
			}
			else if((str[i - 1] != ' ' && str[i] == ' ') || (str[i - 1] != ' ' && str[i] == '\n'))
			{
				count++;
				i++;
			}
		}
	}

		printf("%d\n", count + 1);
	
	return 0;
}
