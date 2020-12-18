#include<stdio.h>

#include<stdbool.h>
struct ListNode
{
	int val;
	struct ListNode* next;
}; 
bool chkPalindrome(struct ListNode* A)
{
	if (A == NULL || A->next == NULL)
		return true;
	struct ListNode* slow, *fast, *newhead, *cur, *head;//head保护头节点指针
	head = slow = fast = A;
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