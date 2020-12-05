#include<String.h>
#include<stdio.h>
#include"testlist.h"
#include<memory.h>
void initseqList(seqList *sl)
{
	if (sl == NULL)
		return;
	sl->_data = NULL;
	sl->_capacity = 0;
	sl->_size = 0;
}
void seqListCheckCapacity(seqList* sl)//检查容量
{
	if (sl->_capacity == sl->_size)
	{
		int newCapacity = sl->_capacity == 0 ? 1 : 2 * sl->_capacity;
		SLDDataType *tmp = (SLDDataType*)malloc(newCapacity*sizeof(SLDDataType));
		memcpy(tmp, sl->_data, sizeof(SLDDataType)*sl->_size);
		free(sl->_data);
		sl->_data = tmp;
		sl->_capacity = newCapacity;
	}
}
void seqListpushBack(seqList* sl, SLDDataType val)
{
	if (sl == NULL)
		return;
	seqListCheckCapacity(sl);//检查容量
	sl->_data[sl->_size] = val;
	sl->_size++;
}
void seqListpopBack(seqList* sl)
{
	if (sl == NULL)
		return;
	if (sl->_size > 0)
		sl->_size--;
}
void seqLstPrint(seqList* sl)
{
	if (sl == NULL)
		return;
	for (int i = 0; i < sl->_size; ++i)
	{
		printf("%d ", sl->_data[i]);
	}
	printf("\n");
}
SLDDataType seqListAt(seqList* sl, int pos)
{
	return sl->_data[pos];

}
int seqListEmpty(seqList* sl)
{
	if (sl == NULL || sl->_size == 0)
		return 0;
	else
		return 1;
}
int seqListSize(seqList* sl)
{

	if (sl == NULL || sl->_size == 0)
		return 0;
	else
		return sl->_size;
}

void test()
{
	seqList sl;
	initseqList(&sl);
	seqListpushBack(&sl, 1);
	seqListpushBack(&sl, 2);
	seqListpushBack(&sl, 3);
	seqListpushBack(&sl, 4);
	seqListpushBack(&sl, 5);
	seqListpushBack(&sl, 6);
	seqListpushBack(&sl, 7);
	seqLstPrint(&sl);
	seqListpopBack(&sl);
	seqLstPrint(&sl);
	seqListpopBack(&sl);
	seqLstPrint(&sl);
	seqListpopBack(&sl);
	seqLstPrint(&sl);
	seqListpopBack(&sl);
	seqLstPrint(&sl);
	seqListpopBack(&sl);


} 
int main()
{
	test();
	return 0;
}