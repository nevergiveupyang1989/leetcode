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

void main()
{
	int x,y;
	int sum,dValue;
	x=2;
	y=1;
		
	sum = add(x,y);
	dValue = subtraction(x,y);
	printf("%d %d", sum ,dValue);
}
