#include <stdio.h>
#include <stdlib.h>

int abs(int number)
{
	if(number<0)
		number = 0-number;
	return number;
}

int divide(int dividend, int divisor)
{
	int result;
	int MAX_INT=0x7fffffff;
	int flag;
	
	flag=0;
	if(divisor==0)
	{
		return MAX_INT;
	}
	
	result=0;
	
	if( (dividend<0&&divisor>0) ||(dividend>0&&divisor<0) )
	{
		flag = 1;
	}	
	
	dividend = abs(dividend);
	divisor = abs(divisor);

	while(dividend>=divisor)
	{
		dividend -= divisor;
		result++;
	}
	
	if(flag==1)
		result = 0-result;

	return result;
}

void main()
{
	int dividend;
	int divisor;
	int result;
	
	dividend = -2;
	divisor = 3;
	result = divide(dividend, divisor);

	printf("%d", result);
}
