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

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
	int **result;
	int start;
	int left;
	int right;
	int i,j;
	int m;
	int sum;
	int fourSum;
	int cnt;
	if (numsSize < 3)
		return NULL;

	result = (int**)calloc(20000, sizeof(int*));
	left = 0;
	right = numsSize - 1;

	quickSort(nums, left, right);
	m = 0;

	for (j = 0; j < numsSize - 3; j++)
	{
		fourSum = target - nums[j];

		if (j>0 && nums[j] == nums[j - 1])
			continue;

		cnt = 0;
		for (i = j+1; i < numsSize - 2; i++)
		{
			start = i;
			left = i + 1;
			right = numsSize - 1;
			
			if (i>j + 1 && nums[i] == nums[i - 1])
				continue;
			sum = fourSum - nums[i];

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
					result[m] = (int*)malloc(4 * sizeof(int));
					result[m][1] = nums[start];
					result[m][2] = nums[left];
					result[m][3] = nums[right];
					result[m][0] = nums[j];
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
	int nums[] = {-3, -2, -1, 0, 0, 1, 2, 3};
	int numsSize;
	int returnSize;
	int i;
	int j;
	int **result;
	int target;

	returnSize = 0;
	numsSize = 8;
	target = 0;

	result = fourSum(nums, numsSize, target, &returnSize);


	for (i = 0; i < returnSize; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d", result[i][j]);
		}

		printf("\n");
	}

	printf("%d", returnSize);

	/*for (int i = 0; i < 20000; i++)
	{
		free(result[i]);
	}

	free(result);*/
}