#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct MyCircularQueue
{//��ͷ
	int _front;
	//��λԪ����һ��λ��
	int _rear;
	//��������
	int k;
	//���Ԫ�ؿռ���׵�ַ
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
{//rear+1%�ռ䳤��==front
	return (obj->_rear + 1) % obj->k + 1 == obj->_front;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	//��������
	if (myCircularQueueIsFull(obj))
		return false;

	obj->_data[obj->_rear++] = value;
	//ѭ���ṹ�ж�β�Ƿ�Խ��
	if (obj->_rear > obj->k)
		obj->_rear = 0;
	return true;
}
bool myCircularQueueDeQueue(MyCircularQueue* obj)//����ͷԪ��
{
	//���зǿ�
	if (myCircularQueueIsEmpty(obj))
		return false;
	//��ͷ����
	obj->_front++;
	//�ж϶�ͷ�Ƿ�Խ��
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
		//rearΪ0,���ض�β
		return obj->_data[obj->k];
	//�ж��Ƿ���0��
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