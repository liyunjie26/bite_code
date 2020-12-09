//����ڵ㣺����+ָ��
#include<stdio.h>
#include<stdlib.h>
typedef int LDataType;
typedef struct listNode
{
	LDataType _data;
	struct listNode* _next;
}listNode;
//����
typedef struct list
{
	//�����һ�����ڵ�ĵ�ַ
	listNode* _head; 
	
}list;
listNode* creatNode(LDataType val)
{
	listNode* node = (LDataType*)malloc(sizeof(listNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}

void listInit(list* sl)
{
	if (sl == NULL)
		return;
	sl->_head = NULL;
}
void listPuahBack(list* sl, LDataType val)//β��
{
	if (sl == NULL)
		return;
	if (sl->_head == NULL)
	{
		//�����ڵ�
		sl->_head=creatNode(val);
	}
	else
	{
		//�����ҵ����һ��
		listNode* tail = sl->_head;
		while (tail->_next != NULL)
		{
			tail = tail->_next;
		}
		tail->_next = creatNode(val);
	}
}
void listPopBack(list* sl)//βɾ
{
	if (sl == NULL || sl->_head == NULL)
		return;
	//�������ҵ����һ���ڵ�
	struct listNode* prev = NULL;
	struct listNode* tail = sl->_head;
	while (tail->_next != NULL)
	{
		prev = tail;
		tail = tail->_next;
	}
	//�ͷ����һ���ڵ�
	free(tail);
	if (sl->_head->_next == NULL)
		sl->_head = NULL;
	else
		prev->_next = NULL;
}
void listlistPuahFont(list* sl, LDataType val)//ͷ��
{
	if (sl == NULL)
		return;
	//struct listNode* prev = sl->_head->_next;
	struct listNode* node = creatNode(val);
	//sl->_head->_next = node;
	//node->_next = prev;
	node->_next = sl->_head;
	sl->_head = node;
}
void listPopFront(list* sl)//ͷɾ��
{
	if (sl == NULL || sl->_head == NULL)
		return;
	struct listNode* next = sl->_head->_next;
	free(sl->_head);
	sl->_head = next;

}

void listInsertAfter(listNode* node,LDataType val)//��ĳһ�ڵ�֮�����
{
	if (node == NULL)
		return;
	struct listNode* newNode = creatNode(val);
	struct listNode* next = node->_next;
	node->_next = newNode;
	newNode->_next = next;
}
void listEraseAfter(listNode* node)//ɾ��ĳһλ��֮��Ľڵ�
{
	if (node == NULL || node->_next == NULL)
		return;
	struct listNode* next = node->_next;
	struct listNode* nextnext = next->_next;
	free(next);
	node->_next = nextnext;
}
listNode* listFind(list* sl, LDataType val)
{
	if (sl == NULL || sl->_head == NULL)
		return NULL;
	struct listNode* cur = sl->_head;
	while (cur)
	{
		if (cur->_data == val)
			return cur;
		else
			cur = cur->_next;
	}
	return NULL;

}
void listDestory(list* sl)
{
	if (sl == NULL)
		return;
	struct listNode* start = sl->_head;
	struct listNode* next = start->_next;
	while (start)
	{//�ͷŵ�ǰ�ֽ�
		free(start);
		start = next;
		next = start->_next;
	}
	sl->_head = NULL;
	}
void main()
{
	list sl;
	listInit(&sl);
	listPuahBack(&sl, 1);
	listPuahBack(&sl, 2);
	listPuahBack(&sl, 3);
	listPuahBack(&sl, 4);
	listPuahBack(&sl, 5);
	listPuahBack(&sl, 6);
	return 0;

}