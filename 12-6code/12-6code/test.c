/*#include<stdio.h>
#define N 10//��N��һ��

int main()
{
	int num[N] = { 0, 1, 2, 8, 4, 5, 6, 9, 7, 3 };//������0-nԪ�ع�n+1���ݣ���ֻʹ����n���ռ�
	int num1[N + 1];
	for (int i = 0; i < N + 1; ++i)
	{
		num1[i] = N + 1;
	}
	for (int i = 0; i < N; ++i)
	{
		num1[num[i]] = 0;
	}
	for (int i = 0; i < N + 1; ++i)
	{
		if (num1[i] == N + 1)
		{
			printf("the number is %d", i);
		}
	}
	return 0;
}

*/

/*
������ѧϰ���еĲ��ͣ������µ�˼·��
Ҫ��ﵽ��Ŀ����Ҫ�������ķ�������ǡ����
��ԭ�����ڣ�
����ʹ�÷�������ͬΪ0����ͬΪ1��������˷��еĽ����ɡ���ô���������е�Ԫ��ȫ������������յõ��Ľ����
����ֻ����һ�ε�Ԫ�ص��������������1�ҳ���������е�һ��1��λ�ã�����������������Ԫ������򣨼��ֳ���ν
���Ϊ0�벻Ϊ0�������Ӵ����Ӷ����Եõ����������*/

#include<stdio.h>
void find(int* num, int size)
{
	int ret = 0;
	int a, b,c;
	a = 0; 
	b = 0;
	for (int i = 0; i < size; ++i)
	{
		ret ^= num[i];
	}
	c = 1;
	while ((ret & c) == 0)
	{
		c =c << 1;
	}
	for (int i = 0; i < size; ++i)
	{
		if ((c & num[i]) == 0)
			a ^= num[i];
		else
			b ^= num[i];
	}
	printf("����Ϊ1��������%d,%d\n",a,b);
}
int main()
{
	int num[10] = { 5, 9, 8, 7, 5, 8, 1, 9, 7, 3 };
	int size = sizeof(num) / sizeof(num[0]);
	find(num, size);
	return 0;
}