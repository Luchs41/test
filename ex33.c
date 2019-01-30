#include <stdio.h>

int main(){
	FILE *student,*output;int scan;char name[6];float totalavg,sum,i,score1,score2;
	student=fopen("student.txt","r");i=0;sum=0;
	output=fopen("output33.txt","w");
	while (1){
		scan=fscanf(student,"%s %f %f",name,&score1,&score2);
		if (scan==EOF)
			break;
		sum+=score1;sum+=score2;i+=1;}
	totalavg=sum/i/2;
	student=fopen("student.txt","r");
	fprintf(output,"student \t average \tgrade\n");
	while(1){
		scan=fscanf(student,"%s %f %f",name,&score1,&score2);
		if (scan==EOF)
			break;
		float avg=(score1+score2)/2;
		fprintf(output,"%s \t\t %.2f \t\t",name,avg);
		if (avg>totalavg)
			fprintf(output,"p\n");
		else fprintf(output,"f\n");}
	fprintf(output,"total average : %.2f\n",totalavg);}
