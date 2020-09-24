#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void _MergeSort(int *a, int begin, int end, int* tmp){
	if (begin >= end){
		return;
	}

	int mid = (begin + end) >> 1;
	//先划分
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	//归并两段有序区间
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2){
		if (a[begin1] < a[begin2]){
			tmp[index++] = a[begin1++];
		}
		else{
			tmp[index++] = a[begin2++];
		}
	}
	if (begin1 <= end1){
		while (begin1 <= end1){
			tmp[index++] = a[begin1++];
		}
	}
	else{
		while (begin2 <= end2)
		{
			tmp[index++] = a[begin2++];
		}
	}

	memcpy(a + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}

void MergeSort(int *a, int n){
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

int main()
{
	int a[] = { 7, 6, 3, 0, 2, 7, 4, 8, 5 };
	//int n = sizeof(a) / sizeof(int);
	MergeSort(a, 9);
	for (int i = 0; i < 9; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}