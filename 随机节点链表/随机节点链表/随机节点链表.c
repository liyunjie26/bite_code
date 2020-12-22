#include<stdio.h>
#include<malloc.h>


typedef struct ListNode {

	int val;
struct	ListNode* next;
struct	ListNode* random;
}ListNode;



/*����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣

Ҫ�󷵻��������� �����

������һ���� n ���ڵ���ɵ���������ʾ����/����е�����ÿ���ڵ���һ�� [val, random_index] ��ʾ��

val��һ����ʾ Node.val ��������
random_index�����ָ��ָ��Ľڵ���������Χ�� 0 �� n-1���������ָ���κνڵ㣬��Ϊ  null ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/copy-list-with-random-pointer
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������*/

ListNode* copyRandomList(ListNode* head)
{
	if (head == NULL)
		return head;
struct	ListNode* cur = head;
	//��������
	while (cur)
	{
	struct ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
		newNode->val = cur->val;
		newNode->next = cur->next;
		cur->next = newNode;
		cur = newNode->next;
	}
	//�������ָ��
	cur = head;
	while (cur)
	{
		struct ListNode* copy = cur->next;
		if (cur->random)
			copy->random = cur->random->next;
		else
			copy->random = NULL;
		cur = copy->next;
	}
	//����
	struct ListNode* newhead = NULL;
	cur = head;
	newhead = cur->next;
	while (cur)
	{
		struct ListNode* copy = cur->next;
		struct ListNode* next = copy->next;
		if (next)
			copy->next = next->next;
		cur->next = next;
		cur = next;
	}
	return newhead;
}
void main()
{
}