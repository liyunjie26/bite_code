#include<stdio.h>
/*����һ������ nums ��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ���� val ��Ԫ�أ��������Ƴ���������³��ȡ�

��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢 ԭ�� �޸��������顣

Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-element
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
int remove(int* nums, int numsSize, int val)
{
	int i = 0, idx = 0;
	for (; i < numsSize; ++i)
	{
		if (nums[i] != val)
		{
			nums[idx++] = nums[i];
		}
	}
	return idx;
}
/*����һ���������飬����Ҫ�� ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�

��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
int removeDuplicates(int* nums, int numsSize)
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
}
/*�������������������� nums1 �� nums2�����㽫 nums2 �ϲ��� nums1 �У�ʹ nums1 ��Ϊһ���������顣

 

˵����

    ��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n ��
    ����Լ��� nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ�ء�

 

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/merge-sorted-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������*/
void merge(int* nums1, int m, int*  nums2, int n)
{
	int i = m - 1, j = n - 1; 
	int dex = m + n - 1;//�Ӻ���ǰ
	while (i >= 0 && j >= 0)
	{
		if (nums1[i] >= nums2[j])
			nums1[dex--] = nums1[i--];
		else
			nums1[dex--] = nums1[j--];
	}
	if (j >= 0)
	{
		memcpy(nums1, nums2, sizeof(int)*(j + 1));
	}
}
/*������ʽ�����*
*/
int addToArrayForm(int* A, int ASize,int k,int* ReturnSize) {
	//��������k��λ��
	int len = 0;
	int num = k;
	while (num)
	{
		len++;
		num /= 10;
	}
	//��������
	int arrlen = len > ASize ? len + 1 : ASize + 1;
	int* arr = (int*)malloc(sizeof(int)*arrlen);
	int step = 0;
	int end = ASize - 1;
	int cursum ;
	int index = 0;
	while (end > 0 || k > 0)
	{
		//��λ���
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
int main()
{
	int arr[10] = { 0, 1, 1, 2, 2, 3, 3, 3, 4, 5 };
	int num=removeDuplicates(arr, 10);
	return 0;
}