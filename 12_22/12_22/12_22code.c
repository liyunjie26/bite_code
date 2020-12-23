#include<stdio.h>
#include<malloc.h>

struct ListNode
{
	int val;
	struct ListNode * next;

};
struct ListNode* insertionSortList(struct ListNode* head) 
{
	if ( head == NULL || head->next == NULL)
		return head;
	struct ListNode* node=head->next;
	struct ListNode* tail=head;
	while (node)
	{
		
		if (node->val < tail->val)//如果小于则不需要再次找数据
		{
			struct ListNode* prev, *cur;
			prev = NULL;
			cur = head;
			while (cur&&cur->val <= node->val)
			{
				prev = cur;
				cur = cur->next;
			}
		
			tail->next = node->next;
			if (prev)
				prev->next = node;
			else
				head = node;
			node->next = cur;
			node = tail->next;
		}
		else
		{
			tail = tail->next;
			node = tail->next;
		}
	}
	return head;
}