#include <stdio.h>

void reverseNums(int* nums, int start, int end)
{
	int i;
	int tmp;
	while(start<end)
	{
		tmp = nums[start];
		nums[start] = nums[end];
		nums[end] = tmp;
		start++;
		end--;
	}
}

void nextPermutation(int* nums, int numsSize )
{
	int i,j;
	int pos;
	int tmp;	
	int left;
	int right;
	int isAccend;	
	int flag=0;               //此变量表示时时候找到可交换元素	
	isAccend = 1;         //0表示不是降序，1表示降序
	right = numsSize - 1;
	left = numsSize - 2;
	
	while(left>=0)
	{
		while(right>left)
		{
			if(nums[right]>nums[left])
			{
				pos = left;
				tmp = nums[right];
				nums[right] = nums[left];
				nums[left] = tmp;
				isAccend = 0;
				flag = 1;
				break;
			}
			right--;
		}
		
		if(flag==1)
			break;         //元素已交换需要推出循环
		left--;
		right = numsSize;
	}
	
	if(left==-1 && isAccend ==1)
	{
		reverseNums(nums, 0, numsSize-1);
		return ;
	}

		
	reverseNums(nums,pos+1,numsSize-1);
}


void main()
{
	int nums[] = {5,4,7,5,3,2};
	int numsSize = 6;
	int i;
	nextPermutation(nums, numsSize);
	
	for(i=0; i<numsSize; i++){	
		printf("%d", nums[i]);
	}
}
