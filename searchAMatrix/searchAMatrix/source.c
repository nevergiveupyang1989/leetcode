#include <stdio.h>
#include <stdlib.h>
#define bool int
#define TRUE 1
#define FALSE 0

bool searchMatrix(int(* matrix)[3], int matrixRowSize, int matrixColSize, int target) 
{
	int left;
	int right;
	int mid;
	int i;

	if(NULL==matrix)
		return FALSE;
	
	left = 0;
	right = (matrixRowSize*matrixColSize)-1;

	while(left<right)
	{
		mid = (left+right)/2;
		if(matrix[mid/matrixColSize][mid%matrixColSize]<target)
		{
			left = mid + 1;
		}
		else if(matrix[mid/matrixColSize][mid%matrixColSize]>target)
		{
			right = mid - 1;
		}
		else
		{
			printf("mid:%d", mid);
			return TRUE;
		}
	}

	return FALSE;
}

void main()
{
	int matrix[][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int row;
	int col;
	int result;
	int target;

	row = 3;
	col = 3;
	target = 30;

	result = searchMatrix(matrix, row, col, target);

	printf("%d", result);
}
