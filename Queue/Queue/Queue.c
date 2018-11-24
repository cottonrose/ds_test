#include "Queue.h"

//��ʼ��
void QueueInit(Queue *pq)
{
	assert(pq != NULL);
	pq->front = NULL;
	pq->rear = NULL;
	pq->size = 0;
}
//����
void QueueDestory(Queue *pq)
{
	QNode *next = NULL;
	QNode *cur = pq->front;
	assert(pq != NULL);
	while(cur != NULL)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	pq->front = NULL;
	pq->rear = NULL;
	pq->size = 0;
}
//��ӡ����
void QueuePrint(Queue *pq)
{
	QNode *cur = NULL;
	assert(pq);
	cur = pq->front;
	while(cur != pq->rear->next)
	{
		printf("%d ",cur->data);
		cur = cur->next;
	}
	printf("\n");
}
//�������
QNode *CreateNode(DataType data)
{
	QNode *newNode = (QNode *)malloc(sizeof(QNode));
	assert(newNode);
	newNode->next = NULL;
	newNode->data = data;
	return newNode;
}
//��������
void QueueInsert(Queue *pq, DataType data)
{
	QNode *newNode = NULL;
	assert(pq != NULL);
	newNode = CreateNode(data);
	if(pq->front == NULL)
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
	pq->size++;
}
//ɾ������
void QueueErase(Queue *pq)
{
	QNode *del = NULL;
	assert(pq);
	assert(pq->front != NULL);
	if(pq->front == pq->rear)
	{
		pq->front = NULL;
		pq->rear = NULL;
	}
	else
	{
		del = pq->front;
		pq->front = pq->front->next;
		free(del);
		del = NULL;
	}
	pq->size--;
}
//���ض�ͷԪ��
DataType QueueFront(Queue *pq)
{
	assert(pq);
	assert(pq->front != NULL);
	return pq->front->data;
}
//�����Ƿ�Ϊ��
int QueueEmpty(Queue *pq)
{
	assert(pq);
	if(pq->front == NULL)
	{
		return 1;
	}
	return 0;
}
//���г���
int QueueSize(Queue *pq)
{
	assert(pq);
	return pq->size;
}