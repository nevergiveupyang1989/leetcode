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

int multiplication(int x, int y)
{
	int result;
	int i;
	int cnt;
	int mod;
	
	result=0;
	cnt = x>>1;
	mod = x&1;//求模
	for(i=0; i<cnt; i++)
	{
		result += add(y,y);
	}
	
	if(mod == 1)
		result += y;
	return result;
}

void main()
{
	int x,y;
	int result;
	x=443;
	y=3;
	result = multiplication(x,y);	
	printf("%d", result);
}
