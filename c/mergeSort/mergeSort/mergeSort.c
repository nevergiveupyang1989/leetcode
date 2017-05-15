#include <stdio.h>
#include <stdlib.h>


void sort(int a[], int left, int mid, int right, int temp[]){
	int l, r, m, k, i;

	l = left;
	r = mid+1;
	m = mid;

	k = 0;
	while (l<=m && r<=right){
		if (a[l]<=a[r]){
			temp[k++] = a[l++];
		}

		if (a[l]>a[r]){
			temp[k++] = a[r++];
		}
	}

	if (l <= m){
		temp[k++] = a[l++];
	}

	if (r <= right){
		temp[k++] = a[r++];
	}

	for (i = 0; i < k; i++){
		a[left+i] = temp[i];
	}
}


void mergeSort(int a[], int begin, int end, int temp[]){
	int mid;

	if (begin<end){
		mid = (begin + end) / 2;
		mergeSort(a, begin, mid, temp);
		mergeSort(a, mid + 1, end, temp);
		sort(a, begin, mid, end, temp);
	}
}

void main(){
	int a[] = { 4, 1, 2, 3 };
	int left, right, i;
	left = 0;
	right = 3;
	int *result;

	result = (int*)malloc(sizeof(int) * 4);

	mergeSort(a, left, right, result);

	for (i = 0; i < 4; i++){
		printf("%d", a[i]);
	}
}