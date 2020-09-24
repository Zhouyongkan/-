#include<stdio.h>


void InsertSort(int*a, int n)//直接插入排序
{
	for (int i = 0; i<n - 1; ++i) //int a[] = { 2, 5, 6, 3, 8, 5, 9 };
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void Shellsort(int* a,int n)//int a[] = { 2, 5, 6, 3, 8, 5, 9 };
{
	int gap=n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//+1是保证最后一定是1
		for (int i = 0; i<n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;
		}
	}
}


int main()
{
	int a[] = { 2, 5, 6, 3, 8, 5, 9 };
	//InsertSort(a, 7);
	Shellsort(a, 7);
	for (int i = 0; i < 7; ++i)
	{
		printf("%d", a[i]);
	}
	printf("\n");

	return 0;
}