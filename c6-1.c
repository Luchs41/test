#include <stdio.h>
#include <stdlib.h>

int *get_new_array(int size)
{
	return (int*)malloc(size*sizeof(int));
}
//크기가 size인 int type을 할당하여 반환한다.
void get_new_array_call_by_value(int*a, int size)
{
	a = (int*)malloc(size*sizeof(int));
//함수에서 *a의 주소가 아닌 값 만을 넘겨준 후 메모리를 할당해 주었기 때문에 main함수의 a에는 적용이 되지 않았다. 
//함수에서 넘겨받은것은 a의 값인 NULL 이므로 본 함수에서는 NULL에 메모리를 할당한 것이다 -> 메모리가 제대로 할당되지 않았다.
}
//입력으로 들어온 a를 int type으로 할당한다.
void get_new_array_call_by_reference(int**a, int size)
{
	*a = (int*)malloc(size*sizeof(int));

}
//입력으로 들어온 a를 int type으로 할당한다.
void print_state(int *a)
{
	if(a == NULL)
	{
		printf("not allocated\n");
	}
	else
		printf("allocated\n");
}
//a가 NULL이면 not allocated를, 아니면 allocated를 출력한다.

int main()
{
	int*a = NULL;
	print_state(a);

	get_new_array_call_by_value(a, 10);
	print_state(a);
	free(a);

	get_new_array_call_by_reference(&a, 10);
	print_state(a);
	free(a);

	a = get_new_array(10);
	print_state(a);
	free(a);
	return 0;
}

