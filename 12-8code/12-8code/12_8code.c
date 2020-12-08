#include<stdio.h>
/*给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
/*给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
/*给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

 

说明：

    初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
    你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
void merge(int* nums1, int m, int*  nums2, int n)
{
	int i = m - 1, j = n - 1; 
	int dex = m + n - 1;//从后向前
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
/*数组形式的相加*
*/
int addToArrayForm(int* A, int ASize,int k,int* ReturnSize) {
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
	int cursum ;
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
int main()
{
	int arr[10] = { 0, 1, 1, 2, 2, 3, 3, 3, 4, 5 };
	int num=removeDuplicates(arr, 10);
	return 0;
}