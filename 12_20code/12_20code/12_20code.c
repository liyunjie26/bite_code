/*
��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷ
ָ��

*/
#include<stdio.h>
struct ListNode{
	struct ListNode* next;
	int val;
};

struct ListNode* deleteDuplication(struct ListNode *pHead)
{
	struct ListNode* prev, *start, *end;
	if (pHead == NULL||pHead->next == NULL)
		return pHead;
	prev = NULL;
	start = pHead;
	end = pHead->next;
	//...
	while (end)
	{
		if (end&&start->val == end->val)
		{
			while (start->val == end->val)
			{
				struct ListNode*next = end->next;
				free(end);
				end = next;
			}
			if (prev == NULL)
				pHead = start;
			
			start->next = end;
			start = end;
			end = end->next;
			}
		else
		{
			start->next = end;
			end = end->next;
			start = end;

		}
	}
	return pHead;
}
void main()
{}