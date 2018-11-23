#include "List.h"
#include <stdio.h>

//��ʼ��
void ListInit(Node *head)
{
	assert(head);
	head->data = 0;
	head->next = head;
	head->prev = head;
}
//����
//Ҫһ�������ȥ���٣�Ȼ��ʣ��һ��ͷ��㣬�ͷ�ͷ���
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
//��ӡ����
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
//����
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
//�������
Node *CreateNode(DataType data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
//ͷ��
void PushFront(Node *head, DataType data)
{
	Node *newNode = CreateNode(data);
	newNode->prev = head;
	newNode->next = head->next;
	head->next->prev = newNode;
	head->next = newNode;
}
//β��
void PushBack(Node *head, DataType data)
{
	Node *newNode = CreateNode(data);
	newNode->prev = head->prev;
	newNode->next = head;
	head->prev->next = newNode;
	head->prev = newNode;
}
//����λ��ǰ����
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
//ͷɾ
void PopFront(Node *head)
{
	Node *del = NULL;
	if(head->next == NULL)
	{
		printf("����Ϊ�գ�ɾ��ʧ��\n");
		return ;
	}
	del = head->next;
	head->next = del->next;
	del->next->prev = head;
	free(del);
	del->next = NULL;
	del->prev = NULL;
}
//βɾ
void PopBack(Node *head)
{
	Node *del = NULL;
	if(head->next == NULL)
	{
		printf("����Ϊ�գ�ɾ��ʧ��\n");
		return ;
	}
	del = head->prev;
	head->prev = del->prev;
	del->prev->next = head;
	free(del);
	del->next = NULL;
	del->prev = NULL;
}
//ָ��λ��ɾ��
void Erase(Node *head, Node *pos)
{
	if(head->next == NULL)
	{
		printf("����Ϊ�գ�ɾ��ʧ��\n");
		return ;
	}
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos->next = NULL;
	pos->prev = NULL;
}