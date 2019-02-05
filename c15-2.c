#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	int x;
	int y;
} point;

int main()
{
	point house;
	point* s1;
	point* s2;
	point* s3;

	s1 = (point*) malloc(sizeof(point));
	s2 = (point*) malloc(sizeof(point));
	s3 = (point*) malloc(sizeof(point));

	printf("house (x y) : ");
	scanf("%d %d", &house.x, &house.y);

	printf("s1 (x y) : ");
	scanf("%d %d", &(s1->x), &(s1->y));

	printf("s2 (x y) : ");
	scanf("%d %d", &(s2->x), &(s2->y));

	printf("s3 (x y) : ");
	scanf("%d %d", &(s3->x), &(s3->y));

	float dis1, dis2, dis3;
	
	dis1 = sqrt(((s1->x) - (house.x)) * ((s1->x) - (house.x)) +  + ((s1->y) - (house.y)) * ((s1->y) - (house.y)));
	dis2 = sqrt(((s2->x) - (house.x)) * ((s2->x) - (house.x)) +  + ((s2->y) - (house.y)) * ((s2->y) - (house.y)));
	dis3 = sqrt(((s3->x) - (house.x)) * ((s3->x) - (house.x)) +  + ((s3->y) - (house.y)) * ((s3->y) - (house.y)));

	if(dis1 < dis2 && dis1 < dis3)
	{
		printf("1 %.6lf\n", dis1);
	}
	else if(dis2 < dis1 && dis2 < dis3)
	{
		printf("2 %.6lf\n", dis2);
	}
	else if(dis3 < dis1 && dis3 < dis2)
	{
		printf("3 %.6lf\n", dis3);
	}
	
	return 0;
}
