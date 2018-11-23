#include "List.h"
#include <stdio.h>

//初始化
void ListInit(Node *head)
{
	assert(head);
	head->data = 0;
	head->next = head;
	head->prev = head;
}
//销毁
//要一个个结点去销毁，然后剩下一个头结点，释放头结点
void ListDestory(Node *head)
{
	Node *ret = NULL;
	Node *cur = NULL;
	assert(head);
	cur = head->next;
	while(cur != head)
	{
		ret = cur->next;
		cur->next = NULL;
		cur->prev = NULL;
		ret->prev = head;
		cur = ret;
	}
	free(head);
	head->next = NULL;
	head->prev = NULL;
}
//打印链表
void ListPrint(Node *head)
{
	Node *cur = NULL;
	assert(head);
	cur = head->next;
	printf("head--->");
	while(cur != head)
	{
		printf("%d--->",cur->data);
		cur = cur->next;
	}
	printf("NULL");
	printf("\n");
}
//查找
Node *Find(Node *head, DataType data)
{
	Node *cur = NULL;
	assert(head);
	cur = head->next;
	while(cur != head)
	{
		if(cur->data == data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//创建结点
Node *CreateNode(DataType data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
//头插
void PushFront(Node *head, DataType data)
{
	Node *newNode = CreateNode(data);
	newNode->prev = head;
	newNode->next = head->next;
	head->next->prev = newNode;
	head->next = newNode;
}
//尾插
void PushBack(Node *head, DataType data)
{
	Node *newNode = CreateNode(data);
	newNode->prev = head->prev;
	newNode->next = head;
	head->prev->next = newNode;
	head->prev = newNode;
}
//任意位置前插入
void Insert(Node *head, Node *pos, DataType data)
{
	Node *newNode = CreateNode(data);
	assert(head);
	assert(pos);
	newNode->next = pos;
	newNode->prev = pos->prev;
	pos->prev->next = newNode;
	pos->prev = newNode;
}
//头删
void PopFront(Node *head)
{
	Node *del = NULL;
	if(head->next == NULL)
	{
		printf("链表为空，删除失败\n");
		return ;
	}
	del = head->next;
	head->next = del->next;
	del->next->prev = head;
	free(del);
	del->next = NULL;
	del->prev = NULL;
}
//尾删
void PopBack(Node *head)
{
	Node *del = NULL;
	if(head->next == NULL)
	{
		printf("链表为空，删除失败\n");
		return ;
	}
	del = head->prev;
	head->prev = del->prev;
	del->prev->next = head;
	free(del);
	del->next = NULL;
	del->prev = NULL;
}
//指定位置删除
void Erase(Node *head, Node *pos)
{
	if(head->next == NULL)
	{
		printf("链表为空，删除失败\n");
		return ;
	}
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos->next = NULL;
	pos->prev = NULL;
}