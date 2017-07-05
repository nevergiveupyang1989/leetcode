#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) 
{
	int left;
	int right;
	int mid;	
	int* res;	
	
	*returnSize = 2;

	if(NULL==nums)
	{
		*returnSize = 0;
		return res;
	}

	res = (int*)malloc(sizeof(int)*2);
	if(NULL==res)
		return NULL;
	
	res[0]=-1;
	res[1]=-1;	

	left = 0;
	right = numsSize-1;

	while(left<right-1)
	{
		mid = (right+left)/2;

		if(target == nums[mid])
		{
			if(right==numsSize-1)
				right = mid;           //寻找左半边
			else
				left = mid;
		}
		else if(target>nums[left])
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	
	if(target == nums[left] || target == nums[right])
	{
		if (target == nums[left])
			res[0] = left;
		if (target == nums[right])
			res[1] = right;
	}
	
	else
		return res;

	if(res[1]!=-1 && res[0]!= -1)
	{
		return res;
	}

	left = 1;
	right = numsSize-1;

	while(left<right-1)
	{
		mid = (right+left)/2;
		
		if(target == nums[mid])
		{
			if(1==left)
				left = mid;                //寻找右半边
			else
				right = mid;
		}
		else if(target>nums[mid])
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	
	if(target == nums[left] || target == nums[right])
	{
		if(nums[left]==target)
			res[0] = left;
		if(nums[right]==target)
			res[1] = right;
	}
	
	if(res[0]==-1 && res[1]==-1)
		return res;
	
	if(res[0]==-1)
	{
		res[0] = res[1];
	}
	else if(res[1]==-1)
		res[1] = res[0];
	
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
