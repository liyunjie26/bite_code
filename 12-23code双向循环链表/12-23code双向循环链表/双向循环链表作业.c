#include<stdio.h>
#include<stdlib.h>

typedef int LTDataType;

typedef struct ListNode

{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
// �������������ͷ���.
ListNode* ListCreate()
{
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->_prev = head->_next = head;
	return head;
}
// ˫����������

void ListDestory(ListNode* pHead)
{
	if (pHead == NULL)
		return;
	struct ListNode* tnode = pHead->_next;
	while (tnode != pHead)
	{
		struct ListNode* next = tnode->_next;
		pHead->_next = next;
		next->_prev = pHead;
		free(tnode);
		tnode = next;
	}
}
// ˫�������ӡ

void ListPrint(ListNode* pHead)
{
	if (pHead->_next == pHead)
		return;
	struct ListNode* cur =pHead->_next;
	while (cur != pHead)
	{
		printf("%d\t", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
// ˫������β��

void ListPushBack(ListNode* pHead, LTDataType x)
{
	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->_data = x;
	struct ListNode* tail = pHead->_prev;
	pHead->_prev = node;
	node->_prev = tail;
	tail->_next = node;
	node->_next = pHead;
}

// ˫������βɾ

void ListPopBack(ListNode* pHead)
{
	if (pHead->_next == pHead)
		return;
	struct ListNode* tail = pHead->_prev;
	struct ListNode* prev = tail->_prev;
	pHead->_prev = prev;
	prev->_next = pHead;
	free(tail);
}

// ˫������ͷ��

void ListPushFront(ListNode* pHead, LTDataType x)
{
	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->_data = x;
	struct ListNode* next = pHead->_next;
	pHead->_next = node;
	node->_prev = pHead;
	node->_next = next;
	next->_prev = node;
}

// ˫������ͷɾ

void ListPopFront(ListNode* pHead)
{
	struct ListNode* cur = pHead->_next;
	struct ListNode* next = cur->_next;
	pHead->_next = next;
	next->_prev = pHead;
	free(cur);
}

// ˫���������

ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	if (pHead == NULL)
		return NULL;
	struct ListNode* cur = pHead->_next;
	while (cur->_next != pHead)
	{
		if (cur->_data == x)
			return cur;
		else
			cur = cur->_next;
	}
	return NULL;
}

// ˫��������pos��ǰ����в���

void ListInsert(ListNode* pos, LTDataType x)
{
	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->_data = x;
	struct ListNode* prev = pos->_prev;
	prev->_next = node;
	node->_prev = prev;
	node->_next = pos;
	pos->_prev = node;

}

// ˫������ɾ��posλ�õĽڵ�

void ListErase(ListNode* pos)
{
	if (pos->_next == pos)
		return;
	struct ListNode* prev = pos->_prev;
	struct ListNode* next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);

}
void main()
{
	struct ListNode* phead;
	phead = ListCreate();

	ListPushBack(phead, 1);
	ListPushBack(phead, 1);
	ListPushBack(phead, 1);
	ListPrint(phead);
	ListPopBack(phead);
	ListPrint(phead);
	ListPushFront(phead, 3);
	ListPrint(phead);
	ListPopFront(phead);
	ListPrint(phead);



}


