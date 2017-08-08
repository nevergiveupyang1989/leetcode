#include <stdlib.h>
#include <stdio.h>
#define MAX 200

int* ans1[MAX+1];
int* ans2[MAX+1];

void sumOfBigData(char* nums1, char* nums2)
{
	int i,j;
	int isStart;	
	int size1;
	int size2;	

	memset(ans1, 0, sizeof(ans1));
	memset(ans2, 0, sizeof(ans2));
	
	size1 = strlen(nums1);
	size2 = strlen(nums2);	
	
	j=0;
	for(i=size1-1;i>=0; i--)
	{
		ans1[j++] = nums1[i]-'0';
	}
	
	j=0;
	for(i=size2-1; i>=0; i--)
	{
		ans2[j++] = nums2[i]-'0';
	}
	
	carry = 0;
	
	for(i=MAX; i>0; i--)
	{
		ans1[i] += ans2[i];
		
		if(ans1[i]>10)
		{
			ans1[i] -= 10;
			ans1[i+1]++;
		}
	}

	
	isStart = 0;
	for(i=MAX; i>=0; i++)
	{
		if(isStart)
			printf("%d", ans1[i]);	
		
		if(ans1[i])
		{
			printf("%d", ans1[i]);
			isStart = 1;
		}
	}
}

void main()
{
	char nums1[MAX];
	char nums2[MAX];

	scanf("%s", nums1);
	scanf("%s", nums2);
	
	sumOfBigData(nums1, nums2);
}

