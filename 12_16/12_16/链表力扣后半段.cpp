/*
6.����һ�����ͷָ�� ListNode* pHead����һ��ֵx��
��дһ�δ��뽫����С��x�Ľ������������֮ǰ��
�Ҳ��ܸı�ԭ��������˳��
�����������к�������ͷָ�롣
*/
//�������������ֱ��¼С��x������x�Ľڵ㣬������ӣ�ֻ��Ҫ����һ�����
//����ͷ���ֱ����Ч�ڵ�
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
	if (greath == NULL)//С����Ϊ��
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


//ʹ��ͷ���



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
