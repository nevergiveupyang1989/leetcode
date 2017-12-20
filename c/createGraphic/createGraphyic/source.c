#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define INIFITY 65535
typedef char POINTTYPE;


struct graphyic
{
	POINTTYPE points[MAX];
	int edges[MAX][MAX];
	int pointNum;
	int edgeNum;
};

typedef struct graphyic Graphyic;
typedef struct graphyic* pGraphyic;

void initGraphyic(pGraphyic pgraphyic)
{
	int i,j;

	if(NULL==pgraphyic)
		return;
	
	for(i=0; i<MAX; i++){
		pgraphyic->points[i] = 0;
	}

	for(i=0; i<MAX; i++)
	{
		for(j=0; j<MAX; j++)
		{
			if(i==j)
				pgraphyic->edges[i][j] = 0;
			else
				pgraphyic->edges[i][j] = INIFITY;
		}
	}
}

int getPos(pGraphyic pgraphyic, char target)
{
	int i;

	if(NULL==pgraphyic)
	{
		return -1;
	}

	for(i=0; i<pgraphyic->pointNum; i++)
	{
		if(target==pgraphyic->points[i])
		{
			return i;
		}	
	}

	return -1;
}

void printGraphyic(pGraphyic pgraphyic)
{
	int i,j;

	for(i=0; i<pgraphyic->pointNum; i++)
	{
		for(j=0; j<pgraphyic->pointNum; j++)
		{
			printf("%d", pgraphyic->edges[i][j]);
			printf(" ");
		}
		printf("\n");	
	}
}

void createGraphyic(pGraphyic pgraphyic)
{
	int i,pos1, pos2;
	char t1, t2;

	if(NULL==pgraphyic)
		return;
	initGraphyic(pgraphyic);

	printf("INPUT THE POINTS:\n");
	for(i=0; i<pgraphyic->pointNum; i++)
	{
		fflush(stdin);
		scanf("%c", &(pgraphyic->points[i]) );
	}

	printf("INPUT EDGES:\n");	
	for(i=0; i<pgraphyic->edgeNum; i++){
		fflush(stdin);
		scanf("%c", &t1);
		pos1 = getPos(pgraphyic, t1);
		
		fflush(stdin);
		scanf("%c", &t2);
		pos2 = getPos(pgraphyic, t2);

		pgraphyic->edges[pos1][pos2] = 1;
	}

	printGraphyic(pgraphyic);
}

void main()
{
	pGraphyic pgraphyic;

	pgraphyic = (pGraphyic)malloc(sizeof(Graphyic));
	if(NULL==pgraphyic)
	{
		return;
	}

	pgraphyic->pointNum = 6;
	pgraphyic->edgeNum = 1;

	createGraphyic(pgraphyic);
}
