#include <stdio.h>
#include <stdlib.h>

long long longAbs(long long x)
{
	int MIN_INT=0x80000000;
	
	if(x==MIN_INT)
	{
		x = 2147483648;
	}
	
	else if(x<0)
	{
		x = 0-x;
	}
	
	return x;
}

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
	
	x = longAbs(x);
	y = longAbs(y);

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
	
	if(isPos==0)
	{
		res = 0 - res;
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
	
	else if(x==MIN_INT&&y==1)
	{
		result = MIN_INT;
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
	y=1;
	result = divide(x,y);

	printf("%d", result);
}
