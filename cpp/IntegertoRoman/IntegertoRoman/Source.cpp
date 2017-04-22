#include <stdio.h>
#include<stdlib.h>
#include <string.h>


char* intToRoman(int num) {
	char* result;
	char row;
	char* head;
	int size;
	int i,j;
	int tmp;

	char* roman[][10] = {
		{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
		{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
		{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
		{ "", "M", "MM", "MMM" }
	};

	result = (char*)malloc(sizeof(char) * 100);

	row = 3;
	head = result;
	tmp = 1000;

	for (j = 0; j < 4;j++)
	{
		if (num>0 && num < 10)
		{
			row = 0;
			size = strlen(roman[row][num]);
			for (i = 0; i < size; i++)
			{
				*result++ = roman[row][num][i];
			}
			num /= 10;
		}
		if (num>=10)
		{
			size = strlen(roman[row][num / tmp]);
			for (i = 0; i < size; i++)
			{
				*result++ = roman[row][num / tmp][i];
			}
			num = num % tmp;
			tmp /= 10;
			row -= 1;
		}
	}
	
	*result= '\0';
	return head;
}

void main()
{
	int obj = 1;
	char* result;

	result = intToRoman(obj);
	
	printf("%s", result);
	free(result);
}