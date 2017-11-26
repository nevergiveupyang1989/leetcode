#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INT_MAX 0x7fffffff

char* substr(char* s, int start, int end)
{
	int i,j;
	int size;
	char* newString;

	newString = (char*)malloc(sizeof(char)*(end-start+1));

	if(NULL==newString)
		return NULL;

	j = 0;
	for(i=start; i<end; i++)
	{
		newString[j++] = s[i];
	}
	newString[end-start] = '\0';

	return newString;	
}

char* minWindow(char* s, char* t)
{
	int d,i;
	int start,end;
	char map[128];
	int tSize,sSize;
	int cnt;
	char* sStr;
	
	sStr = NULL;
	if(0 == strcmp(s, "") || 0 == strcmp(t, ""))
		return "";

	memset(map, 0, sizeof(char)*128);
	start = 0;
	end = 0;

	d =INT_MAX;
	tSize = strlen(t);
	cnt = tSize;
	
	for(i=0; i<tSize; i++)
	{
		map[t[i]]++;
	}

	sSize = strlen(s);
	while(end<sSize)
	{
		if(map[s[end++]]-->0)
		{
			cnt--;
		}
		
		while(cnt==0)
		{
			if(end- start < d)
			{
				d = end - start;
			}

			if(map[s[start++]]++ == 0)
			{
				cnt++;
			}
		}		
	}

	return d==INT_MAX?"":substr(s, start-1, start+d-1);
}

void main()
{
	char* s;
	char* t;
	char* result;

	s = "lcwxsxalbjprcinbjkjqwntkjxiwejeplcofcordziwdsjhbvqrrdkeokmkoyrdlvtrxjkciuymmktohlhzosfdctpsrixfeqwdzigjcexqqseydmzugezkzqetzbyftwiueodivdylvfjbtivzowlomphlqhqjdzfjpitklryjwhkpshqgdbwpsfdimttruycmjvwwpwfnerfyyvebzdtr";
	t = "iwcxrxqmytahqwffvntz";
	result = minWindow(s, t);
	printf("%s", result);

	free(result);
}
