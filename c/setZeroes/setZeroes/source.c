#include <stdio.h>
#include <stdlib.h>

void setZeroes(int(* matrix)[3], int matrixRowSize, int matrixColSize) {
	int i,j;

	if(NULL==matrix)
	    return;
	
	for(i=1; i<matrixRowSize; i++)
	{
		for(j=1; j<matrixColSize; j++)
		{
			if(matrix[i][j]==0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}	
		}
	}

	for(i=0; i<matrixRowSize; i++)
	{
		if(matrix[i][0]==0)
		{
			for(j=0; j<matrixColSize; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}


	for(j=0; j<matrixColSize; j++)
	{
		if(matrix[0][j]==0)
		{
			for(i=0; i<matrixRowSize; i++)
			{
				matrix[i][j] = 0;
			}
		}
	}

	return;
}

void main()
{
	int matrix[][3] = {{1,2,3},{1,0,3}, {1,3,0}};
	int rows,cols;
	int i,j;

	rows = 3;
	cols = 3;
	setZeroes(matrix, rows, cols);
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}
}
