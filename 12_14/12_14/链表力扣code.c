//输入：1->2->6->3->4->5->6,val=6
//输出：1->2->3->4->5
//解：
#include<stdio.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* prev, *cur;//cur当前判断节点，prev后面记录节点
	cur = head;
	prev = NULL;
	while (cur)
	{
		if (cur->val == val)
		{
			struct ListNode* next = cur->next;
			free(cur);//释放当前的节点
			if (prev == NULL)//判断是否为头
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
//解析：如果交换，对于链表来说过于麻烦故采用建立新的链表并且采取头插的方式
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
//方法二，定义三个指针，更改指向

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

/*给定一个头结点为 head 的非空单链表，返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。
*/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
//方法一：先遍历，得到总的个数，之后找到一半的位置
//方法二，遍历一次，使用两个指针，一个走一步，一个走两步
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
输入一个链表，输出该链表中倒数第k个结点。
示例1
输入
复制

1, { 1, 2, 3, 4, 5 }

返回值
复制

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
/*将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
	while (cur1 && cur2)//两个都不为空的时候
	{
		if (cur1->val <= cur2->val)//确定头结点的位置
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
	if (cur1 == NULL)//判断剩下不为空的链表是哪一个
		newtail = cur2;
	if (cur2 == NULL)
		newtail = cur1;
	return newtail;
}
//第二种方法，不确定首节点是哪一个
struct ListNode* mergeTwoLists1(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL || l2 == NULL)
	{
		return l1 == NULL ? l2 : l1;
	}
	struct ListNode* cur1, *cur2, *newhead, *newtail;
	newhead = newtail = (struct ListNode*)malloc(sizeof(struct ListNode));
	cur1 = l1;
	cur2 = l2;
	while (cur1 && cur2)//两个都不为空的时候
	{
		if (cur1->val <= cur2->val)//确定头结点的位置
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
	if (cur1 == NULL)//判断剩下不为空的链表是哪一个
		newtail = cur2;
	if (cur2 == NULL)
		newtail = cur1;
	struct ListNode* head;
	head == newhead->next;
	free(newhead);
	return head;
}