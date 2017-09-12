#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLastWord(char* s)
{
	int strLength;
	int length;
	char *rear;
	int i;	

	strLength = strlen(s);
	length = 0;
	
	for(i=strLength-1; i>=0; i--)
	{
		if(s[i]!=' ')
		{
			length++;
		}
		
		if(s[i]==' ' && length!=0)
		{
			break;
		}
	}

	return length;
}

void main()
{
	char* s = "hello world";
	int length;

	length = lengthOfLastWord(s);
	printf("%d", length);
}
