#include <stdio.h>
#include <math.h>

int main(void)
{
	float a,b,dint,ddec;
	a=5.125;
	b=-1.25;
	dint = modff(a,&ddec);
	printf("the dint is %f\n",dint);
	printf("the ddec is %f\n",ddec);

	dint = modff(b,&ddec);
	printf("the dint is %f\n",dint);
	printf("the ddec is %f\n",ddec);

	return 0;
}
