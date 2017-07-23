#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 1000

int rows = -1;      //
int column = -1;

void allAnswerSstackPush(int** nums, int* oneAnswers, int* returnSize, int** columnsSize)
{
	int i;
	rows++;
	nums[rows] = (int*)malloc(sizeof(column));
	
	for(i=0; i<=column; i++)
	{	
		nums[rows][i] = oneAnswers[i];
	}
	*returnSize = rows+1;
	columnsSize[rows][0] = column+1;
}

void oneAnswersStackPop(int* oneAnswers)
{
	oneAnswers[column]=-1;
	column--;
}

void oneAnswersStackPush(int* oneAnswers, int num)
{
	oneAnswers[++column] = num;
}

int getTargetPos(int* candidates, int target, int candidatesSize)
{
	int i;
	int pos;

	pos = -1;
	for(i=0; i<candidatesSize; i++)
	{
		if(target==candidates[i])
			pos = i;
	}
	
	return pos;
}

void dfs(int** nums, int target,int* candidates,int candidatesSize, int* oneAnswers, int* returnSize, int** columnsSize)
{
	int i;
	int size;	
	int pos;	

	size = candidatesSize;
	
	if(target==0)
	{
		allAnswerSstackPush(nums, oneAnswers, returnSize,columnsSize);
	}
	
	for(i=0; i<size; i++)
	{
		if(target<candidates[i])
			return;
		pos = getTargetPos(candidates, oneAnswers[column+1], candidatesSize);
		
		if(i>=pos || -1==pos)		
			oneAnswersStackPush(oneAnswers, candidates[i]);	
		dfs(nums, target-candidates[i],candidates, candidatesSize, oneAnswers, returnSize, columnsSize);
		//stackPush(candidates[i]);
		oneAnswersStackPop(oneAnswers);
	}
}

void sort(int* condidates, int condidatesSize)
{
	int i;
	int j;
	int temp;	

	for(i=0; i<condidatesSize; i++)
	{
		for(j=i; j<condidatesSize; j++)
		{
			if(condidates[i]>condidates[j])
			{
				temp = condidates[i];
				condidates[i] = condidates[j];
				condidates[j] = temp;
			}
		}
	}
}

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnsSize, int* returnSize)
{
	int** nums;
	int* oneAnswers;

	nums = (int**)malloc(sizeof(int*)*MAX);
	if(NULL==nums)
		return NULL;
		
	oneAnswers = (int*)malloc(sizeof(int)*MAX);
	if(NULL==nums)
		return NULL;
	
	memset(oneAnswers, -1, MAX*sizeof(int));
	dfs(nums, target, candidates, candidatesSize, oneAnswers, returnSize, columnsSize);
	
	return nums;
}

void main()
{
	int a[4]={2,3,6,7};
	int size;
	int target;	
	int** columnsSize;
	int* returnSize;
	int** result;	
	int i,j;
	size = 4;
	target = 7;
	
	returnSize = (int*)malloc(sizeof(int)*1);
	columnsSize = (int**)malloc(sizeof(int*)*MAX);
	
	for(i=0; i<MAX; i++)
	{
		columnsSize[i] = (int*)malloc(sizeof(int)*1);
	}
	
	result = combinationSum(a, size, target, columnsSize, returnSize);	
	
	for(i=0; i<*returnSize; i++)
	{
		for(j=0; j<(*columnsSize[i]); j++)
		{
			printf("%d\n", result[i][j]);
		}
	}
	
/*	for(i=0; i<(*returnSize); i++)
	{
		free(result[i]);
	}
	
	free(result);
*/
}
