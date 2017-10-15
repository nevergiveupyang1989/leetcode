#include <stdio.h>
#include <string.h>
char* getNums(int n)
{
	return NULL;
}


void swap(int* nums, int a, int b)
{
	int temp;
	temp = nums[a];
	nums[a] = nums[b];
	nums[b] = temp;
}

void permutationSeq(int* nums, int start, int end)
{
	int i;

	if(start == end)
	{
		for(i=0; i<end; i++)
		{
			printf("%d", nums[i]);
		}
		printf("\n");
	}
	
	for(i=start; i<end; i++)
	{
		swap(nums, i, start);
		permutationSeq(nums, start+1, end);
		swap(nums, i, start);
	}
}

char* getPermutation(int n, int k)
{
	int start,end;

	int nums[] = {1,2,3};
	start = 0;
	end = 3;

	permutationSeq(nums, start, end);
	
	return NULL;
}

void main()
{
	int n,k;
	n = 3;
	k = 3;
	
	getPermutation(n,k);
}
