#include <stdio.h>
int main()
{
	FILE *input,*output;int i=0;int order,tf;float num1,num2,res;char a,b;
	input=fopen("input32.txt","r");
	output=fopen("output32.txt","w");
	for (i=0;i<6;i++){
		fscanf(input,"%d %f %c %f %c %f",&order,&num1,&a,&num2,&b,&res);
		if (a=='+')
			{if (num1+num2==res)
				tf=1;
			else tf=0;}
		if (a=='-')
			{if (num1-num2==res)
				tf=1;
			else tf=0;}
		if (a=='*')
			{if (num1*num2==res)
				tf=1;
			else tf=0;}
		if (a=='/')
			{if (num1/num2==res)
				tf=1;
			else tf=0;}
		fprintf(output,"%d %.2f %c %.2f %c %.2f ",order,num1,a,num2,b,res);
		if (tf==1)
			fprintf(output,"correct\n");
		else	fprintf(output,"incorrect\n");
}}
