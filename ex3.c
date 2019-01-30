#include <stdio.h>

int main(void)
{
	int jung1, jung2, mox, nameoji;
	printf("Input two integer: ");
	scanf("%d %d", &jung1,&jung2);
	mox=jung1/jung2;
	nameoji=jung1%jung2;
	printf("\n %d / %d is %d with a remainder of %d\n", jung1, jung2, mox, nameoji);
	
	return 0;
}

