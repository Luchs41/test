#include <stdio.h>
int main(){
	FILE *first,*second,*output;
	int res=0,len=0,i,k;
	char char1[100000], char2[100000], ch1, ch2, name1[100000], name2[100000];
	printf("Input first file name: ");for(i=0;i<100000;i++)
						{scanf("%c",&name1[i]);
						if(name1[i]=='\n')
							{name1[i]='\0';break;}}
	printf("Input second file name: ");for(i=0;i<100000;i++)
						{scanf("%c",&name2[i]);
						if(name2[i]=='\n')
							{name2[i]='\0';break;}}
	first=fopen (name1,"r");for(i=0;i<100000;i++)fscanf(first,"%c",&char1[i]);
	second=fopen (name2,"r");for(i=0;i<100000;i++)fscanf(second,"%c",&char2[i]);
	output=fopen ("output.txt","w");
	for (i=0;i<100000;i++){
		ch1=char1[i];ch2=char2[i];
		if (ch1=='\0'  || ch2=='\0')
			break;
		if (ch1==' ' || ch1=='\n')
			len-=1;
		if (ch2==' ' || ch2=='\n')
			len-=1;	
		if ((ch1==' ' || ch1=='\n')&&(ch2==' ' || ch2=='\n'))
			len+=1;
		if (ch1==' ' && ch2==' ')
			res-=1;
		if (ch1=='\n' && ch2=='\n')
			res-=1;
		if (ch1==ch2)
			res+=1;
		len+=1;}
	fprintf(output,"Total character: %d\n",len);
	fprintf(output,"Same character: %d\n",res);
	res=(float)res;len=(float)len;
	fprintf(output,"%.3f%%\n",res*100.0/len);
	}
