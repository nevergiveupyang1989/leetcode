#include <stdio.h>
#include <stdlib.h>
#define maxNum(x,y) (x)>(y)?x:y

int jumpGame(int* num, int numsSize)
{
	int i,rearch;

	if(numsSize == 0)
		return 0;
	
	rearch = 0;
	
	for(i=0; i<numsSize && i <= rearch; i++)
	{
		rearch = maxNum(i+num[i], rearch);
		
		if(rearch == numsSize - 1)
			return 1;
	}
	
	return 0;	
}

void main()
{
	int num[] = {2,3,1,1,4};
	int numsSize = 5;
	int result;	

	result = jumpGame(num, numsSize);
	
	printf("%d", result);
}
