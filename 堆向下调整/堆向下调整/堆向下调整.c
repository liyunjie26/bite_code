
#include<stdio.h>
//����ΪС��
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
			//����λ��
			curpos = child;
			child = 2 * curpos + 1;
		}
		else
			break;

	}

} 
//������
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
//����
void creatHeap(int*arr, int n)
{
//�����һ����Ҷ�ӽڵ㿪ʼ���µ���
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		//shiftDown(����ָ�룬����Ԫ�ظ�������������ʵλ��)
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