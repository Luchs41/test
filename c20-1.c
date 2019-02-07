#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE
{
	int height;
	struct _NODE* link;
}NODE;

NODE* insertNode(NODE* pList, int height);

void printAll(NODE* pList);



int main()
{
	NODE* head;
	head = NULL;

	int input;
	int stnum;

	printf("Enter the number of students : ");
	scanf("%d", &stnum);

	for(int i = 0; i < stnum; i++)
	{
		scanf("%d", &input);
		head = insertNode(head, input);
	}
	printAll(head);

	return 0;

}

NODE* insertNode(NODE* pList, int height)
{
	NODE* pPre;
	NODE* pNext;
	pPre = malloc(sizeof(NODE));
	pPre = pList;
	pNext = malloc(sizeof(NODE));
	pNext = pList;
	
	NODE* pNew;
	pNew = malloc(sizeof(NODE));
	pNew->link = NULL;
	pNew->height = height;
	

	if(pList == NULL)
	{
		pList = pNew;
	}
	else
	{
		if(height < pList->height)
		{
			pNew->link = pList;
			pList = pNew;
		}
		else
		{
			pPre = pList;
			pNext = pList;
			while(pNext != NULL)
			{
				if(pNext->height > height)
				{
					break;
				}
				pPre = pNext;
				pNext = pNext->link;
			}
			pPre->link = pNew;
			pNew->link = pNext;
		}
	}
	return pList;
}

void printAll(NODE* pList)
{
	while(pList != NULL)
	{
		printf("%d ", pList->height);
		pList = pList->link;
	}
	printf("\n");
}


