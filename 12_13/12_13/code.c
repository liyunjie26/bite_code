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