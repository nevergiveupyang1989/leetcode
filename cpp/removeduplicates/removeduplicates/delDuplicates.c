#define _CRT_SECURE_NO_DEPRECATE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

int delDuplicates(char s[], int length){// ±º‰∏¥‘”∂»O£®n£©°£
	int i,j;
	i = 0;
	j = 0;

	while (++j<length){
		if (s[i]!=s[j]){
			s[++i] = s[j];
		}
	}
	j = 0;
	while (j<=i){
		printf("%c\n", s[j++]);
	}

	return j - i;
}

int main(){
	char s[MAX];
	int length;
	int ret;
	int i = 0;
	int num;
	
	printf("print the number:\n");
	scanf("%d", &num);
	fflush(stdin);
	printf("print a string:\n");
	while (i<num){
		scanf("%c", &s[i++]);
	}

	delDuplicates(s, num);
}