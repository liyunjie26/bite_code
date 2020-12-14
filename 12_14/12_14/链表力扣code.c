//���룺1->2->6->3->4->5->6,val=6
//�����1->2->3->4->5
//�⣺
#include<stdio.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* prev, *cur;//cur��ǰ�жϽڵ㣬prev�����¼�ڵ�
	cur = head;
	prev = NULL;
	while (cur)
	{
		if (cur->val == val)
		{
			struct ListNode* next = cur->next;
			free(cur);//�ͷŵ�ǰ�Ľڵ�
			if (prev == NULL)//�ж��Ƿ�Ϊͷ
				head = next;
			else
				prev->next = next;
			cur = next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}


//1->2->3->4->5->NULL
//5->4->3->2->1->NULL
//�������������������������˵�����鷳�ʲ��ý����µ������Ҳ�ȡͷ��ķ�ʽ
struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode* newhead, *cur, *next;
	newhead = NULL;
	cur = head;
	while (cur)
	{
		next = cur->next;
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}
	return newhead;
}
//����������������ָ�룬����ָ��

struct ListNode* reverseList1(struct ListNode* head)
{
	struct ListNode* n1, *n2, *n3;
	n1 = NULL;
	n2 = head;
	n3 = n2->next;
	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3)
		{
			n3 = n3->next;
		}
	}
	return n1;

}

/*����һ��ͷ���Ϊ head �ķǿյ���������������м��㡣

����������м��㣬�򷵻صڶ����м��㡣
*/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
//����һ���ȱ������õ��ܵĸ�����֮���ҵ�һ���λ��
//������������һ�Σ�ʹ������ָ�룬һ����һ����һ��������
struct ListNode* middleNode(struct ListNode* head)
{
	struct ListNode* step1, *step2;
	step1 = head;
	step2 = head;
	while (step2&&step2->next)
	{
		step1 = step1->next;
		step2 = step2->next->next;
	}
	return step1;


	}
/*
����һ����������������е�����k����㡣
ʾ��1
����
����

1, { 1, 2, 3, 4, 5 }

����ֵ
����

{ 5 }*/
struct ListNode* FindKthToTail(struct ListNode* pListHead, unsigned int k)
{
	struct ListNode* key, *fast;
	key = pListHead;
	fast = pListHead;
	while (key&&fast)
	{
		fast = fast->next;
		k--;
	}
	if (k == 0)
	{
		while (fast)
		{
			key = key->next;
			fast = fast->next;
		}
		return key;
	}
	return NULL;
}
/*��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ� 

 

ʾ����

���룺1->2->4, 1->3->4
�����1->1->2->3->4->4

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/merge-two-sorted-lists
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL || l2 == NULL)
	{
		return l1 == NULL ? l2 : l1;
	}
	struct ListNode* cur1, *cur2, *newhead, *newtail;
	cur1 = l1;
	cur2 = l2;
	newhead = newtail = NULL;
	while (cur1 && cur2)//��������Ϊ�յ�ʱ��
	{
		if (cur1->val <= cur2->val)//ȷ��ͷ����λ��
		{
			if (newhead == NULL)
			{
				newhead = newtail = cur1;
			}
			else{
				newtail->next = cur1;
				newtail = newtail->next;
			}
			cur1 = cur1->next;
		}
		else
		{
			if (newhead == NULL)
			{
				newhead = newtail = cur2;
			}
			else{
				newtail->next = cur2;
				newtail = newtail->next;
			}
			cur2 = cur2->next;
		}

	}
	if (cur1 == NULL)//�ж�ʣ�²�Ϊ�յ���������һ��
		newtail = cur2;
	if (cur2 == NULL)
		newtail = cur1;
	return newtail;
}
//�ڶ��ַ�������ȷ���׽ڵ�����һ��
struct ListNode* mergeTwoLists1(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL || l2 == NULL)
	{
		return l1 == NULL ? l2 : l1;
	}
	struct ListNode* cur1, *cur2, *newhead, *newtail;
	newhead = newtail = (struct ListNode*)malloc(sizeof(struct ListNode));
	cur1 = l1;
	cur2 = l2;
	while (cur1 && cur2)//��������Ϊ�յ�ʱ��
	{
		if (cur1->val <= cur2->val)//ȷ��ͷ����λ��
		{
			
				newtail->next = cur1;
				newtail->next = newtail->next;
				cur1 = cur1->next;
		}
		else
		{
			 newtail->next = cur2;
			 newtail->next = newtail->next;
			 cur2 = cur2->next;
		}

	}
	if (cur1 == NULL)//�ж�ʣ�²�Ϊ�յ���������һ��
		newtail = cur2;
	if (cur2 == NULL)
		newtail = cur1;
	struct ListNode* head;
	head == newhead->next;
	free(newhead);
	return head;
}