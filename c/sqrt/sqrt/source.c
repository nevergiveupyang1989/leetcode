#include <stdio.h>
#include <stdlib.h>
#define MAX 46340      

int mySqrt(int x)
{
	int mid;
	int low;
	int high;
	
	low = 0;
	high = x;
	
	mid = (low+high)/2;
	
	if(mid>=MAX)
	{
		high = MAX;
	}
	
	mid = (low+high)/2;
	
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
		
		mid = (low+high)/2;
	}
	
	if(mid*mid==x)
	{
		return mid;
	}	
	
	if(mid*mid>x)
	{
		mid = mid - 1;
	}

	return mid;
}

void main()
{
	int x;
	int result;
	
	x = 4;
	result = mySqrt(x);

	printf("%d", result);
}
