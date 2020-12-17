#include<stdio.h>

#include<stdbool.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* cur, *pre;
	cur = head;
	pre = NULL;
	while (cur)
	{
		struct ListNode* next = cur->next;
		if (cur->val == val)
		{
			free(cur);
			if (pre == NULL)
				head = next;
			else
				pre->next = next;
			cur = next;
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
}

struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode* newhead,*next;
	newhead = NULL;
	next = head;
	while (next)
	{
		struct ListNode* cur = next->next;
		next->next = newhead;
		newhead = next;
		next = cur;
	}
	return newhead;

}


struct ListNode* middleNode(struct ListNode* head)
{
	if (head == NULL)
		return NULL;
	struct ListNode* st1, *st2;
	st1 = head;
	st2 = head;

	while (st2&&st2->next)//当st2节点存在时
	{
		st1 = st1->next;
		st2 = st2->next->next;
	
	}
	return st1;
}

struct ListNode* FindKthToTail(struct ListNode* pListHead, unsigned int k)
{
//判断k位置是否合法
	int i = 0;
	struct ListNode* cur, *key;
	cur = key = pListHead;
	while (cur)
	{
		i++;
		cur = cur->next;
	}
	cur = pListHead; 
	if (i >= k)
	{
		while (k > 0)
		{
			cur = cur->next;
			k--;
		}
		while (cur)
		{
			cur = cur->next;
			key = key->next;
		}
	}
	else

	{
		printf("the k is longer then length\n");
		return NULL;
	}
	return key;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL || l2 == NULL)
	{
		return l1 == NULL ? l2 : l1;
	}
	struct ListNode* newhead,*newtail = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* ln1 = l1;
	struct ListNode* ln2 = l2;
	while (ln1&&ln2)
	{
		if (ln1->val <= ln2->val)
		{
			newtail->next = ln1;
			newtail = newtail->next;
			ln1 = ln1->next;
		}
		else
		{
			newtail->next = ln2;
			newtail = newtail->next;
			ln2 = ln2->next;
		}
	}
	if (ln1 == NULL)
		newtail->next = ln2;
	if (ln2 == NULL)
		newtail->next = ln1;
	struct ListNode* head;
	head = newhead->next;
	free(newhead);
	return head;

}



struct ListNode* partition(struct ListNode* pHead, int x)
{
	if (pHead == NULL)
		return NULL;
	struct ListNode* Bhead, *Bless, *Lhead, *Lless, *cur;
	Bhead = Bless = (struct ListNode*)malloc(sizeof(struct ListNode));
	Lhead = Lless = (struct ListNode*)malloc(sizeof(struct ListNode));
	cur = pHead;
	while (cur)
	{
		if (cur->val < x)
		{
			Lless->next = cur;
			Lless = Lless->next;
			cur = cur->next;
		}
		else
		{
			Bless->next = cur;
			Bless = Bless->next;
			cur = cur->next;
		}
	}
	if (Bless)
		Bless->next = NULL;
	Lless->next = Bhead->next;
	struct ListNode* newhead = Lhead->next;
	free(Bhead);
	free(Lhead);
	return newhead;
}

//链表的回文结构
bool chkPalindrome(struct ListNode* A)
{
	if (A == NULL || A->next == NULL)
		return true;
	struct ListNode* slow, *fast, *newhead,*cur,*head;//head保护头节点指针
	head=slow = fast = A;
	while (fast&& fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	newhead = NULL;
	cur = slow;
	while (cur)
	{
		struct ListNode* next = cur->next;//记录下一个要遍历到的节点
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}
	while (head && newhead)
	{
		if (head->val != newhead->val)
			return false;
		head = head->next;
		newhead = newhead->next;
	}
	return true;
}