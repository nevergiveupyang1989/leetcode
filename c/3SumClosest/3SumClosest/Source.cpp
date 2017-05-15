#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void quickSort(int* nums, int start, int end)
{
	int left;
	int right;
	int key;
	int tmp;
	
	left = start;
	right = end;

	if (start<end)
	{
		key = nums[start];
		while (left<right)
		{
			while (nums[right]>=key && left < right)
			{
				right--;
			}

			while (nums[left]<=key && left < right)
			{
				left++;
			}
			tmp = nums[right];
			nums[right] = nums[left];
			nums[left] = tmp;
		}

		tmp = nums[left];
		nums[left] = key;
		nums[start] = tmp;

		quickSort(nums, start, left - 1);
		quickSort(nums, right + 1, end);
	}
}

int abs(int value)
{
	if (value < 0)
		value = 0 - value;
	return value;
}

int threeSumClosest(int* nums, int numsSize, int target) {
	long long min;
	int i;
	int left;
	int right;
	int sum;
	int absResult;
	long long result;

	quickSort(nums, 0, numsSize - 1);

	i = 0;
	min = 0xffffffff;
	result = 0xffffffff;
	left = 1;
	right = numsSize - 1;
	while (i<numsSize)
	{
		left = i + 1;
		right = numsSize - 1;
		while (left<right){

			sum = nums[i] + nums[left] + nums[right];
			absResult = abs(sum - target);

			if (absResult < min)
			{
				result = sum;
				min = absResult;
			}
			
			if (sum - target < 0)
			{
				left++;
			}
			else
			{
				right--;
			}
		}
		i++;
	}

	return result;
}

void main()
{
	int nums[] = {1, 1, -1, -1, 3};
	int numsSize;
	int target;
	int result;

	numsSize = 5;
	target = -1;
	result=threeSumClosest(nums, numsSize,target);

	printf("%d", result);
}