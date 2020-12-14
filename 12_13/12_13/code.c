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