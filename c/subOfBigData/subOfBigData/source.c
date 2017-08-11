#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 200

char ans1[MAX]={0};
char ans2[MAX]={0};

int subOfBigData(char* nums1, char* nums2)
{
	int size1;
	int size2;
	int isPositive;	
	int i,j;	
	int maxSize;	
	int subSize;	
	char* temp;	

	isPositive= 1;
	size1 = 0;
	size2 = 0;
	
	while(nums1[size1]!='\0')
		size1++;
	
	while(nums2[size2]!='\0')
		size2++;

	maxSize = (size1>size2)?size1:size2;

	if(size1<size2 || (size1==size2) && nums1[size1-1]< nums2[size2-1] )
	{
		temp = nums2;
		nums2 = nums1;
		nums1 = temp;
		isPositive = 0;
	}
	
	j=0;
	for(i=size1-1; i>=0; i--)
	{
		ans1[j++] = nums1[i]-'0';
	}

	j=0;
	for(i=size2-1; i>=0; i--)
	{
		ans2[j++] = nums2[i]-'0';
	}

	for(i=0; i<MAX; i++)
	{
		ans1[i] = ans1[i] - ans2[i];
		
		if(ans1[i]<0)
		{
			ans1[i] = 0 - ans1[i];
			ans1[i+1]--;
		}
		ans1[i] += '0';
	}
	
	subSize = (ans1[maxSize-1]!=0)?maxSize:(maxSize-1);
	
	if(isPositive==0)
	{
		ans1[subSize] = '-';
		subSize++;
	}

	return subSize;
}

void main()
{
	char nums1[MAX]={0};
	char nums2[MAX]={0};
	int size;
	int i;
	int isPrint;	

	scanf("%s", nums1);
	scanf("%s", nums2);

	size = subOfBigData(nums1, nums2);
	
	isPrint = 0;
	for(i=MAX; i>=0; i--)
	{
		if (isPrint!=0)
			printf("%c", ans1[i]);	
		
		if (ans1[i]!= '0' && isPrint==0)
		{
			printf("%c", ans1[i]);
			isPrint = 1;	
		}
	}
}
