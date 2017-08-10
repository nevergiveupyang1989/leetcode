#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 200
#define MAX 200

char ans1[MAX];
char ans2[MAX];

void swap(char* nums1, int size1, char* nums2, int size2)
{
	char* temp;
	int i;
	
	return;
}

int subOfBigData(char* nums1, char* nums2)
{
	int size1;
	int size2;
	int isPositive;	
	int i,j;	
	int maxSize;	
	int sumSize;	

	isPostive = 1;
	size1 = strlen(nums1);
	size2 = strlen(nums2);
	
	memset(ans1, 0, MAX);
	memset(ans2, 0, MAX);
	
	maxSize = (size1>size2)?size1:size2;

	if(size1<size2)
	{
		swap(nums1,size1,nums2,size2);
		isPositive = 0;
	}
	
	j=0;
	for(i=size1-1; i>=0; i--)
	{
		ans1[j++] = nums1[i];
	}

	j=0;
	for(i=size2-1; i>=0; i--)
	{
		ans2[j++] = nums2[i];
	}

	for(i=0; i<MAX; i++)
	{
		ans1[i] = (ans1[i]-'0') - (ans2[i]-'0');
		
		if(ans1[i]<0)
		{
			ans1[i] += 10;
			ans1[i+1]--;
		}
	}
	
	sumSize = (ans1[maxSize-1]!=0)?(maxSize-1):(maxSize-2);
	
	return sumSize;
}

void main(){}
