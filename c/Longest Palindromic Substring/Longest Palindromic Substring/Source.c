#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define min(x, y) ((x)<(y)?(x):(y))

char* createNewStr(char* s , int newSize){
	char* newStr=NULL;
	int i = 0;
	int j = 0;
	newStr = (char*)malloc(sizeof(char)*newSize);

	if (NULL == newStr)
	{
		printf("malloc fail");
		return NULL;
	}

	else
	{
		while (i <= newSize)
		{
			if (0 == i % 2){
				newStr[i] = '#';
			}
			else
			{
				if (i == newSize){
					newStr[i] = '\0';
				}
				else
				{
					newStr[i] = s[j++];
				}
			}

			i++;
		}
	}

	return newStr;
}

char* longestPalindrome(char* s) {
	int len;
	int newSize;
	int i = 0;
	int j = 0;
	char* p = NULL;
	char* newStr = NULL;
	int max = 0;
	int id = 0;

	if (NULL == s)
	{
		printf("error");
		
		return NULL;
	}

	len = strlen(s);
	
	if (0 == len % 2)
	{	
		newSize = 2 * len + 1;
		newStr = createNewStr(s, newSize);
	}

	else
	{
		newStr = s;
	}

	p = (char*)malloc(sizeof(char)*2*len);
	if (NULL == p)
	{
		printf("malloc fail");
		return NULL;
	}

	for (i = 0; i < 2 * len + 1; i++)
	{
		if (max <= i)
		{
			p[i] = 1;
			while (newStr[i + p[i]] == newStr[i - p[i]])
				p[i]++;
		}
		else
		{
			if (p[i] + i < max)
			{
				p[i] = p[2 * id - i];
			}

			if (p[i] + i > max)
			{
				p[i] = max - i;
			}
		}

		if (i + p[i] > max){
			max = i + p[i] - 1;
			id = i;
		}
	}

	for (int i = 0; i < 2 * len + 1; i++){
		printf("%d", p[i]);
	}

	return newStr;
}

void main(){
	char* s = "accb";
	char* result;
	result=longestPalindrome(s);

	printf("%s", result);

	return;
}