#include"slist.h"
#include<memory.h>
#include<stdio.h>
#include<malloc.h>

// ��̬����һ���ڵ�

SListNode* BuySListNode(SLTDateType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;
	return node;
}

// �������ӡ

void SListPrint(SListNode* plist)
{
	if (plist == NULL)
		return;
	SListNode* node = plist;
	while (node->next != NULL)
	{
		printf("%d\t", node->data);
		node = node->next;
	}
	printf("%d\n", node->data);
}
void SListInit(SListNode** plist)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = NULL;
	node->next = NULL;
	(*plist) = node;
	
}
// ������β��

void SListPushBack(SListNode** pplist, SLTDateType x)
{
	if (*pplist == NULL)
		return;
	SListNode* node=BuySListNode(x);
	SListNode** start = pplist;
	if ((*start)->data == NULL)
	{
		*start = node;
	}
	else
	{
		while ((*start)->next != NULL)
		{
			start = &((*start)->next);
		}
		(*start)->next = node;
	}
	
		
}

// �������ͷ��

void SListPushFront(SListNode** pplist, SLTDateType x)
{
	if (*pplist == NULL)
		return;
	SListNode* node = BuySListNode(x);//�����µĽڵ�
	SListNode* start = *pplist;
	*pplist = node;
	(*pplist)->next = start;

}

// �������βɾ

void SListPopBack(SListNode** pplist)//��������һ���ڵ㣬�����ڵ��λ�ã�������NULL
{
	if (*pplist == NULL)
		return;
	if ((*pplist)->next == NULL)
	{
		(*pplist)->data = NULL;
	}
	else{
		SListNode* start = *pplist;
		SListNode* start1 = (*pplist)->next;
		while (start1->next != NULL)
		{
			start = start1;
			start1 = start1->next;
		}
		free(start1);
		start->next = NULL;
	}
}

// ������ͷɾ

void SListPopFront(SListNode** pplist)
{
	if (*pplist == NULL)
		return;
	if ((*pplist)->next == NULL)//��������һ���ڵ㣬�����ڵ��λ�ã�������NULL
	{
		(*pplist)->data = NULL;
	}
	else{
		SListNode* start = (*pplist)->next;
		free(*pplist);
		*pplist = start;
	}

}

// ���������

SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	if (plist == NULL)
		return NULL;
	while (plist != NULL)
	{
		if (plist->data == x)
		{
			printf("���ҵ�\n");
			return plist;
		}
		else
			plist = plist->next;
	}


}

// ��������posλ��֮�����x

// ����˼��Ϊʲô����posλ��֮ǰ���룿

void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	if (pos == NULL)
		return;
	SListNode* node = BuySListNode(x);
	node->next = pos->next;
	pos->next = node;

}

// ������ɾ��posλ��֮���ֵ

// ����˼��Ϊʲô��ɾ��posλ�ã�

void SListEraseAfter(SListNode* pos)
{
	if (pos == NULL || pos->next == NULL)
		return;
	SListNode* node = pos->next;
	pos->next = node->next;
	free(node);

}

// �����������

void SListDestory(SListNode* plist)
{
	if (plist == NULL)
		return;
	while (plist != NULL)
	{
		SListNode* node = plist->next;
		free(plist);
		plist = node;
	}
}



void main()
{
	SListNode* sl;
	SListInit(&sl);//���Գ�ʼ��
	SListPushBack(&sl, 1);//����β��
	SListPushBack(&sl, 2);
	//SListPrint(sl);
	SListPushFront(&sl, 3);
	SListPushFront(&sl, 4);
	//SListPushBack(&sl, 4);//����β��
	SListPushBack(&sl, 5);
	//SListPrint(sl);
	//SListPopBack(&sl);//����βɾ
	//SListPrint(sl);
	//SListPopFront(&sl);
	//SListPrint(sl);
	//SListPopFront(&sl);
	//SListPrint(sl);
	
	SListPrint(sl);
	SListNode* nn = SListFind(sl, 1);
}