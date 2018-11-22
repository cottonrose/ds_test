#include "List.h"
#include <stdio.h>
#include <assert.h>


void ListPushBackTest()
{
	ListNode *pos = NULL;
	ListNode *list;
	ListNode *ret;
	ListInit(&list);
	ListInit(&ret);
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	ListPushBack(&list, 5);
	ListPushBack(&list, 6);
	ListPrint(&list);

	ListPushFront(&list,13);
	ListPushFront(&list,11);
	ListPushFront(&list,9);
	ListPushFront(&list,5);
	ListPushFront(&list,4);
	ListPushFront(&list,3);
	ListPushFront(&list,2);
	ListPrint(&list);
	pos = IsIntersect(list,ret);
	//ListDestory(&list);
}
void ListPushFrontTest()
{
	ListNode *pos = NULL;
	ListNode *list;
	ListNode *ret;
	ListNode *result;
	ListInit(&list);
	ListInit(&ret);

	ListPushFront(&list,13);
	ListPushFront(&list,11);
	ListPushFront(&list,9);
	ListPushFront(&list,5);
	ListPushFront(&list,4);
	ListPushFront(&list,3);
	ListPushFront(&list,2);
	ListPrint(&list);
	//RemoveK(&list,4);
	//ListPrint(&list);

	//pos = FindK(list,5);
	//printf("%d\n",pos->data);
	//pos = FindMid(list);
	//printf("%d\n",pos->data);
	ListPushFront(&ret,10);
	ListPushFront(&ret,8);
	ListPushFront(&ret,6);
	ListPushFront(&ret,5);
	ListPushFront(&ret,4);
	ListPushFront(&ret,2);
	ListPrint(&ret);

	result = UnionSet(list,ret);
	ListPrint(&result);

    //ret = ReverseList(&list);
	//ReversePrint(&list);
	//pos = ListFind(&list, 2);
	//InsertNoHead(pos,6);
	//RemoveNodeNotTail(pos);
	//ret = JocephCircle(list, 3);
	//BubbleSort(&list);
	//ListPrint(&list);


	//ListDestory(&list);

}
void ComListInit(ComplexNode **pFirst)
{
	assert(*pFirst != NULL);
	(*pFirst)->data = 0;
	(*pFirst)->next = NULL;
	(*pFirst)->random = NULL;
}
void ComplexListTest()
{
	ComplexNode *list = NULL;
	ComplexNode *ret = NULL;
	ComplexNode *p1 = CreateComNode(1);
	ComplexNode *p2 = CreateComNode(2);
	ComplexNode *p3 = CreateComNode(3);
	ComplexNode *p4 = CreateComNode(4);

	list = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = NULL;

	p1->random = p3;
	p2->random = p1;
	p3->random = p3;
	p4->random = NULL;
	ret = CopyComplexList(&list);
}
int main()
{
	ListPushBackTest();
	//ListPushFrontTest();
	//ComplexListTest();
	return 0;
}