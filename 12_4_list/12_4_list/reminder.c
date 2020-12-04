#include"reminder.h"
#include<stdio.h>
#include<malloc.h>
#include<memory.h>
void Initialization(Listcode* sl)
{
	if (sl == NULL)
		return;
	sl->list = NULL;
	sl->size = 0;
	sl->capacity = 0;
}
void Dilatation(Listcode* sl)
{
	variable* tem;
	if(sl == NULL)
		return;
	if (sl->size == sl->capacity)
	{
		sl->capacity = sl->capacity * 2;
		sl->size = sl->size * 2;
		tem = (variable*)malloc(sl->capacity*sizeof(variable));
		memcpy(tem, sl, sl->size*sizeof(variable));
		sl = tem;
		free(tem);
	}
}
void Add(Listcode* sl, variable value)
{
	Dilatation(&sl);
	sl->list[sl->size] = value;
	sl->size++;
}
void Delete(Listcode* sl)
{
	if (sl == NULL)
		return;
	if (sl->size > 0)
	{
		sl->size--;
	}
}
void test()
{
	Listcode sl;
	Initialization(&sl);
	Add(&sl, 1);
	Add(&sl, 1);
	Add(&sl, 1);
	Add(&sl, 1);
	Add(&sl, 1);
	Add(&sl, 1);

}
