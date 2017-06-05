#include <stdio.h>
//chageFlag表示已经对pos进行了处理，找到目标的位置，或者没有找到，但已经做了处理


int searchInsert(int* nums, int numsSize, int target) {
	int pos;
	int i;
	int changFlag;

	pos = 0;
	changFlag = 0;

	if (NULL == nums)
		return pos;

	for (i = 0; i < numsSize; i++)
	{
		if (target < nums[i]&&!changFlag)
		{
			pos = i;
			changFlag = 1;
		}

		if (nums[i] == target)
		{
			pos = i;
			changFlag = 1;
		}
	}

	if (0==pos&&!changFlag)
	{
		pos = numsSize;
	}

	return pos;
}

void main()
{
	int pos;
	int nums[] = {1,2,4,5};
	int numsSize = 4;
	int target=3;

	pos = searchInsert(nums,numsSize,target);

	printf("%d", pos);
}