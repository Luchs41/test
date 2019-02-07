#include <stdio.h>
#include <stdlib.h>


enum Sex{male = 0, female};

typedef struct
{
	struct
	{
		float mid;
		float fin;
		float proj;
	} Points;
	char name[40];
	int studentid;
	char grade[3];
	float total_score;
	enum Sex sex;
} Grades;


int main()
{
	int temp;
	int* rank;
	int num, i, j;
	FILE* txt;
	int* a;
	txt = fopen("input[13].txt", "r");
	
	fscanf(txt, "%d", &num);
	Grades* grades;
	grades = (Grades*) malloc(sizeof(Grades) * num);
	a = (int*) malloc(sizeof(int) * num);

	for(i = 0; i < num; i++)
	{
		rank[i] = i;
	}

	for(i = 0; i < num; i++)
	{
		a[i] = i;
		fscanf(txt, "%d", &grades[i].studentid);
		fscanf(txt, "%s", grades[i].name);
		fscanf(txt, "%d", &grades[i].sex);
		fscanf(txt, "%f", &grades[i].Points.mid);
		fscanf(txt, "%f", &grades[i].Points.fin);
		fscanf(txt, "%f", &grades[i].Points.proj);
	}
	fclose(txt);

	for(i = 0; i < num; i++)
	{
		grades[i].total_score = grades[i].Points.mid * 0.3 + grades[i].Points.fin * 0.3 + grades[i].Points.proj * 0.4;
	}

	
	for(i = 0; i < num - 1; i++)
	{
		for(j = 0; j < num - 1 - i; j++)
		{
			if(grades[a[j]].total_score < grades[a[j + 1]].total_score)
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	
	for(i = 0; i < num; i++)
	{
		if(grades[a[i]].total_score < 50)
		{
			grades[a[i]].grade[0] = 'F';
			continue;
		}
		if(i < 0.3 * num || i == 0.3 * num)
		{
			grades[a[i]].grade[0] = 'A';
		}
		else if(i < 0.7 * num || i == 0.7 * num)
		{
			grades[a[i]].grade[0] = 'B';
		}
		else
		{
			grades[a[i]].grade[0] = 'C';
		}
	}
	printf("-- Student List --\n\n");
	for(i = 0; i < num; i++)
	{
		printf("Id : %d\n", grades[a[i]].studentid);
		printf("Name : %s ", grades[a[i]].name);
		if(grades[a[i]].sex == male)
		{
			printf("(Male)\n");
		}
		else
		{
			printf("(Female)\n");
		}
		printf("Grade(mid) : %f\n", grades[a[i]].Points.mid);
		printf("Grade(final) : %f\n", grades[a[i]].Points.fin);
		printf("Grade(project) : %f\n", grades[a[i]].Points.proj);
		printf("Grade : %c (%.2f %d)\n\n", grades[a[i]].grade[0], grades[a[i]].total_score, i + 1);
	}
	return 0;
}
