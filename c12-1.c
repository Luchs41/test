#include <stdio.h>

int main(void)
{
	char str[101];
	printf("Input string: ");
	scanf("%[^\n]s", str);

	printf("Output string: %s\n", str);

	return 0;
}
