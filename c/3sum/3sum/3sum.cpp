#include <stdlib.h>
#include <stdio.h>

void quickSort(int* nums, int left, int right)
{
	int start;
	int end;
	int num;
	int tmp;

	start = left;
	end = right;
	num = nums[left];

	if (left < right)
	{
		while (start<end)
		{
			while (nums[end] >= num && start < end)
			{
				end--;
			}

			while (nums[start] <= num && start < end)
			{
				start++;
			}

			tmp = nums[start];
			nums[start] = nums[end];
			nums[end] = tmp;
		}
		nums[left] = nums[start];
		nums[start] = num;

		quickSort(nums, left, start - 1);
		quickSort(nums, start + 1, right);
	}
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
	int **result;
	int sum;
	int start;
	int left;
	int right;
	int i;
	int m;
	if (numsSize < 3)
		return NULL;

	result = (int**)calloc(20000,sizeof(int*));
	left = 0;
	right = numsSize - 1;

	quickSort(nums, left, right);
	m = 0;
	for (i = 0; i < numsSize - 2; i++)
	{
		start = i;
		left = i + 1;
		right = numsSize - 1;
		sum = 0 - nums[i];
		if (0 == i || i > 0 && nums[i] != nums[i - 1])
		{
			while (left < right)
			{
				if (nums[left] + nums[right] < sum && left < right)
				{
					left++;
				}

				if (nums[left] + nums[right] > sum && left < right)
				{
					right--;
				}

				if (nums[left] + nums[right] == sum && left < right)
				{
					result[m] = (int*)malloc(3 * sizeof(int));
					result[m][0] = nums[start];
					result[m][1] = nums[left];
					result[m][2] = nums[right];
					m++;

					while (left < right && nums[left] == nums[left + 1])
					{
						left++;
					}

					while (left < right && nums[right] == nums[right - 1])
					{
						right--;
					}
					left++;
					right--;
				}

			}
		}
	}

	*returnSize = m;
	return result;
}


void main()
{
	int nums[] = { -2, -2, -1, -1, 0, 1, 1, 2, 2, };
	int numsSize;
	int returnSize;
	int i;
	int j;
	int **result;

	returnSize = 0;
	numsSize = 9;
	result = threeSum(nums, numsSize, &returnSize);

	printf("%d\n", returnSize);

	for (i = 0; i < returnSize;i++)
	{
		for (j = 0; j < 3;j++)
		{
			printf("%d",result[i][j]);
		}

		printf("\n");
	}

	printf("%d", returnSize);

	for (int i = 0; i < 20000; i++)
	{
		free(result[i]);
	}

	free(result);
}