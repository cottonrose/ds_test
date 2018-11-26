#include "Interview.h"

//队列
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

//栈
//初始化
void StackInit(Stack *ps)
{
	ps->top = 0;
}
//销毁
void StackDestory(Stack *ps)
{
	ps->top = 0;
}
//压栈
void StackPush(Stack *ps, SDataType data)
{
	assert(ps->top<MAX_SIZE);
	ps->data[ps->top++] = data;
}
//出栈
void StackPop(Stack *ps)
{
	assert(ps->top>0);
	ps->top--;
}
//返回栈顶元素
SDataType StackTop(Stack *ps)
{
	assert(ps->top>0);
	return ps->data[ps->top-1];
}
//栈的元素个数
int StackSize(Stack *ps)
{
	return ps->top;
}
//判断栈是否为空
int StackEmpty(Stack *ps)
{
	if(ps->top==0)
		return 1;
	else
		return 0;
}

//1、实现一个栈，要求实现出栈、入栈、返回最小值的时间复杂度为O(1)
//初始化
void MinStackInit(MinStack *p)
{
	p->MinSatck.top = 0;
	p->NorStack.top = 0;
}
//销毁
void MinStackDestory(MinStack *p)
{
	p->MinSatck.top = 0;
	p->NorStack.top = 0;
}
//返回栈顶元素
SDataType NorStackTop(MinStack *p)
{
	return p->NorStack.data[p->NorStack.top-1];
}
//返回栈最小元素
SDataType MinStackTop(MinStack *p)
{
	return p->MinSatck.data[p->MinSatck.top-1];
}
//入栈
void MinStackPush(MinStack *p, SDataType data)
{
	assert(p->MinSatck.top<MAX_SIZE);
	p->NorStack.data[p->NorStack.top] = data;
	if(StackEmpty(&(p->MinSatck)) || data<StackTop(&(p->MinSatck)))//栈为空时直接压栈
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

//2、使用两个栈实现一个队列
//初始化
void DouStaQueueInit(DouStaQueue *p)
{
	assert(p!=NULL);
	p->OneStack.top = 0;
	p->TwoStack.top = 0;
}
//销毁
void DouStaQueueDestory(DouStaQueue *p)
{
	assert(p!=NULL);
	p->OneStack.top = 0;
	p->TwoStack.top = 0;
}
//插入数据
void DouStaQueueInsert(DouStaQueue *p, int data)
{
	assert(p->OneStack.top<MAX_SIZE);
	p->OneStack.data[p->OneStack.top] = data;
	p->OneStack.top++;
}
//删除数据
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
//返回队头元素
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
//判断队列是否为空
int DouStaQueueEmpty(DouStaQueue *p)
{
	return StackEmpty(&p->OneStack)&&StackEmpty(&p->TwoStack);
}
//队列长度
int DouStaQueueSize(DouStaQueue *p)
{
	return StackSize(&p->OneStack)+StackSize(&p->TwoStack);
}

//3、两个队列实现一个栈
//初始化
void DouQueStackInit(DouQueStack *p)
{
	assert(p != NULL);
	QueueInit(&(p->OneQueue));
	QueueInit(&(p->TwoQueue));
}
//销毁
void DouQueStackDestory(DouQueStack *p)
{
	assert(p != NULL);
	QueueDestory(&(p->OneQueue));
	QueueDestory(&(p->TwoQueue));
}
//返回队尾元素，并将队尾元素删除掉
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
//压栈
void DouQueStackInsert(DouQueStack *p, DataType data)
{
	assert(p != NULL);
	while(!QueueEmpty(&(p->TwoQueue)))
	{
		QueueInsert(&(p->OneQueue),QueueRearDel(&(p->TwoQueue)));
	}
	QueueInsert(&(p->OneQueue),data);
}
//出栈
void DouQueStackErase(DouQueStack *p)
{
	assert(p != NULL);
	if(QueueEmpty(&(p->OneQueue)))
	{

	}
}
