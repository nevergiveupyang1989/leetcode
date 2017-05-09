#define _CRT_SECURE_NO_DEPRECATE
#include <stdlib.h>
#include <stdio.h>

int fib(int);

int main(){
	int result;
	int num;

	scanf("%d", &num);
	result = fast_fib(num);
	printf("%d", result);
}

int fib(int n){ //ตÝน้
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	return fib(n - 1) + fib(n - 2);
}

