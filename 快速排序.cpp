#include<stdio.h>
#include<string.h>

void Swap(int *p1, int *p2){
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void BubbleSort(int *a, int n){
	
	for (int i = 0; i < n; ++i)
	{
		int flag = 1;
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (a[j + 1] > a[j])
			{
				Swap(&a[j + 1], &a[j]);
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}

//三数取中法
int GetMidIndex(int* a, int begin, int end){
	int mid = (begin + end) >> 1;//相当于(begin+end)/2

	if (a[begin] < a[mid]){
		if (a[mid] < a[end]){
			return mid;
		}
		else if (a[begin] < a[end]){// a[mid]>a[end]
			return end;
		}
		else
			return begin;
	}
	else{//a[begin]>a[mid]
		if (a[mid] > a[end]){
			return mid;
		}
		else if (a[begin] > a[end]){//a[mid]<a[end]
			return end;
		}
		else
			return begin;
	}
}


int PartSort(int *a, int begin, int end){
	int midindex = GetMidIndex(a, begin, end);
	Swap(&a[midindex], &a[end]);
	int key = a[end];
	int keyindex = end;
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyindex]);
	return begin;
}

//挖坑法
int PartSort2(int *a, int begin, int end){
	int key = a[end];
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}
		a[end] = a[begin];
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		a[begin] = a[end];
	}
	a[begin] = key;
	return begin;

}

//前后指针
int PartSort3(int *a,int begin,int end)
{
	int key = a[end];
	int cur = begin;
	int prev = cur-1;
	while (cur != end)
	{
		if (a[cur] >= key){
			++cur;
		}
		else{
			++prev;
			Swap(&a[prev], &a[cur]);
			++cur;
		}
	}
	prev++;
	Swap(&a[prev], &a[end]);
	return prev;
}

void QuickSort(int *a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int keyindex = PartSort(a, begin, end);
	QuickSort(a, begin, keyindex - 1);
	QuickSort(a, keyindex + 1, end);
}


#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stack>

using namespace std;

//非递归
void QuickSortNonR(int *a, int begin, int end){
	//栈来模拟递归
	stack<int> st;
	
	st.push(begin);
	st.push(end);

	while (!st.empty()){
		int right = st.top();
		st.pop();
		int left = st.top();
		st.pop();


		int keyindex = PartSort(a, left, right);

		if (left < keyindex){
			st.push(left);
			st.push(keyindex - 1);
		}
		if (keyindex + 1 < right){
			st.push(keyindex + 1);
			st.push(right);
		}
	}
}



int main()
{
	int a[] = { 2, 6, 4, 8, 4, 8, 3 };
	//BubbleSort(a, 7);
	//QuickSort(a, 0, 6);
	QuickSortNonR(a, 0, 6);
	for (int i = 0; i < 7; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}