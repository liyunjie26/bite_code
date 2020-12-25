#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

//创建栈的结构及相关函数
typedef char STDataType;
typedef struct stack
{
	STDataType* _data;
	int _size;
	int _capacity;//栈的容量
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
STDataType stackTop(stack* st)
{
	if (st == NULL || st->_size == 0)
		return 0;
	return  st->_data[(st->_size) - 1];
}
int stackEmpty(stack* st)//判空
{
	if (st == NULL || st->_size == 0)
		return 1;
	else
		return 0;
}
//判断函数
bool isRight(char* s)
{
	//括号映射
	char map[3][2] = { { '(', ')' }, { '{', '}' }, { '[', ']' } };
	struct stack st;
	initStack(&st);
	while (*s)
	{
		int flag = 0;
		for (int i = 0; i < 3; ++i)//判断是否为左括号
		{
			if (*s == map[i][0])
			{
				stackpush(&st, *s);
				//判断下一个字符
				++s;
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			//取出栈顶元素,先判断栈是否为空
			if (stackEmpty(&st))
				return false;
			char topchar = stackTop(&st);
			stackpop(&st);
			for (int i = 0; i < 3; ++i)//判断与哪一个匹配
			{
				if (map[i][1] == *s)
				{
					if (map[i][0] == topchar)
					{
						//判断下一个字符
						++s;
						break;
					}
					else
						return false;//没有正确匹配
				}
			}
		}

	}
	//判断栈是否为空
	return stackEmpty(&st);
}
void main()
{
	STDataType s[] = "((((}))))";
	bool resulr = isRight(s);
	printf("%d", resulr);


}