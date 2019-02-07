#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union{
	int i;
	float f;
	double d;
} utemp;

typedef struct
{
	int type;
	char name[10];
	union{
		int i;
		float f;
		double d;
	} u;
} stemp;

void power(stemp* s)
{
	
	switch((*s).type)
	{
		case 1:
			(*s).u.i = (*s).u.i * (*s).u.i;
			break;
		case 2:
			(*s).u.f = (*s).u.f * (*s).u.f;
			break;
		case 3:
			(*s).u.d = (*s).u.d * (*s).u.d;
			break;
	}
}
int main()
{
	stemp* s;
	int n, i;
	printf("Number of Iterations : ");
	scanf("%d", &n);
	s = (stemp*) malloc(sizeof(stemp) * n);
	for(i = 0; i < n; i++)
	{
		printf("Type [1 for int, 2 for float, 3 for double] : ");
		scanf("%d", &s[i].type);	
		switch(s[i].type)
		{
			case 1:
				printf("Enter an integer value : ");
				scanf("%d", &s[i].u.i);
				strcpy(s[i].name, "integer");
				break;
			case 2:
				printf("Enter a float value : ");
				scanf("%f", &s[i].u.f);
				strcpy(s[i].name, "float");
				break;
			case 3:
				printf("Enter a double value : ");
				scanf("%lf", &s[i].u.d);
				strcpy(s[i].name, "double");
				break;
		}
		power(&s[i]);
	}

	

	printf("----------Result----------\n");
	for(i = 0; i < n; i++)
	{
		switch(s[i].type)
		{
			case 1:
				printf("%-10s : %d\n", s[i].name, s[i].u.i);
				break;
			case 2:
				printf("%-10s : %.4f\n", s[i].name, s[i].u.f);
				break;
			case 3:
				printf("%-10s : %.4lf\n", s[i].name, s[i].u.d);
		}
	}
	return 0;
}
