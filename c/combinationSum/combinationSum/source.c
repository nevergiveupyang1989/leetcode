#include <stdlib.h>
#include <stdio.h>
#define MAX 1000

int top;
int rows = 0;      //stack top
int columnMax = 0;

void allAnswerSstackPush(int** nums, int* oneAnswers)
{
	nums[rows++] = oneAnswers;
	
	if(top>columnMax)
	{
		columnMax = top;
	}

	top=0;
}

void oneAnswersStackPop()
{
	top--;
}

void oneAnswersStackPush(int* oneAnswers, int num)
{
	oneAnswers[top++] = num;
}

void dfs(int** nums, int target, const int* candidates, int candidatesSize, int* oneAnswers)
{
	int i;
	int size;	
	
	size = candidatesSize;
	
	if(target==0)
	{
		stackPush(nums, oneAnswers);
	}
	
	for(i=0; i<size; i++)
	{
		if(target<candidates[i])
			return;
		oneAnswersStackPush(oneAnswers, candidates);	
		dfs(nums, target-candidates[i],candidates, candidatesSize, oneAnswers);
		stackPush(candidates[i]);
		oneAnswersStackPop();
	}
}

void sort(int* condidates, int condidates)
{
	int i;
	int j;
	int temp;	

	for(i=0; i<condidates; i++)
	{
		for(j=i; j<condidates; j++)
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

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize)
{
	int** nums;
	int* oneAnswers;

	nums = (int**)malloc(sizof(int*)*MAX);
	if(NULL==nums)
		return NULL;
	
	oneAnswers = (int**)malloc(sizof(int*)*MAX);
	if(NULL==nums)
		return NULL;
	
	dfs(nums, target, condidates, condidatesSize, oneAnswers);
	
	*returnSize = rows + 1;
	**columnSize = columnMax;	
	return nums;
}

void main()
{
	int a[][3]={{1},{1,2,3}};
}
