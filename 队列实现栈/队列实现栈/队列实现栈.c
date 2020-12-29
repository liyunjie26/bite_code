/*
使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空

注意:

你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-stack-using-queues
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//队列是先进先出，故，我们因从开始输出到最后一个元素，之后再将之前的元素再次入队

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
void queuepush(Queue* q, QDateType val)//尾插
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
void queqePop(Queue* q)//头删
{
	if (q == NULL || q->_head == NULL)
		return;
	struct QNode* node = q->_head->_next;
	free(q->_head);
	q->_head = node;
	if (node == NULL)
		q->_tail = NULL;//空对列
	q->size--;
}
QDateType queueFront(Queue* q)
{
	//返回头结点的值
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
//队列成员变量
	struct Queue q;

}MyStack;
struct MyStack* myStackCreat()
{
//动态创建
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
//获取栈顶元素
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