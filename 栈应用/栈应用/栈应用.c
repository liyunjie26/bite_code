#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

//����ջ�Ľṹ����غ���
typedef char STDataType;
typedef struct stack
{
	STDataType* _data;
	int _size;
	int _capacity;//ջ������
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
STDataType stackTop(stack* st)
{
	if (st == NULL || st->_size == 0)
		return 0;
	return  st->_data[(st->_size) - 1];
}
int stackEmpty(stack* st)//�п�
{
	if (st == NULL || st->_size == 0)
		return 1;
	else
		return 0;
}
//�жϺ���
bool isRight(char* s)
{
	//����ӳ��
	char map[3][2] = { { '(', ')' }, { '{', '}' }, { '[', ']' } };
	struct stack st;
	initStack(&st);
	while (*s)
	{
		int flag = 0;
		for (int i = 0; i < 3; ++i)//�ж��Ƿ�Ϊ������
		{
			if (*s == map[i][0])
			{
				stackpush(&st, *s);
				//�ж���һ���ַ�
				++s;
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			//ȡ��ջ��Ԫ��,���ж�ջ�Ƿ�Ϊ��
			if (stackEmpty(&st))
				return false;
			char topchar = stackTop(&st);
			stackpop(&st);
			for (int i = 0; i < 3; ++i)//�ж�����һ��ƥ��
			{
				if (map[i][1] == *s)
				{
					if (map[i][0] == topchar)
					{
						//�ж���һ���ַ�
						++s;
						break;
					}
					else
						return false;//û����ȷƥ��
				}
			}
		}

	}
	//�ж�ջ�Ƿ�Ϊ��
	return stackEmpty(&st);
}
void main()
{
	STDataType s[] = "((((}))))";
	bool resulr = isRight(s);
	printf("%d", resulr);


}