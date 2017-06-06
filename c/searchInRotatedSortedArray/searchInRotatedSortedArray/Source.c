#include <stdio.h>

int search(int* nums, int numsSize, int target)
{
	int i;
	
	if(NULL==nums)
{
	return 0;
}

	for(i=0; i<numsSize; i++)
{
	if(nums[i]==target)
		return i;
}
	return -1;
}

void main()
{
	int nums={1,2,3,4,5}
	int target = 3;
	int numsSize = 5;

	serch(nums,numsSize, target);
}
