#include <stdio.h>


int* searchRange(int* nums, int numsSize, int target, int* returnSize) 
{
	int left;
	int right;
	int res[] = {-1,-1};

	if(NULL==nums)
		return res;
	
	left = 0;
	right = numsSize-1;

	while(left<right-1)
	{
		mid = left + (left+right)/2;
		
		if(target == nums[mid])
		{
			right = mid;           //寻找左半边
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
	
	if(target == nums[left])
	{
		res[0] = left;
	}
	
	else if(target == nums[right])
	{
		res[0] = right;
	}
	
	else
		return ret;

}


	left = 0;
	right = numsSize-1;

	while(left<right-1)
	{
		mid = left + (left+right)/2;
		
		if(target == nums[mid])
		{
			left = mid;                //寻找右半边
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
	
	if(target == nums[left])
	{
		res[0] = left;
	}
	
	else if(target == nums[right])
	{
		res[0] = right;
	}
	
	else
		return ret;
	
	return ret;
}

void main()
{

}
