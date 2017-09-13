#include <stdio.h>
#include <stdlib.h>

int mySqrt(int x)
{
	int mid;
	int low;
	int high;
	
	low = 0;
	high = x;
	mid = (low+high)/2;
	
	if(mid*mid==x)
	{
		return mid;
	}	
	
	while(mid*mid!=x && low < high)
	{
		if(mid*mid>x)
		{
			high = mid - 1;
		}
		
		if(mid*mid<x)
		{
			low = mid + 1;
		}
		
		if(mid*mid == x)
		{
			return mid;
		}
		mid = (low+high)/2;
	}
	
	high = high - 1;

	return high;
}

void main()
{
	int x;
	int result;
	
	x = 4;
	result = mySqrt(x);

	printf("%d", result);
}
