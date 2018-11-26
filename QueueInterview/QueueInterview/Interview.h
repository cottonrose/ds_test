#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef int DataType;

typedef struct QNode
{
	DataType data;
	struct QNode *next;
}QNode;

typedef struct
{
	QNode *front;
	QNode *rear;
	int size;
}Queue;

typedef char SDataType;
typedef struct Stack
{
	SDataType data[MAX_SIZE];
	int top;
}Stack;

//��һ���ṹ���װ����ջʵ�ֲ�����Сֵջ
typedef struct 
{
	Stack NorStack;
	Stack MinSatck;
}MinStack;
//��һ���ṹ���װ����ջʵ��һ������
typedef struct
{
	Stack OneStack;
	Stack TwoStack;
}DouStaQueue;
//��һ���ṹ���װ��������ʵ��һ��ջ
typedef struct
{
	Queue OneQueue;
	Queue TwoQueue;
}DouQueStack;


//����
//��ʼ��
void QueueInit(Queue *pq);
//����
void QueueDestory(Queue *pq);
//��ӡ����
void QueuePrint(Queue *pq);
//�������
QNode *CreateNode(DataType data);
//��������
void QueueInsert(Queue *pq, DataType data);
//ɾ������
void QueueErase(Queue *pq);
//���ض�ͷԪ��
DataType QueueFront(Queue *pq);
//�����Ƿ�Ϊ��
int QueueEmpty(Queue *pq);
//���г���
int QueueSize(Queue *pq);

//ջ
//��ʼ��
void StackInit(Stack *ps);
//����
void StackDestory(Stack *ps);
//ѹջ
void StackPush(Stack *ps, SDataType data);
//��ջ
void StackPop(Stack *ps);
//����ջ��Ԫ��
SDataType StackTop(Stack *ps);
//ջ��Ԫ�ظ���
int StackSize(Stack *ps);
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack *ps);

//1��ʵ��һ��ջ��Ҫ��ʵ�ֳ�ջ����ջ��������Сֵ��ʱ�临�Ӷ�ΪO(1)
//��ʼ��
void MinStackInit(MinStack *p);
//����
void MinStackDestory(MinStack *p);
//��ջ
void MinStackPush(MinStack *p, SDataType data);
//����ջ��Ԫ��
SDataType NorStackTop(MinStack *p);
//����ջ��СԪ��
SDataType MinStackTop(MinStack *p);
//��ջ
void MinStackPush(MinStack *p, SDataType data);

//2��ʹ������ջʵ��һ������
//��ʼ��
void DouStaQueueInit(DouStaQueue *p);
//����
void DouStaQueueDestory(DouStaQueue *p);
//��������
void DouStaQueueInsert(DouStaQueue *p, int data);
//ɾ������
void DouStaQueueErase(DouStaQueue *p);
//���ض�ͷԪ��
int  DouStaQueueFront(DouStaQueue *p);
//�ж϶����Ƿ�Ϊ��
int DouStaQueueEmpty(DouStaQueue *p);
//���г���
int DouStaQueueSize(DouStaQueue *p);

//3����������ʵ��һ��ջ
//��ʼ��
void DouQueStackInit(DouQueStack *p);
//����
void DouQueStackDestory(DouQueStack *p);
//ѹջ
void DouQueStackInsert(DouQueStack *p, DataType data);
//��ջ
void DouQueStackErase(DouQueStack *p);
