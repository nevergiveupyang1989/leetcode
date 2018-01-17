#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bool int
#define TRUE 1
#define FALSE 0

bool dfs(char (*board)[3], int boardRowSize, int boardColSize, char* word, int r, int c, int begin, int wordSize)
{
	bool res = FALSE;
	
	if(board[r][c]==word[begin])
	{
		if(begin >= wordSize-1)
		{
			return TRUE;
		}

		if(r+1 < boardRowSize && dfs(board, boardRowSize,boardColSize,word, r+1,c, begin+1, wordSize))
		{
			board[r][c] = '*';
			res = TRUE;
		}
		else if(r > 0 && dfs(board, boardRowSize,boardColSize,word, r-1,c, begin+1, wordSize))
		{

			board[r][c] = '*';
			res = TRUE;
		}
		else if(c > 0 && dfs(board, boardRowSize,boardColSize,word, r,c-1, begin+1, wordSize))
		{
			board[r][c] = '*';
			res = TRUE;
		}
		else if(c+1 < boardColSize && dfs(board, boardRowSize,boardColSize,word, r,c+1, begin+1, wordSize))
		{
			board[r][c] = '*';
			res = TRUE;
		}
	}

	return res;	
}

bool exist(char (*board)[3], int boardRowSize, int boardColSize, char* word) 
{
    int i,j;
    int begin;
    int wordSize;

    wordSize = strlen(word);
    if(board == NULL || word == NULL)
	    return FALSE;

    for(i=0; i<boardRowSize; i++)
    {
	    for(j=0; j<boardColSize;j++)
	    {
		    begin = 0;
		    if(dfs(board,boardRowSize, boardColSize,word, i,j, begin, wordSize))
			    return TRUE;
	    }
    }

    return FALSE;
}

void main()
{
	char board[3][3] = {{'A','B','C'},{'E','F','G'},{'H','J','K'}};
	int boardRowSize = 2;
	int boardColSize = 3;
	char* word = "CGE";
	char res;

	res = exist(board, boardRowSize, boardColSize, word);

	printf("%d", res);	
}
