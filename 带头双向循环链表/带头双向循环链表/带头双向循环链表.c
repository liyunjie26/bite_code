#include<stdio.h>
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _val;
	struct ListNode*_next;
	struct ListNode*_prev;
}ListNode;
typedef struct List
{
	ListNode* _head;
}List;
ListNode* ListCreate(LTDataType val)//创建新节点
{

	struct ListNode* node = (struct ListNode*)malloc(sizeof(ListNode));
	node->_val = val;
	node->_prev = NULL;
	node->_next = NULL;
	return node;
}
void listInit(struct List* lst)
{
	lst->_head=ListCreate(0);
	lst->_head->_prev = lst->_head;
	lst->_head->_next = lst->_head;
}
void ListPushBack(List* lst, LTDataType x)//尾插
{
	struct ListNode* newnode = ListCreate(x);
	struct ListNode* tail = lst->_head->_prev;
	lst->_head->_prev = newnode;
	newnode->_next = lst->_head;
	tail->_next = newnode;
	newnode->_prev = tail;
	
}
void listpopback(struct List* lst)//尾删
{
	if (lst->_head->_prev == lst->_head)
		return ;
	struct ListNode* tail = lst->_head->_prev;
	struct ListNode* prev = tail->_prev;
	free(tail);
	prev->_next = lst->_head;
	lst->_head->_prev = prev;
}
void ListPushFront(List* lst, LTDataType x)//头插
{
	struct ListNode* newnode = ListCreate(x);
	struct ListNode* next = lst->_head->_next;
	newnode->_next = next;
	newnode->_prev = lst->_head;
	lst->_head->_next = newnode;
	next->_prev = newnode;

}
void listpophead(struct List* lst)//头删
{
	if (lst->_head->_next == lst->_head)
		return;
	struct ListNode* next = lst->_head->_next;
	struct ListNode* nextnext = next->_next;
	free(next);
	lst->_head->_next = nextnext;
	nextnext->_prev = lst->_head;

}
void listInsert(ListNode* node, LTDataType val)//在任意节点-之前插入新节点
{
	struct ListNode* newnode = ListCreate(val);
	struct ListNode* prev=node->_prev;
	newnode->_next = node;
	node->_prev = newnode;
	newnode->_prev = prev;
	prev->_next = newnode;
}
void listErase(ListNode* node)//删除任意节点
{
	if (node->_next == node)
		return;
	struct ListNode* prev = node->_prev;
	struct ListNode* next = node->_next;
	prev->_next = next;
	next->_prev = prev;
	free(node);
}
void listprint(List* lst)
{
	if (lst->_head->_next == lst->_head)
		return;
	struct ListNode* cur = lst->_head->_next;
	while (cur!= lst->_head)
	{
		printf("%d\t",cur->_val);
		cur = cur->_next;
	}
	printf("\n");
}
void main()
{
	struct List lst;
	listInit(&lst);
	ListPushFront(&lst, 1);
	ListPushFront(&lst, 2);
	ListPushFront(&lst, 3);
	ListPushFront(&lst, 4);
	listprint(&lst);
	listpophead(&lst);
	listprint(&lst);
	listpophead(&lst);
	listprint(&lst);
	listpophead(&lst);
	listprint(&lst);
	listpophead(&lst);
	listprint(&lst);
	ListPushFront(&lst, 1);
	ListPushFront(&lst, 2);
	ListPushFront(&lst, 3);
	ListPushFront(&lst, 4);
	listpopback(&lst);
	listprint(&lst);
	listpopback(&lst);
	listprint(&lst);
	listpopback(&lst);
	listprint(&lst);
}