#include<stdio.h>
void shiftDown(int* arr, int n, int curPos)
{
	//���� curPos Ϊ��ǰλ������   ��0�±꿪ʼ
	int child = 2 * curPos + 1;
	while (child < n)
	{

		//�����Һ����ҵ�һ����Сֵ
		if (child + 1 < n && arr[child + 1] < arr[child])
			++child;
		//��Ҫ���������ݺ���Сֵ���бȽ�
		if (arr[child] < arr[curPos])
		{
			int temp = arr[child];
			arr[child] = arr[curPos];
			arr[curPos] = temp;
			//����λ��
			curPos = child;
			child = 2 * curPos + 1;
		}
		else
			break;
	}
}