#include <stdio.h>
#include <stdlib.h>

void setZeroes(int(* matrix)[3], int matrixRowSize, int matrixColSize) {
	int i,j;
	int isClear;
	
	isClear = 0;
	if(NULL==matrix)
	    return;
	
	if(matrixRowSize==1 || matrixColSize==1)
	{
		if(matrixRowSize==1)
		{
			for(i=0; i<matrixColSize;i++)
			{
				if(matrix[0][i]==0)
				{
					isClear = 1;
					break;
				}
			}
			
			if(isClear == 0)
				return;

			for(i=0; i<matrixColSize; i++)
			{
				matrix[0][i] = 0;
			}
		}
		else
		{
			for(i=0; i<matrixRowSize; i++)
			{
				if(matrix[i][0]==0)
				{
					isClear = 1;
					break;
				}
			}
			
			if(isClear==0)
				return;

			for(i=0; i<matrixRowSize; i++)
			{
				matrix[i][0] = 0;
			}
		}

		return;
	}

	else{
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
