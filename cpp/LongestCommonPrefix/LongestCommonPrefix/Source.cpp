#include <stdlib.h>
#include <stdio.h>

char* longestCommonPrefix(char** strs, int strsSize) {
	char** pstr;
	pstr = strs;
	int i;

	static char prefix[1000];

	if (0 == strsSize || 1 == strsSize)
		return NULL;

	i = 0;
	while (*(*pstr + i)!= '\0')
	{
		prefix[i] = *(*pstr+i);
		i++;
	}

	prefix[i] = '\0';

	return NULL;
}


void main()
{
	char* result;
	char strs[][4] = {"abc", "abc"};
	result = longestCommonPrefix((char**)strs, 2);

	printf("%s",result);
}