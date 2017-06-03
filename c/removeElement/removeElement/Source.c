#include <stdio.h>
#include <stdlib.h>


int removeElement(int* nums, int numsSize, int val) {
	int i;
	int start;
	int size;

	start = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i]!=val)
		{
			nums[start++] = nums[i];
		}
	}

	size = start;

	return size;
}


void main()
{
	int nums[] = {2,2,3,3};
	int numsSize = 4;
	int value;
	int size;

	value = 2;
	size = removeElement(nums, numsSize, value);

	printf("%d", size);
}