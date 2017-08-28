#include <stdio.h>
#include <stdlib.h>

double myPow(double x, int n)
{
	double result;

	if(0==n)
	{
		return 1;
	}
	
	if(n<0)
	{
		n = 0-n;
		x = 1/x;
	}
	
	result = (n%2==0)?myPow(x*x, n/2):(x*myPow(x*x, n/2));	
}

void main()
{
	double result;
	double x;
	int n;
	
	x = 3;
	n = -2;

	result = myPow(x, n);
	
	printf("%f", result);
}
