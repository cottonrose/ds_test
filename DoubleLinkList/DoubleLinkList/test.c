#include "List.h"


void test()
{
	Node *pos = NULL;
	Node *head =(Node *)malloc(sizeof(Node));
	ListInit(head);
	PushFront(head, 1);
	PushFront(head, 2);
	PushFront(head, 3);
	PushFront(head, 4);
	PushFront(head, 5);
	PushBack(head, 6);
	PushBack(head, 7);
	PushBack(head, 8);
	pos = Find(head, 3);
	Insert(head, pos, 9);
	ListPrint(head);
	PopFront(head);
	ListPrint(head);
	PopBack(head);
	ListPrint(head);
	pos = Find(head, 4);
	Erase(head, pos);
	ListPrint(head);


}
int main()
{
	test();
}