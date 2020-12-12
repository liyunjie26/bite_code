#include"slist.h"
#include<memory.h>
#include<stdio.h>
#include<malloc.h>

// 动态申请一个节点

SListNode* BuySListNode(SLTDateType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;
	return node;
}

// 单链表打印

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
// 单链表尾插

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

// 单链表的头插

void SListPushFront(SListNode** pplist, SLTDateType x)
{
	if (*pplist == NULL)
		return;
	SListNode* node = BuySListNode(x);//建立新的节点
	SListNode* start = *pplist;
	*pplist = node;
	(*pplist)->next = start;

}

// 单链表的尾删

void SListPopBack(SListNode** pplist)//如果是最后一个节点，则保留节点的位置，内容置NULL
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

// 单链表头删

void SListPopFront(SListNode** pplist)
{
	if (*pplist == NULL)
		return;
	if ((*pplist)->next == NULL)//如果是最后一个节点，则保留节点的位置，内容置NULL
	{
		(*pplist)->data = NULL;
	}
	else{
		SListNode* start = (*pplist)->next;
		free(*pplist);
		*pplist = start;
	}

}

// 单链表查找

SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	if (plist == NULL)
		return NULL;
	while (plist != NULL)
	{
		if (plist->data == x)
		{
			printf("已找到\n");
			return plist;
		}
		else
			plist = plist->next;
	}


}

// 单链表在pos位置之后插入x

// 分析思考为什么不在pos位置之前插入？

void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	if (pos == NULL)
		return;
	SListNode* node = BuySListNode(x);
	node->next = pos->next;
	pos->next = node;

}

// 单链表删除pos位置之后的值

// 分析思考为什么不删除pos位置？

void SListEraseAfter(SListNode* pos)
{
	if (pos == NULL || pos->next == NULL)
		return;
	SListNode* node = pos->next;
	pos->next = node->next;
	free(node);

}

// 单链表的销毁

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
	SListInit(&sl);//测试初始化
	SListPushBack(&sl, 1);//测试尾插
	SListPushBack(&sl, 2);
	//SListPrint(sl);
	SListPushFront(&sl, 3);
	SListPushFront(&sl, 4);
	//SListPushBack(&sl, 4);//测试尾插
	SListPushBack(&sl, 5);
	//SListPrint(sl);
	//SListPopBack(&sl);//测试尾删
	//SListPrint(sl);
	//SListPopFront(&sl);
	//SListPrint(sl);
	//SListPopFront(&sl);
	//SListPrint(sl);
	
	SListPrint(sl);
	SListNode* nn = SListFind(sl, 1);
}