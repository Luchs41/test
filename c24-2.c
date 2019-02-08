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
	
int DequeuePrint(QUEUE* pQueue, char* dataOut)
{
	QUEUE_NODE* temp;
	if(pQueue->count == 0)
	{
		return 0;
	}
	else
	{
		if(pQueue->count == 1)
		{
			strcpy(dataOut, pQueue->front->command);
			temp = pQueue->front;
			pQueue->front = pQueue->rear = NULL;
			free(temp);
			(pQueue->count)--;
			return 0;
		}
		else
		{
			strcpy(dataOut, pQueue->front->command);
			temp = pQueue->front;
			pQueue->front = pQueue->front->next;
			free(temp);
			(pQueue->count)--;
			return 1;
		}
		
		
	}
}
int main()
{
	int i;
	QUEUE* queue = NULL;
	queue = (QUEUE*)malloc(sizeof(QUEUE));
	queue->count = 0;
	int Return = 1;
	char dataOut[10];
	char input[10];
	while(1)
	{
		for(i = 0; i < 10; i++)
		{
			input[i] = '\0';
			dataOut[i] = '\0';
		}
		printf(">>");
		scanf("%s", input);
		if(strcmp(input, "q") == 0 || strcmp(input, "quit") == 0)
		{
			break;
		}
		else if(strcmp(input, "h") == 0 || strcmp(input, "history") == 0)
		{
			while(1)
			{
				if(queue->count == 1)
				{
					Return = DequeuePrint(queue, dataOut);
					printf("%s\n", dataOut);
				}
				else
				{
					Return = DequeuePrint(queue, dataOut);
					if(Return == 0)
					{
						break;
					}
					printf("%s\n", dataOut);
				}
			}
		}
		else if(strcmp(input, "help") == 0 || strcmp(input, "dir") == 0 || strcmp(input, "mkdir") == 0 || strcmp(input, "cd") == 0)
		{
			printf("[Valid] %s\n", input);
			enqueue(queue, input);
		}
		else
		{
			printf("[Invalid]\n");
		}

	}
	return 0;

}
