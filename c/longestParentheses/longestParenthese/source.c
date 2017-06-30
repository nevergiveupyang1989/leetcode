#include <stdio.h>
#define MAX 1000	
#define maxNum(a,b) ((a)>(b))?(a):(b) 

int longestValidParentheses(char* s)
{
	char stack[MAX]={0};
	int maxCnt;
	int i;
	int top;	
	int cnt;
	int maxLen;
	int curLen;	

	if(NULL==s)
	{
		return 0;
	}
	
	i=0;
	top=0;
	curLen=0;
	maxLen=0;
	while(s[i]!='\0')
	{
		if(s[i]=='(')
		{
			stack[top++] = s[i++];
		}
		else
		{
			if(top>=0 &&  (stack[--top]=='(' && s[i]==')'))
			{
				if(top==0)
				{
					curLen = i+1;			
				}
				else
				{
					curLen = i-(top+1);
				}
				
				maxLen = maxNum(maxLen,curLen);		
				i++;
			}
			else
			{
				top++;
				i++;
			}
		}
	}
	
	return maxLen;	
}

void main()
{
	char* s ="()(()()";
	int result;
	result = longestValidParentheses(s);
	printf("%d", result);	
}
