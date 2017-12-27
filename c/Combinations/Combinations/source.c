#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int a[MAX];
int cnt;

void combine(int n, int k) {
    int i;
    int j;

    for(i=n; i>=k; i--)
    {
	    a[k] = i;
	    if(k>1)
	    {
		combine(n-1, k-1); 
	    }
	    else
	    {
		cnt++;
		for(j=a[0]; j>0; j--)
		{
			printf("%d", a[j]);
		}
		printf("\n");		
	    }
    }
}

void main()
{
	int n,k;

	n=4;
	k=2;

	a[0] = k;
	combine(n,k);
	printf("%d", cnt);
}
