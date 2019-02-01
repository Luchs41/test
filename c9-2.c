#include <stdio.h>

int main()
{
	int step;
	int i;
	char oristr[99];
	
	printf("Enter string without blank space: ");
	scanf("%s", oristr);
	printf("Enter step size (1~3): ");
	scanf("%d", &step);

	if(step == 1)
	{
		printf("%s\n", oristr);
	}
	if(step == 2)
	{
		int in1 = 0;
		int in2 = 0;
		char str1[99];
		char str2[99];
		char* ptr = oristr;
		for(i = 0; *ptr != '\0'; i++)
		{
			if(i % 2 == 0)
			{
				str1[in1] = *ptr;
				in1 += 1;
			}
			if(i % 2 == 1)
			{
				str2[in2] = *ptr;
				in2 += 1;
			}
			ptr++;
		}
		printf("%s\n", str1);
		printf("%s\n", str2);
	}
	if(step == 3)
	{
		int in1 = 0;
		int in2 = 0;
		int in3 = 0;
		char str1[99];
		char str2[99];
		char str3[99];
		char* ptr = oristr;
		for(i = 0; *ptr !='\0'; i++)
		{
			if(i % 3 == 0)
			{
				str1[in1] = *ptr;
				in1 += 1;
			}
			if(i % 3 == 1)
			{
				str2[in2] = *ptr;
				in2 += 1;
			}
			if(i % 3 == 2)
			{
				str3[in3] = *ptr;
				in3 += 1;
			}
			ptr++;
		}

		printf("%s\n", str1);
		printf("%s\n", str2);
		printf("%s\n", str3);
	}
	return 0;
}

