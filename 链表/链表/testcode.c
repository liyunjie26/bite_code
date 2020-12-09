//定义节点：数据+指针
#include<stdio.h>
#include<stdlib.h>
typedef int LDataType;
typedef struct listNode
{
	LDataType _data;
	struct listNode* _next;
}listNode;
//链表
typedef struct list
{
	//保存第一个个节点的地址
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
void listPuahBack(list* sl, LDataType val)//尾插
{
	if (sl == NULL)
		return;
	if (sl->_head == NULL)
	{
		//创建节点
		sl->_head=creatNode(val);
	}
	else
	{
		//遍历找到最后一个
		listNode* tail = sl->_head;
		while (tail->_next != NULL)
		{
			tail = tail->_next;
		}
		tail->_next = creatNode(val);
	}
}
void listPopBack(list* sl)//尾删
{
	if (sl == NULL || sl->_head == NULL)
		return;
	//遍历，找到最后一个节点
	struct listNode* prev = NULL;
	struct listNode* tail = sl->_head;
	while (tail->_next != NULL)
	{
		prev = tail;
		tail = tail->_next;
	}
	//释放最后一个节点
	free(tail);
	if (sl->_head->_next == NULL)
		sl->_head = NULL;
	else
		prev->_next = NULL;
}
void listlistPuahFont(list* sl, LDataType val)//头插
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
void listPopFront(list* sl)//头删法
{
	if (sl == NULL || sl->_head == NULL)
		return;
	struct listNode* next = sl->_head->_next;
	free(sl->_head);
	sl->_head = next;

}

void listInsertAfter(listNode* node,LDataType val)//在某一节点之后插入
{
	if (node == NULL)
		return;
	struct listNode* newNode = creatNode(val);
	struct listNode* next = node->_next;
	node->_next = newNode;
	newNode->_next = next;
}
void listEraseAfter(listNode* node)//删除某一位置之后的节点
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
	{//释放当前字节
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