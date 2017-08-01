#include <stdio.h>
#include <stdlib.h>

int firstMissingPositive(int* nums, int numsSize)
{
	int i;
	int result;	

	result = 1;
	if(0==numsSize)
	{
		return result;
	}
	
	for(i=0; i<numsSize; i++)
	{
		while(nums[i]!=i+1 && i<numsSize && nums[i]>0)
		{
            if((nums[i]-1 >= 0) && (nums[i]-1<numsSize) && (nums[i]!=nums[nums[i]-1]) )
			    swap(nums, i, nums[i]-1);
            else 
                break;
		}
	}

	for(i=0; i<numsSize; i++)
	{
		if(nums[i]!=i+1)
			break;
	}
	
	result = i+1;
	
	return result;
}

void main()
{
	int nums[] = {3,4,-1,1};
	int numsSize = 4;
	int result;	

	result = firstMissingPositive(nums, numsSize);

	printf("%d", result);
} 
