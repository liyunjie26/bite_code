// ��ʽ�ṹ����ʾ���� 

typedef struct QListNode

{

	struct QListNode* _next;

	QDataType _data;

}QNode;



// ���еĽṹ 

typedef struct Queue

{

	QNode* _front;

	QNode* _rear;

}Queue;



// ��ʼ������ 

void QueueInit(Queue* q);

// ��β����� 

void QueuePush(Queue* q, QDataType data);

// ��ͷ������ 

void QueuePop(Queue* q);

// ��ȡ����ͷ��Ԫ�� 

QDataType QueueFront(Queue* q);

// ��ȡ���ж�βԪ�� 

QDataType QueueBack(Queue* q);

// ��ȡ��������ЧԪ�ظ��� 

int QueueSize(Queue* q);

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 

int QueueEmpty(Queue* q);

// ���ٶ��� 

void QueueDestroy(Queue* q);




// ֧�ֶ�̬������ջ

#include<stdio.h>

#include<stdlib.h>

#include<malloc.h>


typedef int STDataType;


typedef struct Stack


{


	STDataType* _a;


	int _top;      // ջ��


	int _capacity; // ���� 


}Stack;


// ��ʼ��ջ 


void StackInit(Stack* ps)

{

	ps->_a = NULL;

	ps->_capacity = ps->_top = 0;


}


// ��ջ ,ֻ��Ҫ����ջʱ��������


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


// ��ջ 


void StackPop(Stack* ps)

{

	if (ps == NULL || ps->_a == NULL)

		return;

	if (ps->_top != 0)

		ps->_top--;

	else

		StackInit(ps);

}


// ��ȡջ��Ԫ�� 


STDataType StackTop(Stack* ps)

{

	if (ps == NULL || ps->_a == NULL)

		return;

	return ps->_a[ps->_top];


}


// ��ȡջ����ЧԪ�ظ��� 


int StackSize(Stack* ps)

{

	if (ps == NULL || ps->_a == NULL)

		return 0;

	return ps->_top + 1;

}


// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 


int StackEmpty(Stack* ps)

{

	if (ps == NULL || ps->_a == NULL)

		return 1;

	return 0;

}


// ����ջ 


void StackDestroy(Stack* ps)

{

	if (ps == NULL)

		return;

	free(ps->_a);

	free(ps);

}






�ο���(�����ɲ鿴)
