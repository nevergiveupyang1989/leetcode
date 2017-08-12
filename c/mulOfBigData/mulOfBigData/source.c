#include <stdio.h>
#include <stdio.h>
#include <string.h>
#define MAX 200

char ans1[MAX] = {0};
char ans2[MAX] = {0};
char result[MAX] = {0};

int mulOfBigData(char* nums1, char* nums2)
{
	int size1,size2;
	int i,j;
	int mulSize;	
	int isPositive;	

	size1 = strlen(nums1);
	size2 = strlen(nums2);
	
	mulSize = size1+size2+1;	
	isPositive = 1;	
	
	if(nums1[0] == '-' || nums2[0] == '-')
	{
		isPositive = 0;
	}

	j = 0;
	for(i=size1-1; i>=0; i--)
	{
		ans1[j++] = nums1[i] - '0';
	}
	
	j = 0;
	for(i=size2-1; i>=0; i--)
	{
		ans2[j++] = nums2[i] - '0';
	}

	for(i=0; i<mulSize; i++)
	{
		for(j=0; j<size1; j++)
		{
			result[i] += ans2[i]*ans1[j];
			
			if(result[i]>10)
			{
				result[i] -= 10;
				result[i+1]++;
				result[i] += '0';
			}
		}
	}
	
	if(result[mulSize-1]==0)
		mulSize -= 1;
	
	if(isPositive == 0)
	{	
		result[mulSize] = '-';
		mulSize++;
	}
	
	return mulSize;
}

void main()
{
	char nums1[MAX]={0};
	char nums2[MAX]={0};
	int size;	
	int i;	

	scanf("%s", nums1);
	scanf("%s", nums2);

	size = mulOfBigData(nums1, nums2);

	for(i=size-1; i>=0; i--)
	{
		printf("%c", result[i]);
	}
}
