#include <stdlib.h>
#include <stdio.h>
#define min(x,y) (x)<(y)?x:y

int maxArea(int* height, int heightSize) {
	int* start;
	int* end;
	int max;
	int tmp;

	start = height;
	end = height + heightSize - 1;
	max = 0;

	if (1 == heightSize)
		return *height;

	while (start != end)
	{
		tmp = (end - start)*(min(*start,*end));
		if (tmp > max)
			max = tmp;

		if (*start < *end)
			start += 1;
		else
		{
			end -= 1;
		}
	}

	return max;
}

void main()
{
	int height[] = { 1, 2, 3, 4 };
	int heightSize = 4;
	int result;


	result = maxArea(height,heightSize);

	printf("%d",result);
}