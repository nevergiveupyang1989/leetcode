#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
	int fast;
	int slow;
	int size;

	fast = 0;
	slow = 0;
	size = 0;

	if (1 == numsSize)
		return size = 1;

	while (fast<=numsSize-2)
	{
		if (fast==slow || ((nums[fast] == nums[fast + 1]) && nums[fast]!=nums[slow-1]))
		{
			nums[slow++] = nums[fast];
			size++;
		}

		else if (nums[fast] != nums[fast + 1])
		{
			if (nums[fast] != nums[slow-1])
			{
				nums[slow++] = nums[fast];
				nums[slow++] = nums[fast + 1];
				size += 2;
			}

			else
			{
				nums[slow++] = nums[fast + 1];
				size++;
			}
		}

		fast += 2;
	}


	return size;
}

void main()
{
	int nums[] = {1,2,3,4};
	int numsSize;

	numsSize = 4;
	numsSize = removeDuplicates(nums,numsSize);

	printf("%d", numsSize);
}