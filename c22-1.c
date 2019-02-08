#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int count;
	struct node* top;
}STACK;

typedef struct node {
	char data;
	struct node* link;
}STACK_NODE;

void push(STACK* pStack, char ch) {
	STACK_NODE* new;
	new = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	new->data = ch;
	new->link = NULL;
	if(empty(pStack) == 1)
	{
		pStack->top = new;
	}
	else
	{
		new->link = pStack->top;
		pStack->top = new;
		pStack->count++;
	}
}

int pop(STACK* pStack, char* ch) {
	int result;
	STACK_NODE* dlt;
	if(empty(pStack) == 1)
	{
		result = 0;
		return result;
	}
	else
	{
		*ch = pStack->top->data;
		dlt = pStack->top;
		pStack->top = pStack->top->link;
		pStack->count--;
		free(dlt);
		result = 1;
		return result;
	}
}

int empty(STACK* pStack) {
	if(pStack->top == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int solve(const char* str) {
	STACK* pStack = (STACK*)calloc(1, sizeof(STACK));
	pStack->top = NULL;
	pStack->count = 0;
	char ch = 0;
	for (int i = 0; str[i]; i++) {
		if (str[i] == '(') {
			push(pStack, str[i]);
		}
		else {
			if (empty(pStack)) {
				free(pStack);
				return 0;
			}
			pop(pStack, &ch);
		}
	}
	int ans = empty(pStack);
	
    //free all nodes in pStack
	STACK_NODE* del = pStack->top;
    STACK_NODE* temp = NULL;
	while (del) {
		temp = del;
		del = del->link;
		free(temp);
	}
	free(pStack);
	return ans;
}

int main(void) {
	int T;
	char str[101];

	scanf("%d", &T);
	getchar();

    while (T--) {
		scanf("%s", str);
		if (solve(str))
			printf("YES\n");
		else
			printf("NO\n");
	}
	
    return 0;
}
