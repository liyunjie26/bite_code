// 支持动态增长的栈
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int STDataType;

typedef struct Stack

{

	STDataType* _a;

	int _top;		// 栈顶

	int _capacity;  // 容量 

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
	ps->_a[ps->_top] = data;
	ps->_top++;
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
	if(ps==NULL||ps->_a==NULL)
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
test()
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps, 1);
	StackPush(&ps, 2);

	StackPush(&ps, 3);

	StackPush(&ps, 4);
	StackPush(&ps, 5);






}
int main()
{
	test();
	return 0;
}

