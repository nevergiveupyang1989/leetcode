#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
	int start;
	int key;
	int i;

	start = 1;
	key = nums[0];

	if (0 == numsSize)
		return start-1;

	for (i = 1; i<numsSize; i++)
	{
		if (nums[i] != key)
		{
			nums[start++] = nums[i];
			key = nums[i];
		}
	}

	nums[start] = key;

	return start;
}

void main()
{
	int nums[] = {1,2,3,4};
	int numsSize;

	numsSize = 4;
	numsSize = removeDuplicates(nums,numsSize);

	printf("%d", numsSize);
}