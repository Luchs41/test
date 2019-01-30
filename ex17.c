#include <stdio.h>
float avgFunc(float a, float b, float c);
void gradeFunc(float avg);

int main()
{
	float a, b, c;
	float avg;
	printf("Input: ");
	scanf("%f %f %f", &a, &b, &c);
	avg = avgFunc(a,b,c);
	gradeFunc(avg);
	
	return 0;
}
float avgFunc(float a, float b, float c)
{
	float avg;
	avg = (a + b + c)/3;
	return avg;
}
void gradeFunc(float avg)
{
	if(avg >= 50)
		{if(avg < 70)
			printf("Grade: D\n");
		}

	if(avg >= 70)
		{if(avg < 80)
			printf("Grade: C\n");
		}

	if(avg >= 80)
		{if(avg < 90)
			printf("Grade: B\n");
		}
	{if(avg >= 90)
		printf("Grade: A\n");
	}
	{if(avg < 50)
		printf("Grade: F\n");
	}

}
