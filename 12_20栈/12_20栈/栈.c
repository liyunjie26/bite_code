#include<stdio.h>
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
void checkCapacity(stack* st)//ÈÝÁ¿¼ì²é
{
	if (st->_capacity == st->_size)
	{
		int newCap = st->_capacity == 0 ? 1 : 2 * st->_capacity;
		st->_data = (STDataType*)realloc(st->_data,sizeof(STDataType)*newCap);
		st->_capacity = newCap;
	}
}
void stackpush(stack* st, STDataType val)//Ñ¹Õ»
{
	if (st == NULL)
		return;
	checkCapacity(st);
	st->_data[st->_size++] = val;
}
void stackpop(stack* st)//³öÕ»
{
	if (st == NULL || st->_size == 0)
		return;
	--st->_size;
}
int stackEmpty(stack* st)//ÅÐ¿Õ
{
	if (st == NULL || st->_size == 0)
		return 1;
	else
		return 0;
}
STDataType stackTop(stack* st)//È¡Õ»¶¥ÔªËØ
{
	if (st == NULL || st->_size == 0)
		return 0;
	return  st->_data[(st->_size) - 1];
}
int main()
{
	struct stack st;
	initStack(&st);
	STDataType c = 'a';
	stackpush(&st, 1);
 }