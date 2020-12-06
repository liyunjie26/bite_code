/*#include<stdio.h>
#define N 10//比N多一个

int main()
{
	int num[N] = { 0, 1, 2, 8, 4, 5, 6, 9, 7, 3 };//理论上0-n元素共n+1数据，但只使用了n个空间
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
在网上学习大佬的博客，理解大致的思路：
要想达到题目所需要求用异或的方法是最恰当的
其原理在于：
异或的使用方法是相同为0，不同为1，且满足乘法中的交换律。那么对于数组中的元素全部进行异或，最终得到的结果是
两个只出现一次的元素的异或结果。再利用1找出其二进制中第一个1的位置，将其与数组中所有元素相异或（即分成所谓
结果为0与不为0的两个子串，从而可以得到两个结果。*/

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
	printf("个数为1的数字是%d,%d\n",a,b);
}
int main()
{
	int num[10] = { 5, 9, 8, 7, 5, 8, 1, 9, 7, 3 };
	int size = sizeof(num) / sizeof(num[0]);
	find(num, size);
	return 0;
}