#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void Show(int *arr, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d   ", arr[i]);
	}
	printf("\n");
}
void BubbleSort(int *arr, int len)
{
	int i = 0;
	int tmp = 0;
	for (i = 0; i < len - 1; i++)
	{
		int j = 0;
		for (j = 0; j < len - i - 1; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	int arr[] = { 4, 7, 3, 2, 6, 8, 1, 5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Show(arr, len);
	BubbleSort(arr, len);
	Show(arr, len);
	return 0;
}