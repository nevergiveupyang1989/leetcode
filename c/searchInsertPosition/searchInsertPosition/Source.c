#include <stdio.h>
//chageFlag��ʾ�Ѿ���pos�����˴����ҵ�Ŀ���λ�ã�����û���ҵ������Ѿ����˴���


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