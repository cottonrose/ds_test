#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

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