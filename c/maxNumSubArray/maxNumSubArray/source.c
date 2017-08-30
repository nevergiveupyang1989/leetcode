#include <stdio.h>
#include <stdlib.h>
#define MAX 0x7fffffff

int maxSubArray(int* nums, int numsSize)
{
	int sum;
	int i;	
	int j;	
	int temp;	

	sum = 0;
	
	for(i=0; i<numsSize; i++)
	{
		for(j=i+1; j<numsSize; j++)
		{
			if(nums[i]<nums[j])
			{
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;				
			}
		}

		if(nums[i]<0)
		{
			if(i!=0)
				continue;
			else
				return nums[i];
		}

		else if(nums[i]==MAX)
		{
			return nums[i];
		}

		else
		{
			sum += nums[i];
		}
	}

	return sum;
}

void main()
{
	int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
	int numsSize = 9;
	int sum;
		
	sum = maxSubArray(nums, numsSize);

	printf("%d", sum);
}
