#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

char* count2Str(char* s)
{
	int i;
	int cnt;
	int size;	
	char target;	
	long sum;	
	int carry;	
	char* result;	

	cnt = 0;
	size = strlen(s);
	target = s[0];
	sum = 0;	
	carry = 1;

	result = (char*)malloc(sizeof(char)*MAX);
	if (NULL==result)
		return 	NULL;	

	for(i=0; i<size; i++)
	{
		if(target==s[i])
		{
			cnt++;
		}
		else
		{
			sum += (cnt*10 + (target-'0'))*carry;
			target = s[i];
			cnt=1;	
		}		
	}
	
	sum += (cnt*10 + (target-'0'))*(carry/10);
	sprintf(result, "%ld", sum);	
	
	return result;
}

char* countAndSay(int n)
{
	int i;
	char* s;	

	s = (char*)malloc(sizeof(char)*2);
	if(NULL==s)
		return NULL;

	s[0]='1';
	s[1]='\0';	

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

void main()
{
	int n,i;
	n=2;
	char* result;

	result = countAndSay(n);
	
	i=0;
	while(result[i]!='\0')
	{
		printf("%c", result[i]);
		i++;
	}
}
