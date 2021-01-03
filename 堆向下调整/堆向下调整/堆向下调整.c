
#include<stdio.h>
//假设为小堆
void shiftDown(int *arr, int n, int curpos)
{
	int child = 2 * curpos + 1;
	while (child < n)
	{
		if (child+1<n && arr[child + 1] < arr[child])
			child++;
		if (arr[child] < arr[curpos])
		{
			int temp = arr[child];
			arr[child] = arr[curpos];
			arr[curpos] = temp;
			//更新位置
			curpos = child;
			child = 2 * curpos + 1;
		}
		else
			break;

	}

} 
//假设大堆
void shiftDown_1(int *arr, int n, int curpos)
{
	int child = 2 * curpos + 1;
	while (child < n)
	{
		if (child + 1 < n&&arr[child + 1] > arr[child])
			++child;
		if (arr[child]>arr[curpos])
		{
			int temp = arr[child];
			arr[child] = arr[curpos];
			arr[curpos] = temp;
			curpos = child;
			child = 2 * curpos + 1;
		}
		else
			break;
	}
}
//建堆
void creatHeap(int*arr, int n)
{
//从最后一个非叶子节点开始向下调整
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		//shiftDown(数组指针，数组元素个数，调整的其实位置)
		shiftDown(arr, n, i); 
	}
}
void test()
{
	int arr[] = { 10, 5, 3, 8, 7, 6 };
	shiftDown(arr, sizeof(arr) / sizeof(arr[0]), 0);
}
int main()
{
	test();
	return 0;
}