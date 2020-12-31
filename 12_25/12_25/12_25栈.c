#include<stdio.h>
#include<stdlib.h>

typedef int QDateType;
typedef struct QNode//����
{
	struct QNode* _next;
	QDateType _val;
}QNode;
typedef struct Queue
{
	struct QNode* _head;
	struct QNode* _tail;
	int size;
}Queue;
void initQueue(Queue* q)
{
	if (q == NULL)
		return;
	q->_head = q->_tail = NULL;
	q->size = 0;
}
QNode* creatNode(QDateType val)
{
	struct QNode* node = (struct QNode*)malloc(sizeof(QNode));
	node->_next = NULL;
	node->_val = val;
}
void queuepush(Queue* q, QDateType val)//β��
{
	struct QNode* node = creatNode(val);
	if (q->_head == NULL)
		q->_head=q->_tail = node;
	else
	{
		q->_tail->_next = node;
		q->_tail = node;
	}
	q->size++;
}
void queqePop(Queue* q)//ͷɾ
{
	if (q == NULL||q->_head==NULL)
		return;
	struct QNode* node = q->_head->_next;
	free(q->_head);
	q->_head = node;
	if (node == NULL)
		q->_tail = NULL;//�ն���
	q->size--;
}
QDateType queueFront(Queue* q)
{
//����ͷ����ֵ
	return q->_head->_val;
}
QDateType queueBack(Queue* q)
{
	return q->_tail->_val;
}
int queueEmpty(Queue* q)
{
	return q->_head==NULL;
}
int queueSize(Queue* q)
{
	return q->size;
}
void test()
{
	struct Queue q;
	initQueue(&q);
	queuepush(&q, 1);
	queuepush(&q, 1);
	queuepush(&q, 1);
	queuepush(&q, 1);
}
void main()
{
	test();
	return 0;
}
