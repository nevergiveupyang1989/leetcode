#include <stdio.h>
#include <stdlib.h>
int binarySearch(int* nums, int left, int right, int target)
{
	int begin;
	int end;
	int mid;	
	int pos;	

	if(left>right)
	{
		return -1;
	}	
	
	
	begin = left;
	end = right;
	mid = (begin+end)/2;

	if(nums[mid]==target)
	{
		pos = mid;
		return pos;		
	}
	
	if(nums[mid]<target)
	{
		begin = mid+1;
		pos = binarySearch(nums, begin, end, target);
	}
	else
	{
		end = mid-1;	
		pos = binarySearch(nums, begin, end, target);
	}
	
	return pos;		
}

int search(int* nums, int numsSize, int target)
{
	int i;
	int j;
	int pos;
	int left1;
	int right1;
	int left2;
	int right2;
	
	j=0;
	pos = numsSize-1;	
	while(j<=numsSize-2)
	{
		if(nums[j+1]<nums[j])
		{	
			pos = j;
		
		}
		j++;
	}
	
	left1 = 0;
	right1 = pos;
	left2 = pos+1;
	right2 = numsSize-1;
	
	pos = binarySearch(nums,left1, right1, target);
	if(-1!=pos)
	{
		return pos;
	}
	
	pos = binarySearch(nums,left2, right2, target);
	
	return pos;
}

void main()
{
	int nums[]={1,2,3};
	int target = 3;
	int numsSize = 3;
	int pos;
	
	pos = search(nums,numsSize,target);
	printf("%d", pos);
}
