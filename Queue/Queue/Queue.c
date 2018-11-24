#include "Queue.h"

//初始化
void QueueInit(Queue *pq)
{
	assert(pq != NULL);
	pq->front = NULL;
	pq->rear = NULL;
	pq->size = 0;
}
//销毁
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
//打印队列
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
//创建结点
QNode *CreateNode(DataType data)
{
	QNode *newNode = (QNode *)malloc(sizeof(QNode));
	assert(newNode);
	newNode->next = NULL;
	newNode->data = data;
	return newNode;
}
//插入数据
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
//删除数据
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
//返回队头元素
DataType QueueFront(Queue *pq)
{
	assert(pq);
	assert(pq->front != NULL);
	return pq->front->data;
}
//队列是否为空
int QueueEmpty(Queue *pq)
{
	assert(pq);
	if(pq->front == NULL)
	{
		return 1;
	}
	return 0;
}
//队列长度
int QueueSize(Queue *pq)
{
	assert(pq);
	return pq->size;
}