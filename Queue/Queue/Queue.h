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