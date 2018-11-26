#include "Interview.h"

//����
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

//ջ
//��ʼ��
void StackInit(Stack *ps)
{
	ps->top = 0;
}
//����
void StackDestory(Stack *ps)
{
	ps->top = 0;
}
//ѹջ
void StackPush(Stack *ps, SDataType data)
{
	assert(ps->top<MAX_SIZE);
	ps->data[ps->top++] = data;
}
//��ջ
void StackPop(Stack *ps)
{
	assert(ps->top>0);
	ps->top--;
}
//����ջ��Ԫ��
SDataType StackTop(Stack *ps)
{
	assert(ps->top>0);
	return ps->data[ps->top-1];
}
//ջ��Ԫ�ظ���
int StackSize(Stack *ps)
{
	return ps->top;
}
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack *ps)
{
	if(ps->top==0)
		return 1;
	else
		return 0;
}

//1��ʵ��һ��ջ��Ҫ��ʵ�ֳ�ջ����ջ��������Сֵ��ʱ�临�Ӷ�ΪO(1)
//��ʼ��
void MinStackInit(MinStack *p)
{
	p->MinSatck.top = 0;
	p->NorStack.top = 0;
}
//����
void MinStackDestory(MinStack *p)
{
	p->MinSatck.top = 0;
	p->NorStack.top = 0;
}
//����ջ��Ԫ��
SDataType NorStackTop(MinStack *p)
{
	return p->NorStack.data[p->NorStack.top-1];
}
//����ջ��СԪ��
SDataType MinStackTop(MinStack *p)
{
	return p->MinSatck.data[p->MinSatck.top-1];
}
//��ջ
void MinStackPush(MinStack *p, SDataType data)
{
	assert(p->MinSatck.top<MAX_SIZE);
	p->NorStack.data[p->NorStack.top] = data;
	if(StackEmpty(&(p->MinSatck)) || data<StackTop(&(p->MinSatck)))//ջΪ��ʱֱ��ѹջ
	{
		p->MinSatck.data[p->MinSatck.top] = data;
	}
	else
	{
		p->MinSatck.data[p->MinSatck.top] = StackTop(&(p->MinSatck));
	}
	p->MinSatck.top++;
	p->NorStack.top++;
}

//2��ʹ������ջʵ��һ������
//��ʼ��
void DouStaQueueInit(DouStaQueue *p)
{
	assert(p!=NULL);
	p->OneStack.top = 0;
	p->TwoStack.top = 0;
}
//����
void DouStaQueueDestory(DouStaQueue *p)
{
	assert(p!=NULL);
	p->OneStack.top = 0;
	p->TwoStack.top = 0;
}
//��������
void DouStaQueueInsert(DouStaQueue *p, int data)
{
	assert(p->OneStack.top<MAX_SIZE);
	p->OneStack.data[p->OneStack.top] = data;
	p->OneStack.top++;
}
//ɾ������
void DouStaQueueErase(DouStaQueue *p)
{
	assert(p->OneStack.top != 0);
	if(StackEmpty(&(p->TwoStack)))
	{
		while(p->OneStack.top)
		{
			p->TwoStack.data[p->TwoStack.top] = p->OneStack.data[p->OneStack.top-1];
			p->OneStack.top--;
			p->TwoStack.top++;
		}
		p->TwoStack.top--;
	}
}
//���ض�ͷԪ��
int  DouStaQueueFront(DouStaQueue *p)
{
	assert(p->OneStack.top != 0);
	if(StackEmpty(&(p->TwoStack)))
	{
		while(p->OneStack.top)
		{
			p->TwoStack.data[p->TwoStack.top] = p->OneStack.data[p->OneStack.top-1];
			p->OneStack.top--;
			p->TwoStack.top++;
		}
		p->TwoStack.top--;
	}
	return p->TwoStack.data[p->TwoStack.top-1];
}
//�ж϶����Ƿ�Ϊ��
int DouStaQueueEmpty(DouStaQueue *p)
{
	return StackEmpty(&p->OneStack)&&StackEmpty(&p->TwoStack);
}
//���г���
int DouStaQueueSize(DouStaQueue *p)
{
	return StackSize(&p->OneStack)+StackSize(&p->TwoStack);
}

//3����������ʵ��һ��ջ
//��ʼ��
void DouQueStackInit(DouQueStack *p)
{
	assert(p != NULL);
	QueueInit(&(p->OneQueue));
	QueueInit(&(p->TwoQueue));
}
//����
void DouQueStackDestory(DouQueStack *p)
{
	assert(p != NULL);
	QueueDestory(&(p->OneQueue));
	QueueDestory(&(p->TwoQueue));
}
//���ض�βԪ�أ�������βԪ��ɾ����
DataType QueueRearDel(Queue *q)
{
	QNode *pre = NULL;
	QNode *cur = NULL;
	assert(q != NULL);
	cur = q->front;
	while(cur->next != NULL)
	{
		pre = cur;
		cur = cur->next;
	}
	pre->next = NULL;
	q->size--;
	return cur->data;
}
//ѹջ
void DouQueStackInsert(DouQueStack *p, DataType data)
{
	assert(p != NULL);
	while(!QueueEmpty(&(p->TwoQueue)))
	{
		QueueInsert(&(p->OneQueue),QueueRearDel(&(p->TwoQueue)));
	}
	QueueInsert(&(p->OneQueue),data);
}
//��ջ
void DouQueStackErase(DouQueStack *p)
{
	assert(p != NULL);
	if(QueueEmpty(&(p->OneQueue)))
	{

	}
}
