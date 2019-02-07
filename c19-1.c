#include <stdio.h>

typedef struct _STAMP
{
	char letter;
	struct _STAMP* next;
} STAMP;

int main()
{
	STAMP s1, s2, s3;
	s1.next = &s2;
	s2.next = &s3;
	s3.next = &s1;
	
	int dist;
	printf("Travel distance (cm): ");
	scanf("%d", &dist);
	getchar();
	printf("Enter 3 letters for the stamps: ");
	scanf("%c", &s1.letter);

	scanf("%c", &s2.letter);

	scanf("%c", &s3.letter);
	


	STAMP* current = &s1;
	int i = 0;

	for(i = 0; i < dist + 1; i++)
	{
		printf("%c ", current->letter);
		current = current->next;
	}

	printf("\n");
	return 0;
}
