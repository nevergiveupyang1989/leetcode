#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 200

char ans1[MAX+1];
char ans2[MAX+1];

int sumOfBigData(char* nums1, char* nums2)
{
	int i,j;
	int isStart;	
	int size1;
	int size2;	
	int sumSize;
	int maxSize;

	memset(ans1, 0, MAX+1);
	memset(ans2, 0, MAX+1);
	
	size1 = strlen(nums1);
	size2 = strlen(nums2);	
	
	maxSize = (size1>size2)?size1:size2;
	
	j=0;
	for(i=size1-1;i>=0; i--)
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
		
		ans1[i] = (ans1[i]-'0')+(ans2[i]-'0');
		
		if( ans1[i]>10)
		{
			ans1[i] -= 10;
			ans1[i+1]++;
		}
	}

	sumSize = (nums1[maxSize]>0)?(maxSize+1):maxSize;
	
	return sumSize;
	/*isStart = 0;
	for(i=MAX; i>=0; i++)
	{
		if(isStart)
			printf("%d", ans1[i]);	
		
		if(ans1[i])
		{
			printf("%d", ans1[i]);
			isStart = 1;
		}
	}*/
}

void main()
{
	char nums1[MAX];
	char nums2[MAX];
	int size;	

	scanf("%s", nums1);
	scanf("%s", nums2);
	size = sumOfBigData(nums1, nums2);

	printf("%d", size);
}

