#include<stdio.h>
void shiftDown(int* arr, int n, int curPos)
{
	//左孩子 curPos 为当前位置坐标   以0下标开始
	int child = 2 * curPos + 1;
	while (child < n)
	{

		//从左右孩子找到一个最小值
		if (child + 1 < n && arr[child + 1] < arr[child])
			++child;
		//需要调整的数据和最小值进行比较
		if (arr[child] < arr[curPos])
		{
			int temp = arr[child];
			arr[child] = arr[curPos];
			arr[curPos] = temp;
			//更新位置
			curPos = child;
			child = 2 * curPos + 1;
		}
		else
			break;
	}
}