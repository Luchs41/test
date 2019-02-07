#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int arr[10];
	char str[20];
	float f_arr[10];
}_struct;

typedef union
{
	int arr[9];
	double d_arr[5];
	char str[39];
}_union;

int main()
{
	_struct a;
	_union b;
	printf("sizeof(_struct)\t: %ld, size_s = %ld\n", sizeof(_struct), sizeof(a.f_arr) + sizeof(a.arr) + sizeof(a.str));
	printf("sizeof(_union)\t: %ld, size_u = %ld\n", sizeof(_union), sizeof(b.d_arr));

	return 0;
}
