#include <stdio.h>
#include <string.h>
#include <malloc.h>
char* getNums(int n)
{
	char* nums = NULL;
	int i;

	if(0 == n)
		return NULL;
	
	nums = (char*)malloc(sizeof(char)*n);
	if(NULL==nums)
		return NULL;	

	for(i=0; i<n; i++)
	{
		nums[i] = i+1;
	}
	
	return nums;	
}


void swap(char* nums, int index, int start)
{
	int temp;
	int i;

	temp = nums[index];
	
	i = index - 1;
	while(i>=start)
	{
		nums[i+1] = nums[i];
		i--;
	}	
	
	nums[start] = temp;
}

char* permutationSeq(char* nums, int start, int end, int k, int* cnt)
{
	int i;
	char* result;	
	
	result = NULL;

	if(start == end)
	{
		if(*cnt==k-1)
		{
			result = (char*)malloc(sizeof(char)*end);
			for(i=0; i<end; i++)
			{
				result[i] = nums[i];
			}
		}
		
		*cnt++;	
		return result;
		/*for(i=0; i<end; i++)
		{
			printf("%d", nums[i]);
		}
		printf("\n");*/
	}
	
	for(i=start; i<end; i++)
	{
		swap(nums, i, start);
		result = permutationSeq(nums, start+1, end, k, cnt);
		if(NULL!=result)
			return result;
		swap(nums, i, start);
	}
}

char* getPermutation(int n, int k)
{
	int start,end;
	char* nums;
	int* cnt;
	char* result;
	//int nums[] = {1,2,3};
	
	cnt = (int*)malloc(sizeof(int)*1);
	*cnt = 0;

	nums = getNums(n);
	start = 0;
	end = n;
	result = permutationSeq(nums, start, end, k, cnt);
	
	return result;
}

void main()
{
	int n,k;
	n = 3;
	k = 6;
	int i;
	char* result;

	result = getPermutation(n,k);
	for(i=0; i<n; i++)
	{
		printf("%d", result[i]);
	}
}
