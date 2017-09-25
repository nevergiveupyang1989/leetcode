#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize)
{
	int startx,starty;
	int visitedRows,visitedCols;
	int step;
	int* result;
	int direction;
	int x[]={1,0,-1,0};
	int y[]={0,1,0,-1};
	int rows;
	int cols;
	int nums;
	int cnt;

	startx = 0;
	starty = 0;
	visitedRows = 0;
	visitedCols = 0;
	step = 0;
	direction = 0;
	rows = 	matrixRowSize;
	cols = matrixColSize;
	cnt = 0;
	
	result = (int*)malloc(sizeof(int)*(matrixRowSize*matrixColSize));
	if(NULL==result)
		return NULL;
	
	while(1)
	{
		if(x[direction]==0)
		{
			nums = cols - visitedRows;			
		}
		else
			nums = rows - visitedCols;
	
		if(nums<=0)
			break;
		
		result[cnt++] = matrix[startx][starty];
		step++;
		
		if(step==nums)
		{
			step = 0;
			visitedRows = x[direction] == 0?0:1;
			visitedCols = y[direction] == 0?0:1;
			direction++;
		}
		
		startx += y[direction];
		starty += x[direction];		
	}
}


void main()
{
	int r,c,i,j;
	int* result;
	int** matrix;
	r = 2;
	c = 2;
	
	matrix = (int **)malloc(sizeof(int)*r);
	for(i=0; i<r; i++)
	{
		matrix[i] = (int*)malloc(sizeof(int)*c);
	}	
	
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	matrix[1][2] = 4;

	result = spiralOrder(matrix, r, c);
	
	for(i=0; i<r*c; i++)
	{
		printf("%d", result[i]);
	}
}
