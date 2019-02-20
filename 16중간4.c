#include <stdio.h>

char key, c1, c2, c3;
void encryption_func(char *c1, char*c2, char*c3);
int main()
{
	printf("Input key : ");
	scanf("%c", &key);
	printf("Input three characters : ");
	scanf("\n%c%c%c", &c1, &c2, &c3);

	encryption_func(&c1, &c2, &c3);
}
void encryption_func(char *c1, char*c2, char*c3)
{
	*c1 = *c1 + (key - 96);
	*c2 = *c2 + (key - 96);
	*c3 = *c3 + (key - 96);
	if (*c1 >= 123)
		*c1 = *c1 - 26;
	if (*c2 >= 123)
		*c2 = *c2 - 26;
	if (*c3 >= 123)
		*c3 = *c3 - 26;
	printf("Encryption result is %1c %1c %1c.\n", *c1, *c2, *c3);
}
