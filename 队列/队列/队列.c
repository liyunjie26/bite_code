#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct MyCircularQueue
{//队头
	int _front;
	//队位元素下一个位置
	int _rear;
	//队列容量
	int k;
	//存放元素空间的首地址
	int*_data;
}MyCircularQueue;
MyCircularQueue* myCircularCreat(int k)
{
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->_data = (int*)malloc(sizeof(int)*(k + 1));
	cq->k = k;
	cq->_front = cq->_rear = 0;//0~k
	return cq;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	return obj->_front == obj->_rear;
}
bool myCircularQueueIsFull(MyCircularQueue* obj)
{//rear+1%空间长度==front
	return (obj->_rear + 1) % obj->k + 1 == obj->_front;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	//队列已满
	if (myCircularQueueIsFull(obj))
		return false;

	obj->_data[obj->_rear++] = value;
	//循环结构判队尾是否越界
	if (obj->_rear > obj->k)
		obj->_rear = 0;
	return true;
}
bool myCircularQueueDeQueue(MyCircularQueue* obj)//出队头元素
{
	//队列非空
	if (myCircularQueueIsEmpty(obj))
		return false;
	//队头出队
	obj->_front++;
	//判断队头是否越界
	if (obj->_front > obj->k)
		obj->_front = 0;
	return true;
}
int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->_data[obj->_front];
}
int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	if (obj->_rear != 0)
		return obj->_data[obj->_rear - 1];
	else
		//rear为0,返回队尾
		return obj->_data[obj->k];
	//判断是否在0处
}

void myCircularQueueIsFree(MyCircularQueue* obj)
{
	free(obj->_data);
	free(obj);
}
int main()
{
	return 0;
}