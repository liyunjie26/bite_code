// 链式结构：表示队列 

typedef struct QListNode

{

	struct QListNode* _next;

	QDataType _data;

}QNode;



// 队列的结构 

typedef struct Queue

{

	QNode* _front;

	QNode* _rear;

}Queue;



// 初始化队列 

void QueueInit(Queue* q);

// 队尾入队列 

void QueuePush(Queue* q, QDataType data);

// 队头出队列 

void QueuePop(Queue* q);

// 获取队列头部元素 

QDataType QueueFront(Queue* q);

// 获取队列队尾元素 

QDataType QueueBack(Queue* q);

// 获取队列中有效元素个数 

int QueueSize(Queue* q);

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 

int QueueEmpty(Queue* q);

// 销毁队列 

void QueueDestroy(Queue* q);




// 支持动态增长的栈

#include<stdio.h>

#include<stdlib.h>

#include<malloc.h>


typedef int STDataType;


typedef struct Stack


{


	STDataType* _a;


	int _top;      // 栈顶


	int _capacity; // 容量 


}Stack;


// 初始化栈 


void StackInit(Stack* ps)

{

	ps->_a = NULL;

	ps->_capacity = ps->_top = 0;


}


// 入栈 ,只需要在入栈时进行扩容


void StackPush(Stack* ps, STDataType data)

{

	if (ps == NULL)

		return;

	if (ps->_capacity == ps->_top)

	{

		int size = ps->_capacity == 0 ? 1 : ps->_capacity * 2;

		STDataType* b = (STDataType*)realloc(ps->_a, sizeof(STDataType)*size);

		ps->_a = b;

		ps->_capacity = size;

	}

	ps->_a[ps->_top++] = data;

}


// 出栈 


void StackPop(Stack* ps)

{

	if (ps == NULL || ps->_a == NULL)

		return;

	if (ps->_top != 0)

		ps->_top--;

	else

		StackInit(ps);

}


// 获取栈顶元素 


STDataType StackTop(Stack* ps)

{

	if (ps == NULL || ps->_a == NULL)

		return;

	return ps->_a[ps->_top];


}


// 获取栈中有效元素个数 


int StackSize(Stack* ps)

{

	if (ps == NULL || ps->_a == NULL)

		return 0;

	return ps->_top + 1;

}


// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 


int StackEmpty(Stack* ps)

{

	if (ps == NULL || ps->_a == NULL)

		return 1;

	return 0;

}


// 销毁栈 


void StackDestroy(Stack* ps)

{

	if (ps == NULL)

		return;

	free(ps->_a);

	free(ps);

}






参考答案(答题后可查看)
