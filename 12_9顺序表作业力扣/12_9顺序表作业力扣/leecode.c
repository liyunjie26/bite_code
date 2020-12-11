//4.旋转数组
/*#include<stdio.h>
void change(int* arr, int key, int size)
{
	int end;
	int tem;
	while (key--)
	{
		end = size - 1;
		tem = arr[end];
		while (end > 0)
		{
			arr[end] = arr[end - 1];
			end--;
		}
		arr[end] = tem;
	}
}
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int key = 3;
	int size = sizeof(arr) / sizeof(arr[0]);
	change(arr, key, size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}*/


//3.合并两个有序数组
/*
#include<stdio.h>
void merge(int* arr1, int m, int* arr2, int n)
{
	int i = m - 1;
	int j = n - 1;
	int end = m + n - 1;
	while (i >= 0 && j >= 0)
	{
		if (arr1[i] > arr2[j])
			arr1[end] = arr1[i];
		else
			arr1[end] = arr1[j];
	}
	if (j >=0)
	{
		memcpy(arr1, arr2, sizeof(int)*(j + 1));
	}
}*/
/*#include<stdio.h>
int remove(int* nums, int numsSize)
{
	if (numsSize <= 1)
		return numsSize;
	int i = 0, j = 0, idx = 0;
	nums[idx] = nums[i];
	for (; j < numsSize; ++j)
	{
		if (nums[j] == nums[i])
			continue;
		else
		{
			i = j;
			nums[++idx] = nums[i];
		}
	}
	idx += 1;
	return idx;
}*/


#include<stdio.h>
int add(int* A, int ASize, int k, int* ReturnSize) {
	//计算正数k的位数
	int len = 0;
	int num = k;
	while (num)
	{
		len++;
		num /= 10;
	}
	//申请数组
	int arrlen = len > ASize ? len + 1 : ASize + 1;
	int* arr = (int*)malloc(sizeof(int)*arrlen);
	int step = 0;
	int end = ASize - 1;
	int cursum;
	int index = 0;
	while (end > 0 || k > 0)
	{
		//逐位相加
		cursum = step;
		if (end >= 0)
			cursum += A[end];
		if (k > 0)
			cursum += k % 10;
		if (cursum > 9)
		{
			step = 1;
			cursum -= 10;
		}
		else
			step = 0;
		arr[index] = cursum;
		k /= 10;
		end--;

	}
	if (step == 1)
		arr[index++] = 1;
	int start = 0;
	end = index - 1;
	while (start < end)
	{
		int tem = arr[start];
		arr[start] = arr[end];
		arr[end] = tem;
		start++;
		end--;
		*ReturnSize = index;
		return arr;

	}
}