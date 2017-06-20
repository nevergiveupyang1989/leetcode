#include <stdio.h>
#include <stdlib.h>

int div(int x, int y)
{
	int isPos;
	int digits;
	digits = 0;
	isPos = 0;
	long res;

	if((x<0 && y<0) || (x>0 && y>0))
	{
		isPos = 1;
	}
	
	x = abs(x);
	y = abs(y);

	while(x>=y)
	{
		y <<= 1;
		digits++;
	}
	
}

int divide(int x, int y)
{
	int MIN_INT = 0x80000000;
	int MAX_INT = 0x7fffffff;
	int result;
	
	if((x==MIN_INT && y==-1) || (y==0))
	{
		result = MAX_INT;
	}
	
	else
	{
		result = div(x,y);
	}

	return result;
}

void main()
{
	int result;
	int x, y;
	x=-2147483648;
	y=-1;
	result = divide(x,y);

	printf("%d", result);
}
