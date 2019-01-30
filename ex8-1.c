#include <stdio.h>

float aver(float, float, float, float);
float pyeon(float, float);

int main(void)
{
	float a, b, c, d;
	float vud,vusa,vusb,vusc,vusd;

	printf("Enter the first number : ");
	scanf("%f", &a);
	printf("Enter the second number : ");
	scanf("%f", &b);
	printf("Enter the third number : ");
	scanf("%f", &c);
	printf("Enter the fourth number : ");
	scanf("%f", &d);
	
	vud = aver(a,b,c,d);
	vusa = pyeon(a,vud);
	vusb = pyeon(b,vud);
	vusc = pyeon(c,vud);
	vusd = pyeon(d,vud);

	printf("******** average is %.2f ********", vud);
	printf("\nfirst number :\t\t%10.0f -- deviation :\t\t%10.2f", a, vusa);
	printf("\nsecond number :\t\t%10.0f -- deviation :\t\t%10.2f", b, vusb);
	printf("\nthird number :\t\t%10.0f -- deviation :\t\t%10.2f", c, vusc);
	printf("\nfourth number :\t\t%10.0f -- deviation : \t\t%10.2f\n", d, vusd);

	return 0;
}

float aver(float a, float b, float c, float d)
{
	float vud;
	vud = (a + b + c + d)/4;
	return vud;
}

float pyeon(float gabs, float vud)
{
	float vus = gabs - vud;
	return vus;
}
