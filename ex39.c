#include <stdio.h>
int main(void)
{
	FILE * text = fopen("input_39.txt", "r");
	char arr[100000] = {0};
	int alphabet[26] = {0};
	int scan, i;
	while(1)
	{
		for(i = 0; i < 100000; i++)
		{
			scan = fscanf(text, "%c", &arr[i]);
			if(scan == EOF)
				break;
		}
		for(i = 0; i < 100000; i++)
		{
			if((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z'))
			{
				if(arr[i] >= 'A' && arr[i] <= 'Z')
				{
					alphabet[arr[i] - 'A'] += 1;
				}
				else if(arr[i] >= 'a' && arr[i] <= 'z')
				{
					alphabet[arr[i] - 'a'] += 1;
				}
			}
		}
		if(scan == EOF) break;
	}
	for(i = 0; i < 25; i++)
	{
		printf("%c : %d ", i+'A', alphabet[i]);
		if(i == 7 || i == 14)
			printf("\n");
	}
	printf("\n");
	return 0;
}
