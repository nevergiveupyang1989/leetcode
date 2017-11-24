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
	memset(temp,0,tempSize);
	
	for(i=0; i<numsSize; i++)
	{
		temp[nums[i]]++;
	}
	
	j = 0;
	for(i=0; i<tempSize; i++)
	{
		k = 0;
		
		while(k<temp[i])
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
	int nums[] = {0,1,2,0,1,2,0,1,2};
	int size;

	size = 9;
	sortColors(nums, size);
}
