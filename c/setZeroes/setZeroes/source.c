#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setZeroes(int(* matrix)[9], int matrixRowSize, int matrixColSize) {
	int i,j;
	int* addRows;
	int* addCols;

	addRows = (int*)malloc(sizeof(int)*matrixRowSize);     //在原来矩阵的基础上，增加一维记录所在行/列有无0元素
	addCols = (int*)malloc(sizeof(int)*matrixColSize);
	
	if(NULL==addRows || NULL==addCols)
		return;

	memset(addRows, 0, sizeof(int)*matrixRowSize);      //执行初始化，1表示该行/列有0元素，0表示没有
	memset(addCols, 0, sizeof(int)*matrixColSize);
	
	if(NULL==matrix)
	    return;
	
	for(i=0; i<matrixRowSize; i++)
	{
		for(j=0; j<matrixColSize; j++)
		{
			if(matrix[i][j]==0)
			{
				addRows[j] = 1;
				addCols[i] = 1;
			}	
		}
	}
	
	for(i=0; i<matrixRowSize; i++)
	{
		if(addRows[i]==1)
		{
			for(j=0; j<matrixColSize; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}

	for(j=0; j<matrixColSize; j++)
	{
		for(i=0; i<matrixRowSize; i++)
		{
			if(addRows[i]==0 && addCols[j]==0){
				continue;
			}
			else
				matrix[i][j] = 0;
		}	
	}

	free(addRows);
	free(addCols);
	return;
}

void main()
{
	int matrix[][9] = {{8,3,1,4,6,4,0,3,4},{9,1,3,0,1,5,7,4,1},{2,2,5,7,5,4,4,3,8},{4,9,7,0,3,6,9,5,9},{4,1,8,8,4,1,5,7,6}};
	int rows,cols;
	int i,j;

	rows = 5;
	cols = 9;
	setZeroes(matrix, rows, cols);
	
	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
		{
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}
}
