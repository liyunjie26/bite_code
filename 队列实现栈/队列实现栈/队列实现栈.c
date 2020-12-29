/*
ʹ�ö���ʵ��ջ�����в�����

push(x) -- Ԫ�� x ��ջ
pop() -- �Ƴ�ջ��Ԫ��
top() -- ��ȡջ��Ԫ��
empty() -- ����ջ�Ƿ�Ϊ��

ע��:

��ֻ��ʹ�ö��еĻ�������-- Ҳ���� push to back, peek/pop from front, size, �� is empty ��Щ�����ǺϷ��ġ�
����ʹ�õ�����Ҳ��֧�ֶ��С� �����ʹ�� list ���� deque��˫�˶��У���ģ��һ������ , ֻҪ�Ǳ�׼�Ķ��в������ɡ�
����Լ������в���������Ч�ģ�����, ��һ���յ�ջ������� pop ���� top ��������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/implement-stack-using-queues
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//�������Ƚ��ȳ����ʣ�������ӿ�ʼ��������һ��Ԫ�أ�֮���ٽ�֮ǰ��Ԫ���ٴ����

typedef int QDateType;
typedef struct QNode
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
	return node;
}
void queuepush(Queue* q, QDateType val)//β��
{
	struct QNode* node = creatNode(val);
	if (q->_head == NULL)
		q->_head = q->_tail = node;
	else
	{
		q->_tail->_next = node;
		q->_tail = node;
	}
	q->size++;
}
void queqePop(Queue* q)//ͷɾ
{
	if (q == NULL || q->_head == NULL)
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
	return q->_head == NULL;
}
int queueSize(Queue* q)
{
	if (q == NULL)
		return 0;
	return q->size;
}
void queueDestory(Queue* q)
{
	QNode* cur = q->_head;
	while (cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_head = q->_tail = NULL;
}


typedef struct MyStack
{
//���г�Ա����
	struct Queue q;

}MyStack;
struct MyStack* myStackCreat()
{
//��̬����
	struct MyStack* pst = (struct MyStack*)malloc(sizeof(struct MyStack));
	initQueue(&pst->q);
	return pst;
}

void myStackpush(MyStack* obj,int x) {
	queuepush(&obj->q, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackpop(MyStack* obj) {
	int n = queueSize(&obj->q);
	while (n > 1)
	{
		--n;
		int front = queueFront(&obj->q);
		queqePop(&obj->q);
		queuepush(&obj->q, front);
	}
	int top = queueFront(&obj->q);
	queqePop(&obj->q);
	return top;
}

/** Get the top element. */
int  myStacktop(MyStack* obj)
//��ȡջ��Ԫ��
{
	return queueBack(&obj->q);
}

/** Returns whether the stack is empty. */
bool  myStackempty(MyStack* obj) {
	return queueEmpty(&obj->q);
}
void myStackdestory(MyStack* obj) {
	queueDestory(&obj->q);
	free(obj);
}
int main()
{}