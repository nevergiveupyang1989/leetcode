#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
	int max = 0;
	int size = strlen(s);
	int i;
	int dict[256];
	int start = -1;

	memset(dict, -1, sizeof(dict));
	if (NULL == s)
		return 0;

	for (int i = 0; i < size; i++){
		if (dict[s[i]]>start){
			start = dict[s[i]];
		}
		dict[s[i]] = i;

		max = max >= (i - start) ? max : (i - start);
	}

	return max;
}


void main(){
	char* s = "pwwkew";
	int result;

	result = lengthOfLongestSubstring(s);

	printf("%d", result);
}


