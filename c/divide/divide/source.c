#include <stdio.h>
#include <stdlib.h>

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

int numAbs(int x)
{
	int MIN_INT = 0x80000000;
	int MAX_INT = 0x7fffffff;
	
	if(MIN_INT == x)
	{
		x = MAX_INT;
	}
	else
	{
		if(x<0)
		{
			x = 0 - x;
		}
	}

	return x;
}

int divide(int x, int y)
{
	int result;
	int MAX_INT = 0x7fffffff;
	int flag = 1;			//flag==1表示其中一个数是负数
	
	if((x>=0 && y>0)||(x<0 && y<0))
	{
		flag=0;
	}
	
	x = numAbs(x);
	y = numAbs(y);
	result = 0;
	while(x>=y)
	{
		x = subtraction(x,y);
		result += add(0,1);		
	}
	
	if(1==flag)
	{
		result = 0-result;
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
