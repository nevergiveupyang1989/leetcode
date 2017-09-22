#include <stdio.h>
#include <stdlib.h>
int cnt = 0;

void sprialMatrix(int x, int y, int row, int col, int* result, int** matrix)
{
	int i,j;

	if(x<row && y<col)
	{
		for(j=y; j<col; j++)
		{
			result[cnt++] = matrix[x][j];		
		}
		
		for(i=x; i<row; i++)
		{
			result[cnt++] = matrix[++i][j];
		}
		
		j -= 2;	
		for(;j>=y; j--)
		{
			result[cnt++] = matrix[--i][j];
		}
		
		for(;i>x;i--)
		{
			result[cnt++] = matrix[--i][j];
		}
		
		sprialMatrix(x+1,y+1,row-2, col-2, result, matrix);		
	}
	return;
}

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize)
{
	int row,col;
	int* result;
	int x,y;

	row = matrixRowSize;
	col = matrixColSize;
	x = 0;
	y = 0;

	result = (int*)malloc(sizeof(int)*(row*col));
	if(NULL==result)
		return NULL;
	
	sprialMatrix(x,y,row,col,result, matrix);
	
	return result;		
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
