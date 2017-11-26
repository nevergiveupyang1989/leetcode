#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortColors(int* nums, int numsSize) {
    	int i,j,k;
	int tempSize;
	int* temp;

	if(NULL==nums)
	    return;

	tempSize = 3;
	temp = (int*)malloc(sizeof(int)*tempSize);
	if(NULL==temp)
		return;

	memset(temp,0,sizeof(int*)*tempSize);
	
	for(i=0; i<numsSize; i++)
	{
		temp[nums[i]]++;
	}
	
	j = 0;
	for(i=0; i<tempSize; i++)
	{
		k = 0;
		
		while(k<temp[i] && j<numsSize)
		{
			nums[j] = i;
			j++;
			k++;
		}
	}	

	free(temp);
}

void main()
{
	int nums[] = {1,1,1,0,1,1,0,0,2,0,0,1,1,2,1,1,1,2,0,0,2,0,2,1,1,0,1,0,0,1,0,2,1,2,2,2,1,0};
	int size;

	size = 38;
	sortColors(nums, size);
}
