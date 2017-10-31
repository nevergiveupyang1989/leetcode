#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bool int
#define True 1
#define False 0

bool isNumber(char* s)
{
	int i;
	int signNum;
	int pointNum;	
	int strSize;
	int digitNum;
		
	strSize = strlen(s);	
	
	while(s[i]==' ')
		i++;
	
	signNum = 0;
	while(s[i]=='+' || s[i]=='-')
	{
		signNum++;
		i++;	
	}
	
	if(signNum>1)
		return False;
	
	pointNum = 0;
	digitNum = 0;
	for(; (s[i]=='.' || (s[i]>='1' && s[i]<='9'))&&i<strSize ;i++)
	{
		if(s[i]=='.')
			pointNum++;
		else
			digitNum++;
	}
	
	if(pointNum>1 || digitNum<1)
		return False;
	
	if(s[i]=='e')
	{
		i++;
		signNum = 0;
		while(s[i]=='+' || s[i]=='-')
			signNum++;
	
		if(signNum>1)
			return False;	
		
		while(s[i]>='0' && s[i]<= '9')
			i++;
	}

	while(s[i]==' ')
		i++;

	return s[i]==0;
}


void main()
{
	bool result;
	char* s = "123";
	result = isNumber(s);

	printf("%d",result);
}
