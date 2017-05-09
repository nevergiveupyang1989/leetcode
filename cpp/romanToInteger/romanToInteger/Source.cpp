#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int romanToInt(char* s) {
	int i;
	int size;
	char c;
	int ans;

	ans = 0;
	size = strlen(s);
	for (i = size-1; i >=0; i--)
	{
		c = s[i];
		switch (c)
		{
		case 'I':
		{
			ans += (ans >= 5 ? -1 : 1);
			break;
		}

		case 'V':
		{
			ans += 5;
			break;
		}

		case 'X':
		{
			ans += 10 * (ans >= 50 ? -1 : 1);
			break;
		}

		case 'L':
		{
			ans += 50;
			break;
		}

		case 'C':
		{
			ans += 100 * (ans >= 500 ? -1 : 1);
			break;
		}

		case 'D':
		{
			ans += 500;
			break;
		}

		case 'M':
		{
			ans += 1000;
			break;
		}
		default:
			break;
		}
	}

	return ans;
}

