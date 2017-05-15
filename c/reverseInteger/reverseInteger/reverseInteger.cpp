#include <stdlib.h>
#include <stdio.h>

int reverse(int x) {
	int max = 0x7fffffff;
	int min = 0x80000000;
	long long result;
	int flag = 1;

	if (x < 0)
	{
		flag = 0;
		x = 0 - x;
	}

	result = 0;
	while (x)
	{
		result = result * 10 + x % 10;
		x /= 10;
	}

	if (0 == flag)
	{
		result = 0 - result;
	}

	if (result > max || result < min)
		return 0;

	return result;
}

void main()
{
	int x = 2147483647;
	int m;

	m = reverse(x);
	printf("%d", m);
}