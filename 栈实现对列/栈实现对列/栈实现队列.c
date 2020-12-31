//ʹ������ջ
/*
����
��ӣ����ջ����
���ӣ�����ջ��
      �ǿգ���������
	  Ϊ�գ����Ƚ����ջ��Ԫ�ش����ջ�ӣ��ڽ��г�ջ
*/

#include<stdio.h>
#include<stdlib.h>
typedef int STDataType;

typedef struct stack
{
	STDataType* _data;
	int _size;
	int _capacity;
}stack;

void initStack(stack* st)
{
	if (st == NULL)
		return;
	st->_data = NULL;
	st->_capacity = st->_size = 0;
}
void checkCapacity(stack* st)//�������
{
	if (st->_capacity == st->_size)
	{
		int newCap = st->_capacity == 0 ? 1 : 2 * st->_capacity;
		st->_data = (STDataType*)realloc(st->_data, sizeof(STDataType)*newCap);
		st->_capacity = newCap;
	}
}
void stackpush(stack* st, STDataType val)//ѹջ
{
	if (st == NULL)
		return;
	checkCapacity(st);
	st->_data[st->_size++] = val;
}
void stackpop(stack* st)//��ջ
{
	if (st == NULL || st->_size == 0)
		return;
	--st->_size;
}
int stackEmpty(stack* st)//�п�
{
	if (st == NULL || st->_size == 0)
		return 1;
	else
		return 0;
}
STDataType stackTop(stack* st)//ȡջ��Ԫ��
{
	if (st == NULL || st->_size == 0)
		return 0;
	return  st->_data[(st->_size) - 1];
}





typedef struct MyQueue
{
//����ջ��Ա
	stack pushST;
	stack popST;
}MyQueue;

MyQueue* myqueueCreat()
{
	MyQueue* pd = (MyQueue*)malloc(sizeof(MyQueue));
	initStack(&pd->popST);
	initStack(&pd->pushST);
	return pd;
}

void myqueuePush(MyQueue* obj, int x)
{
//���ջpush
	stackpush(&obj->pushST, x);


}


int myqueuePop(MyQueue* obj)
{
	//�жϳ���ջ�Ƿ�Ϊ��
	int front;
	if (!stackEmpty(&obj->popST))
	{
		front = stackTop(&obj->popST);
		stackpop(&obj->popST);
	}
	else
	{
		//�����ջԪ�ش������ջ
		while (!stackEmpty(&obj->pushST))
		{
			stackpush(&obj->popST, stackTop(&obj->pushST));
			stackpop(&obj->pushST);
		}
		front = stackTop(&obj->popST);
		stackpop(&obj->popST);
	}
	return front;
}

int myqueuePeek(MyQueue* obj)//��ȡ��ͷԪ��
{
	if (stackEmpty(&obj->popST))
	{
		while (!stackEmpty(&obj->pushST))
		{
			stackpush(&obj->popST, stackTop(&obj->pushST));
			stackpop(&obj->pushST);
		}
	}
	return stackTop(&obj->popST);
}
void myqueueEmpty(MyQueue* obj)
{
	return stackEmpty(&obj->popST) && stackEmpty(&obj->pushST);
}
int main()
{
	return 0;
}