#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
	int size = strlen(s);
	int i,j,m;
	char* result;
	int index;

	if (1 == numRows || size <= numRows)
		return s;

	result = (char*)malloc(sizeof(char)*(size+1));
	if (NULL == result)
		return NULL;

	m = 0;

	for (int i = 0; i < numRows; i++)
	{
		for (int j = i; j < size; j+= 2*(numRows-1))
		{
			result[m++] = s[j];

			if (i != 0 && i != numRows - 1)
			{
				index = j + 2 * (numRows - 1) - 2 * i;

				if (index < size)
				{
					result[m++] = s[index];
				}
			}
		}
	}

	result[size] = '\0';
	return result;
}

void main()
{
	char* result=NULL;
	char* s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
	int nRows;

	nRows = 61;
	result = convert(s, nRows);

	printf("%s", result);
	free(result);
}



