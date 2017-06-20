#include <stdio.h>
#include <stdlib.h>

int newDiv(int a, int b)
{
	int isPos;
	int digits;
	long long x,y,tmp,p;
	isPos = 0;			//其值为1表示为正，0为负
	int res;
	
	x = (long long)a;
	y = (long long)b;
	
	if((x<0 && y<0) || (x>0 && y>0))
	{
		isPos = 1;
	}
	
	x = abs(x);
	y = abs(y);

	res = 0;	
	while(x>=y)
	{
		tmp = y;
		p = 1;
		while(x>(tmp<<1))
		{
			tmp <<= 1;
			p <<= 1;	
		}
		res += p;
		x -= tmp;
	}
	
	return res;
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
		result = newDiv(x,y);
	}

	return result;
}

void main()
{
	int result;
	int x, y;
	x=0x80000000;
	y=-1;
	result = divide(x,y);

	printf("%d", result);
}
