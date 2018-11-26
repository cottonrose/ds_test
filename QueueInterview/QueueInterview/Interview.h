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

//用一个结构体封装两个栈实现查找最小值栈
typedef struct 
{
	Stack NorStack;
	Stack MinSatck;
}MinStack;
//用一个结构体封装两个栈实现一个队列
typedef struct
{
	Stack OneStack;
	Stack TwoStack;
}DouStaQueue;
//用一个结构体封装两个队列实现一个栈
typedef struct
{
	Queue OneQueue;
	Queue TwoQueue;
}DouQueStack;


//队列
//初始化
void QueueInit(Queue *pq);
//销毁
void QueueDestory(Queue *pq);
//打印队列
void QueuePrint(Queue *pq);
//创建结点
QNode *CreateNode(DataType data);
//插入数据
void QueueInsert(Queue *pq, DataType data);
//删除数据
void QueueErase(Queue *pq);
//返回队头元素
DataType QueueFront(Queue *pq);
//队列是否为空
int QueueEmpty(Queue *pq);
//队列长度
int QueueSize(Queue *pq);

//栈
//初始化
void StackInit(Stack *ps);
//销毁
void StackDestory(Stack *ps);
//压栈
void StackPush(Stack *ps, SDataType data);
//出栈
void StackPop(Stack *ps);
//返回栈顶元素
SDataType StackTop(Stack *ps);
//栈的元素个数
int StackSize(Stack *ps);
//判断栈是否为空
int StackEmpty(Stack *ps);

//1、实现一个栈，要求实现出栈、入栈、返回最小值的时间复杂度为O(1)
//初始化
void MinStackInit(MinStack *p);
//销毁
void MinStackDestory(MinStack *p);
//入栈
void MinStackPush(MinStack *p, SDataType data);
//返回栈顶元素
SDataType NorStackTop(MinStack *p);
//返回栈最小元素
SDataType MinStackTop(MinStack *p);
//入栈
void MinStackPush(MinStack *p, SDataType data);

//2、使用两个栈实现一个队列
//初始化
void DouStaQueueInit(DouStaQueue *p);
//销毁
void DouStaQueueDestory(DouStaQueue *p);
//插入数据
void DouStaQueueInsert(DouStaQueue *p, int data);
//删除数据
void DouStaQueueErase(DouStaQueue *p);
//返回队头元素
int  DouStaQueueFront(DouStaQueue *p);
//判断队列是否为空
int DouStaQueueEmpty(DouStaQueue *p);
//队列长度
int DouStaQueueSize(DouStaQueue *p);

//3、两个队列实现一个栈
//初始化
void DouQueStackInit(DouQueStack *p);
//销毁
void DouQueStackDestory(DouQueStack *p);
//压栈
void DouQueStackInsert(DouQueStack *p, DataType data);
//出栈
void DouQueStackErase(DouQueStack *p);
