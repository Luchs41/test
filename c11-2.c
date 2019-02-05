#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[16];
	char str2[16];
	char str3[16];
	char str4[16];
	char str5[16];
	char* pstr[5];

	pstr[0] = str1;
	pstr[1] = str2;
	pstr[2] = str3; 
	pstr[3] = str4; 
	pstr[4] = str5;
	

	int size[5];
	char temp[16];
	char* ptr = temp;
	
	
	printf("Input 5 string\nString 1: ");
	scanf("%s", str1);
	printf("String 2: ");
	scanf("%s", str2);
	printf("String 3: ");
	scanf("%s", str3);
	printf("String 4: ");
	scanf("%s", str4);
	printf("String 5: ");
	scanf("%s", str5);

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4 - i; j++)
		{
			if(strlen(pstr[j]) > strlen(pstr[j + 1]))
			{
				  strcpy(ptr, pstr[j]);
				  strcpy(pstr[j], pstr[j + 1]);
				  strcpy(pstr[j + 1], ptr);

			}
		}
	}
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4 - i; j++)
		{
			if(strlen(pstr[j]) == strlen(pstr[j + 1]))
			{
				if(strcmp(pstr[j], pstr[j + 1]) > 0)
				{
					strcpy(ptr, pstr[j]);
					strcpy(pstr[j], pstr[j + 1]);
					strcpy(pstr[j + 1], ptr);
				}
			}
		}
	}

	
	printf("\nResult\n%s\n%s\n%s\n%s\n%s\n", pstr[0], pstr[1], pstr[2], pstr[3], pstr[4]);
	return 0;
}
