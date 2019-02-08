#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char command[10];
	struct node* next;
}QUEUE_NODE;

typedef struct
{
	QUEUE_NODE* front;
	int count;
	QUEUE_NODE* rear;
}QUEUE;

void enqueue(QUEUE* queue, char* data)
{
	QUEUE_NODE* new;
	new = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
	strcpy(new->command, data);
	if(queue->count == 0)
	{
		queue->front = new;
	}
	else
	{
		queue->rear->next = new;
	}
		queue->rear = new;
		(queue->count)++;
}
void printQueue(QUEUE* queue)
{
	QUEUE_NODE* temp = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
	temp = queue->front;
	printf("queue count : %d\n", queue->count);
		
		while(temp)
		{
			printf("%s\n", temp->command);
			temp = temp->next;
		}
}
	

int main()
{
	int i;
	QUEUE* queue = NULL;
	queue = (QUEUE*)malloc(sizeof(QUEUE));
	queue->count = 0;
	queue->front = NULL; //꼭 해주기
	queue->rear = NULL;

	char input[10];
	while(1)
	{
		for(i = 0; i < 10; i++)
		{
			input[i] = '\0';
		}
		printf("Enter a command : ");
		scanf("%s", input);
		if(strcmp(input, "q") == 0 || strcmp(input, "quit") == 0)
		{
			break;
		}
		else if(strcmp(input, "h") == 0 || strcmp(input, "history") == 0)
		{
			printQueue(queue);
		}
		else if(strcmp(input, "help") == 0 || strcmp(input, "dir") == 0 || strcmp(input, "mkdir") == 0 || strcmp(input, "cd") == 0)
		{
			enqueue(queue, input);
		}
		else
		{
			printf("[%s] is invalid command!!\n", input);
		}

	}
	return 0;

}
