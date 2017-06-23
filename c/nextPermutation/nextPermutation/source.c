#include <stdio.h>

void nextPermutation(int* nums, int numsSize )
{
	int i,j;
	int pos;
	int tmp;	

	for(i=numsSize; i-1>0; i--)
	{
		if(nums[i-1]>nums[i])
		{
			pos = i-1;
			break;			
		}
	}
	
	for(i=numsSize; i>pos; i--)
	{
		if(nums[i]>nums[pos])
		{
			tmp = nums[i];
			nums[i] = nums[pos];
			nums[pos] = tmp;
		}
	}
	
	j = numsSize;
	i = pos;
	while(i<j)
	{
		tmp = nums[j];
		nums[j] = nums[i];
		nums[i] = tmp;
		i++;
		j--;
	}	
}


void main()
{
	int* nums = "12456";
	int numsSize = 5;
	nextPermutation(nums, numsSize);

	printf("%s", nums);
}
