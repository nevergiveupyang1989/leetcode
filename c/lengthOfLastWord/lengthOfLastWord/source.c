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
	i = strLength-1;

	while(s[i]== ' ')
		i--;
	
	while(s[i]!= ' ')
	{
		i--;
		length++;
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
