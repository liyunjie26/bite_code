/*
6.现有一链表的头指针 ListNode* pHead，给一定值x，
编写一段代码将所有小于x的结点排在其余结点之前，
且不能改变原来的数据顺序，
返回重新排列后的链表的头指针。
*/
//采用两个链表，分别记录小于x，大于x的节点，最后连接，只需要遍历一遍就行
//不用头结点直接有效节点
#include<stdio.h>
#include<malloc.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
ListNode* partition(ListNode* pHead, int x)
{
	struct  ListNode* greath, *greatl, *ulessh, *ulessl,*cul;
	greath=greatl=ulessh=ulessl=NULL;
	cul = pHead;
	while (cul)
	{
		if (cul->val < x)
		{
			if (greatl == NULL)
			{
				greath = greatl = cul;
			}
			else
			{
				greatl->next = cul;
				greatl = greatl->next;

			}
			cul = cul->next;
		}
		else
		{
			if (ulessl == NULL)
			{
				ulessh = ulessl = cul;
			}
			else
			{
				ulessl->next = cul;
				ulessl = ulessl->next;
			}
			cul = cul->next;
		}
	}
	if (ulessl)
		ulessl->next = NULL;
	if (greath == NULL)//小链表为空
		return ulessh;
	if (ulessh == NULL)
	{
		if (greatl)
			greatl->next = NULL;
		return greath;
	}
	greatl->next = ulessh;
	return greath;
	
}


//使用头结点



ListNode* partition(ListNode* pHead, int x)
{
	struct  ListNode* greath, *greatl, *ulessh, *ulessl, *cul;
	greath = greatl = (struct ListNode*)malloc(sizeof(struct  ListNode));
	ulessh = ulessl = (struct ListNode*)malloc(sizeof(struct  ListNode));

	cul = pHead;
	while (cul)
	{
		if (cul->val < x)
		{
			
				greatl->next = cul;
				greatl = greatl->next;
				cul = cul->next;
		}
		else
		{
				ulessl->next = cul;
				ulessl = ulessl->next;
				cul = cul->next;
		}
	}
	if (ulessl)
		ulessl->next = NULL;
	
	greatl->next = ulessh->next;
	struct ListNode* newhead = greath;
	free(greath);
	free(ulessh);
	return greath;

}
