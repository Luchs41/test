#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
	char Data;
	struct _NODE *LINK;
} NODE;

NODE *head = NULL;

void InsertNodeAtFront(char a)
{
	NODE* new;
	new = (NODE*)malloc(sizeof(NODE));
	new->Data = a;
	new->LINK = NULL;
	if(head == NULL)
	{
		head = new;
	}
	else
	{
		new->LINK = head;
		head = new;
	}
}

void InsertNodeAtBack(char b)
{
	NODE* new;
	new = (NODE*)malloc(sizeof(NODE));
	new->Data = b;
	new->LINK = NULL;
	NODE* pre;
	pre = head;
	if(head == NULL)
	{
		head = new;
	}
	else
	{
		while(1)
		{
			if(pre->LINK == NULL)
			{
				pre->LINK = new;
				break;
			}
			pre = pre->LINK;
		}
	}
}

void PrintList()
{
	NODE* list;
	list = head;

	while(list != NULL)
	{
		printf("%c", list->Data);
		list = list->LINK;
	}
	printf("\n");
}

void DeleteNodeAtFront()
{
	if(head == NULL)
	{
		printf("Error!\n");
	}
	else
	{
		head = head->LINK;
	}
}

void DeleteNodeAtBack()
{
	NODE* last;
	last = head;
	while(last->LINK->LINK != NULL)
	{
		last = last->LINK;
	}
	last->LINK = NULL;
}

void main()
{
	InsertNodeAtFront('p');
	InsertNodeAtFront('p');
	InsertNodeAtFront('a');
	InsertNodeAtBack('l');
	InsertNodeAtBack('e');
	PrintList();
	head = NULL;
	InsertNodeAtFront('n');
	InsertNodeAtFront('e');
	InsertNodeAtFront('p');
	InsertNodeAtBack('l');
	InsertNodeAtFront('o');
	InsertNodeAtBack('a');
	InsertNodeAtBack('b');
	PrintList();
	DeleteNodeAtFront();
	DeleteNodeAtBack();
	DeleteNodeAtBack();
	DeleteNodeAtBack();
	
	PrintList();
	
}




