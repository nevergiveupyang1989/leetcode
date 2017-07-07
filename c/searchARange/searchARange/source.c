#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) 
{
	int start;
	int end;
	int* res;
	int mid;	

	*returnSize = 2;
	
	res = (int*)malloc(sizeof(int)*2);
	if(NULL==res)
	{
		returnSize = 0;
		return 	NULL;
	}
	
	start = 0;
	end = numsSize-1;

	while(start<end)
	{
		mid = start + (end-start)/2;
		
		if(nums[mid]<target)
		{
			start = mid + 1;
		}
		else if (nums[mid]>target)
		{
			end = mid - 1;
		}
		else
		{
			if(nums[start]<target)
				start++;
			if(nums[end]>target)
				end--;
		}
	}
	
	if(nums[start]==target)
	{
		res[0]=start;
		res[1]=end;
	}

	return res;
}

void main()
{
	int nums[] = {1,3};
	int target = 1;
	int* returnSize;
	int numsSize = 2;
	int i;	
	int* res;	

	returnSize = (int*)malloc(sizeof(int)*2);
	res = searchRange(nums,numsSize,target,returnSize);

	for(i=0; i<2; i++)
	{
		printf("%d", res[i]);
	}
	free(returnSize);
	free(res);
}
