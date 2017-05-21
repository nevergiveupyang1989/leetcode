#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000
//leftNUM：表示左括号剩余的个数
//rightNUM:表示右括号剩余的个数
//results:表示所有组的结果
//result:表示一组的结果
//index:表示result的索引值

void generate(int leftNum, int rightNum, char** results, int* returnSize, char* result, int index)
{

	if (0 == leftNum && 0 == rightNum)
	{
		result[index] = '\0';
		results[*returnSize] = (char*)malloc(sizeof(char)*index);
		strcpy(results[*returnSize], result);
		(*returnSize)++;

		return;
	}

	if (leftNum>rightNum)
	{
		return;
	}

	if (leftNum>0)
	{
		result[index] = '(';
		generate(leftNum - 1, rightNum, results, returnSize, result, index+1);
	}

	if (rightNum > 0 && leftNum<rightNum)
	{
		result[index] = ')';
		generate(leftNum, rightNum - 1, results, returnSize, result, index+1);
	}
}


char** generateParenthesis(int n, int* returnSize) {
	char** results;
	char* result;
	int leftNum;
	int rightNum;
	int index;

	leftNum = n;
	rightNum = n;
	index = 0;

	results = (char**)malloc(sizeof(char)*MAXSIZE);
	if (NULL == results)
		return NULL;

	result = (char*)malloc(sizeof(char)*(2*n+1));
	if (NULL == result)
		return NULL;

	generate(leftNum, rightNum, results, returnSize, result, index);

	return results;
}

void main()
{
	int n;
	int returnSize;
	char** results;
	int i;
	int j;

	n = 6;
	returnSize = 0;
	results = generateParenthesis(n, &returnSize);

	//printf("%d", returnSize);

	for (i = 0; i < returnSize; i++)
	{
		for (j = 0; j < 2 * n + 1; j++)
		{
			printf("%c", results[i][j]);
		}

		printf("\n");
	}

	free(results);
}