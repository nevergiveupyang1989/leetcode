#include <stdio.h>
#include <stdlib.h>
#define MIN 0x80000000

double myPow(double x, int n)
{
	double result;

	if(0 == x)
	{
		return 0;
	}

	if(0==n || (x == -1 && n%2 == 0) || x== 1)
	{
		return 1;
	}
	
	if(n<0)
	{
		if(n == MIN)
		{
			n += 1;
		}

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
	n = -2147483648;

	result = myPow(x, n);
	
	printf("%f", result);
}
