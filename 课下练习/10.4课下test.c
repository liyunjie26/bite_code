//1.��������ͷ�ת
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include"function.h"
int Sort(int arr[], int n)
{
	int i, j, temp;
	for (i = 0; i < n-1; ++i)
	{
		for (j = 0; j < n - 1-i;++j)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return 1;
}
int Resever(int arr[], int n)
{
	int low = 0;
	int high = n - 1;
	int temp;
	while (low <= high)
	{
		temp = arr[low];
		arr[low] = arr[high];
		arr[high] = temp;
		low++;
		high--;
	}
}
/*int main()
{
	int i;
	int arr[] = { 32, 25, 21, 4, 52, 65, 87, 41, 23, 54, 21, 22, 98, 99, 65 };
	int n = sizeof(arr) / sizeof(arr[0]);
	Sort(arr, n);
	for (i = 0; i < n; i++)
	{
		printf("%d	", arr[i]);
	}
	printf("\n");
	Resever(arr, n);
	for (i = 0; i < n; i++)
	{
		printf("%d	", arr[i]);
	}
	printf("\n");
}*/
//�ж�����


bool Is_prime_0(int num)//�����жϺ���
{
	int i;
	if (num == 1)//ͨ���жϷ����ų�1,2����
		return 0;
	else if (num == 2)
		return 1;
	else
	{
		for (i = 3; i < sqrt(num); ++i)
		{
			if (num % i == 0)
			{
				return false;
				break;
			}
		}
		return true;

	}
}
int Is_prime(int num)//�����жϺ���
{
	int i;
	if (num == 1)//ͨ���жϷ����ų�1,2����
		return 0;
	else if (num == 2)
		return 1;
	else
	{
		for (i = 2; i < sqrt(num); ++i)
		{
			if (num%i == 0)
			{
				return 0;
				break;
			}
		}
		return 1;
	}
}
/*int main()
{
	int n;
	printf("�����������жϵ����֣�>");
	scanf("%d", &n);
	int flag = Is_prime(n);
	if (flag == 1)
	{
		printf("%d������", n);
	}
	else
		printf("%d��������", n);

}
*/
//�ж��Ƿ�Ϊ����
int Is_Lead(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return 1;
	}
	else
		return 0;
}
//���ֲ���
int find(int arr[], int top, int tail, int num)
{
	int mid;
	mid = (top + tail) / 2;
	if ((tail == top) && (arr[top] != num))
	{
		printf("we can't find!\n");
		return 0;
	}
	if (num == arr[mid])
	{
		printf("we have find it at %d\n", mid + 1);
		return 1;
	}
	if (num < arr[mid])
		return find(arr, top, mid - 1, num);
	if (num>arr[mid])
		return find(arr, mid + 1, tail, num);
}
//ÿ����һ��num+1
int add(int *num)
{
	*num=*num+1;
	return 1;
}
/*int main()
{
	int i,n = 0;
	for (i = 0; i < 5; i++)
	{
		add(&n);
		printf("%d	", n);
	}
	return 0;
}*/