//使用两个栈
/*
规则：
入队：入队栈操作
出队：出队栈：
      非空：正常出队
	  为空：首先将入队栈中元素存入出栈队，在进行出栈
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
void checkCapacity(stack* st)//容量检查
{
	if (st->_capacity == st->_size)
	{
		int newCap = st->_capacity == 0 ? 1 : 2 * st->_capacity;
		st->_data = (STDataType*)realloc(st->_data, sizeof(STDataType)*newCap);
		st->_capacity = newCap;
	}
}
void stackpush(stack* st, STDataType val)//压栈
{
	if (st == NULL)
		return;
	checkCapacity(st);
	st->_data[st->_size++] = val;
}
void stackpop(stack* st)//出栈
{
	if (st == NULL || st->_size == 0)
		return;
	--st->_size;
}
int stackEmpty(stack* st)//判空
{
	if (st == NULL || st->_size == 0)
		return 1;
	else
		return 0;
}
STDataType stackTop(stack* st)//取栈顶元素
{
	if (st == NULL || st->_size == 0)
		return 0;
	return  st->_data[(st->_size) - 1];
}





typedef struct MyQueue
{
//定义栈成员
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
//入队栈push
	stackpush(&obj->pushST, x);


}


int myqueuePop(MyQueue* obj)
{
	//判断出队栈是否为空
	int front;
	if (!stackEmpty(&obj->popST))
	{
		front = stackTop(&obj->popST);
		stackpop(&obj->popST);
	}
	else
	{
		//将入队栈元素存入出队栈
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

int myqueuePeek(MyQueue* obj)//获取队头元素
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