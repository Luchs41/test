#include <stdio.h>
void snail(int(*board)[20], int size);
void print_snail(int max[][20], int size);
void main(void)
{
	int size, i;
	int max[20][20];
	int (*board)[20] = max;
	
	printf("Input N : ");
	scanf("%d", &size);
	for (i = size; 0 < i; i--)
	{
		snail(board, i);
		print_snail(max, i);
		printf("\n");
	}
}
void print_snail(int max[][20], int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%3d ", max[i][j]);
		}
		printf("\n");
	}
}
void snail(int (*board)[20], int size)
{
	int i, j, num, dev, hex;
	dev = size;
	hex = 0;
	num = 1;
	while (num != size*size+1)
	{
		for (j = hex; j < dev; j++)
		{
			board[hex][j] = num;
			num++;
		}
		hex++;
		dev--;
		for (i = hex; i < dev + 1; i++)
		{
			board[i][dev] = num;
			num++;
		}
		hex--;
		for (j = dev - 1; hex - 1 < j; j--)
		{
			board[dev][j] = num;
			num++;
		}
		dev--;
		for (i = dev; hex < i; i--)
		{
			board[i][hex] = num;
			num++;
		}
		hex++;
		dev++;
	}
}
