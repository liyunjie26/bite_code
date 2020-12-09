#include"SeqList.h"

void SeqListInit(SeqList* ps)//初始化
{
	if (ps == NULL)
		return;
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}
void seqListCheckCapacity(SeqList* ps)//检查容量
{
	if (ps->capacity == ps->size)
	{
		int newcapacity = ps->capacity == 0 ? 1 : 2 * ps->capacity;//判断容量是哪一种不够
		SLDateType* tem = (SLDateType*)malloc(newcapacity*sizeof(SLDateType));//申请新的空间
		memcpy(tem, ps->a, sizeof(SLDateType)*ps->size);
		free(ps->a);
		ps->a = tem;
		ps->capacity = newcapacity;

	}

}
void SeqListDestory(SeqList* ps)//摧毁
{
	if (ps != NULL&&ps->a != NULL)
	{
		free(ps->a);
		ps->a = NULL;
	}
}
void SeqListPrint(SeqList* ps)//输出
{
	if (ps == NULL)
		return;
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d", ps->a[i]);
	}
	printf("\n");
}
void SeqListPushBack(SeqList* ps, SLDateType x)//尾插
{
	if (ps == NULL)
		return; 
	seqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void SeqListPushFront(SeqList* ps, SLDateType x)//头插
{
	if (ps == NULL)
		return;
	seqListCheckCapacity(ps);
	int end = ps->size;
	while (end > 0)
	{
		ps->a[end] = ps->a[end - 1];
		end--;
	}
	ps->a[end] = x;
	ps->size++;
}

void SeqListPopFront(SeqList* ps)//头删
{
	if (ps == NULL)
		return;
	int start = 1;
	while (start < ps->size)
	{
		ps->a[start - 1] = ps->a[start];
		start++;
	}
}
void SeqListPopBack(SeqList* ps)//尾删
{
	if (ps == NULL)
		return;
	if (ps->size>0)
		ps->size--;
}
// 顺序表查找

int SeqListFind(SeqList* ps, SLDateType x)
{
	if (ps == NULL || ps->size == 0)
		return;
	int start = 0;
	while (start < ps->size)
	{
		if (ps->a[start] == x)
		{
			printf("have found at %d", start);
			return;
		}
	}
	if (start == ps->size)
	{
		printf("not found\n");
		return;
	}
}
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	if (ps == NULL)
		return;
	seqListCheckCapacity(ps);
	if (pos >= 0 && pos <= ps->size)
	{
		int end = ps->size;
		while (end > pos)
		{
			ps->a[end] = ps->a[end - 1];
			--end;
		}
		ps->a[pos] = x;
		ps->size++;
	}
}
void SeqListErase(SeqList* ps, size_t pos)// 顺序表删除pos位置的值
{
	if (ps == NULL || ps->size == 0)
		return;
	if ((0 <= pos) && (pos < ps->size))
	{
		int start = pos + 1;
		while (start < ps->size)
		{
			ps->a[start - 1] = ps->a[start];
			++start;
		}
	}
	ps->size--;
}