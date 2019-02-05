#include <stdio.h>

int main(void)
{
	int N;
	int cnt[26] = {0};
	char str[1000];
	FILE* fp;

	char ch;
	char* txt;
	printf("Input Number : ");
	scanf("%d", &N);
	
	for(int i = 1; i <= N; i++)
	{
		sprintf(str,"input%d.txt",i);
		fp = fopen(str,"r");
		if(fp == NULL)
		{
			printf("File open error!\n");
			continue;
		}

		while(1)
		{
			*str = fscanf(fp, "%c", &ch);
			if(*str == EOF)
			{
				break;
			}

			if(ch >= 'A' && ch <= 'Z')
			{
				cnt[ch - 'A']++;
			}
			if(ch >= 'a' && ch <= 'z')
			{
				cnt[ch - 'a']++;
			}

		}
			fclose(fp);
	}

	for(int j = 0; j < 26; j++)
	{
		printf("The number of %c is %d\n", 'a' + j, cnt[j]);
	}
		

}
