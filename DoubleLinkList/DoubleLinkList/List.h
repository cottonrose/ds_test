#pragma once

#include <assert.h>
#include <stdlib.h>
typedef int DataType;

typedef struct Node
{
	DataType data;
	struct Node *prev;
	struct Node *next;
}Node;

void ListInit(Node *head);
void ListDestory(Node *head);
void ListPrint(Node *head);
void PushFront(Node *head, DataType data);
void PushBack(Node *head, DataType data);
Node *Find(Node *head, DataType data);
void Insert(Node *head, Node *pos, DataType data);
void PopFront(Node *head);
void PopBack(Node *head);
void Erase(Node *head, Node *pos);