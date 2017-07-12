#include <stdio.h>
#include <stdlib.h>
#define bool int 
#define True 1
#define False 0

bool isVaildSudoku(char** board, int boardRowSize, int boardColSize)
{
	const int size=9;
	
	bool rows[9][9] = {False};
	bool cols[9][9] = {False};
	bool areas[9][9] = {False};
	int row,col,area;
	int idx;	
	char cell;	

	for(row=0; row<boardRowSize; row++)
	{
		for(col=0; col<boardColSize; col++)
		{
			cell = board[row][col];
			if(cell == '.')
				continue;
			
			idx = cell - '0' - 1;
			if(rows[row][idx]==True)
				return False;				
			
			rows[row][idx] = True;
			
			if(cols[col][idx]==True)
				return False;
			
			cols[col][idx]=True;
	
			area = (row/3)*3 + col/3;
			if(areas[area][idx]==True)
				return False;
			
			areas[area][idx] = True;
		}
	}
	
	return True; 
}


void main()
{
	char board[][9] ={{'5','3','.','.', '7', '.','.','.','.'},};
	int rowSize,colSize;
	bool result;

	result = isVaildSudoku((char**)board, rowSize, colSize);
	printf("%d", result);
}
