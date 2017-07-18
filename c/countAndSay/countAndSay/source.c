#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
int NODECNT=0;
char* nodeList[MAX];


char* count2Str(char* s)
{
	int i;
	int cnt;
	int size;	
	char target;	
	int carry;	
	int index;	
	char* result;	

	cnt = 0;
	size = strlen(s);
	target = s[0];
	index = 0;	

	result = (char*)malloc(sizeof(char)*size);
	if(NULL==result)
		return NULL;	

	for(i=0; i<size; i++)
	{
		if(target==s[i])
		{
			cnt++;
		}
		else
		{
			result[index++] = cnt + '0';
			result[index++] = target;
			target = s[i];
			cnt=1;
		}		
	}
	result[index++] = cnt + '0';
	result[index++] = target;
	
	nodeList[NODECNT++] = result;

	return result;
}

char* countAndSay(int n)
{
	int i;
	char* s = "1";	

	if(n<=0)
	{
		return NULL;
	}

	for(i=1; i<n; i++)
	{
		s = count2Str(s);
	}
	
	return s;
}

void freeNode()
{
	int i;
	
	for(i=0; i<NODECNT; i++)
	{
		free(nodeList[i]);
	}
}

void main()
{
	int n,i;
	n=5;
	char* result;

	result = countAndSay(n);
	
	i=0;
	while(result[i]!='\0')
	{
		printf("%c", result[i]);
		i++;
	}
}
