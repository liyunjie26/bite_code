#include<stdio.h>
struct ListNode{
	struct ListNode* next;
	int val;
};
struct ListNode* deleteDuplication(struct ListNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	struct ListNode* head=(struct ListNode*)malloc(sizeof(struct ListNode)) ;
	head->next = pHead;
	struct ListNode* pnode = head;
	struct ListNode* end = pnode->next;
	while(end!=NULL)
	{
		while (end->next!=NULL&&end->val != end->next->val)
		{
			pnode = pnode->next;
			end = end->next;
		}
		while (end->next != NULL&&end->val == end->next->val)
		{
			end = end->next;
		}
		if (pnode->next != end)
		{
			pnode->next = end->next;
		}
		end = end->next;
	}
	return head->next;
}
void main()
{}