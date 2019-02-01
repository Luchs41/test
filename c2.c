#include <stdio.h>
#include <math.h>

void function(double *pa, double *pb, double *pc, double *pd);
int main()
{
	double a,b,c,d;
	double *pa,*pb,*pc,*pd;
	printf("Input a, b, c, d: ");
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	pa = &a;
	pb = &b;
	pc = &c;
	pd = &d;
	function(pa, pb, pc, pd);

	return 0;
}
void function(double *pa, double *pb, double *pc, double *pd)
{
	double dis, result;
	dis = (pa - pc)*(pa - pc) + (pb - pd)*(pb - pd);
	result = sqrt(dis);
	printf("%.4lf \n", result);
}
	
