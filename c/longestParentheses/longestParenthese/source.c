#include <stdio.h>
#define MAX 1000	

int longestValidParentheses(char* s)
{
	char stack[MAX]={0};
	int maxCnt;
	int i;
	int top;	
	int cnt;

	if(NULL==s)
	{
		return 0;
	}
	
	i=0;
	top=0;
	cnt=0;
	while(s[i]!='\0')
	{
		if(s[i]=='(')
		{
			stack[top++] = s[i++];
		}
		else
		{
			if(top>0 &&  (s[top]==')' && s[top-1]=='('))
			{
				top--;
				i++;
				cnt++;
			}
			else
			{
				top++;
				i++;
			}
		}
	}
	
	return cnt;	
}

void main()
{
	char* s =")()())";
	int result;
	result = longestValidParentheses(s);
	printf("%d", result);	
}
