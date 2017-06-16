#include <stdio.h>

int add(int x, int y)
{
	int sum,carry;
	if(0==y)
	{
		return x;
	}
	
	sum = x^y;
	carry = (x&y)<<1;

	return add(sum,carry);
}

int subtraction(int x, int y)
{
	y = ~y+1;
	return add(x,y);
}

int divide(int x, int y)
{
	int result;
	int MAX_INT = 0x7fffffff;
	
	result = 0;
	while(x>=y)
	{
		x = subtraction(x,y);
		result += add(0,1);		
	}
	
	return result;
}

void main()
{
	int result;
	int x, y;
	x=4;
	y=2;
	result = divide(x,y);

	printf("%d", result);
}
