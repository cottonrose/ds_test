#pragma once

typedef int DataType; 

typedef struct ListNode
{ 
	DataType data; 
	struct ListNode *next; 
} ListNode;

typedef struct ComplexNode
{
	int data;
	ComplexNode *next;
	ComplexNode *random;
}ComplexNode;

//初始化
void ListInit(ListNode **pFirst);
//销毁
void ListDestory(ListNode **pFirst);
//打印链表
void ListPrint(ListNode **pFirst);
//尾插
void ListPushBack(ListNode **pFirst, DataType data);
//头插
void ListPushFront(ListNode **pFirst, DataType data);
// 按值查找，返回第一个找到的结点指针，如果没找到，返回 NULL 
ListNode *ListFind(ListNode **pFirst, DataType data);
// 给定结点插入(插入到结点前)
void ListInsert(ListNode **pFirst, ListNode *pos, DataType data);
//尾删
void ListPopBack(ListNode **pFirst);
//头删
void ListPopFront(ListNode **pFirst);
//给定结点删除
void ListErase(ListNode **pFirst, ListNode *pos);
//删除指定元素
void ListRemove(ListNode **pFirst, DataType data);
//删除所有指定元素
void ListRemoveAll(ListNode **pFirst, DataType data);

//链表面试题
//倒序打印链表
//1、last方式
void ReversePrint(ListNode **pFirst);
//2、递归方式
void ReversePrintR(ListNode *pFirst);
//逆置链表
ListNode *ReverseList(ListNode **pFirst);
//删除一个无头单链表的非尾结点
void RemoveNodeNotTail(ListNode *pos);
//无头链表前插入
void InsertNoHead(ListNode *pos, int data);
//单链表实现约瑟夫环
ListNode *JocephCircle(ListNode *pFirst, int k);
//冒泡排序
void BubbleSort(ListNode **pFirst);
//合并两个有序链表
ListNode *MergeOrderedList(ListNode *p1First, ListNode *p2First);
//查找链表的中间结点（只能遍历一次链表）
ListNode *FindMid(ListNode *pFirst);
//查找倒数第K个结点（只能遍历一次链表）
ListNode *FindK(ListNode *pFirst, int k);
//删除倒数第K个结点（只能遍历一次链表，不能使用替换法删除）
void RemoveK(ListNode **pFirst, int k);
//求两个已排序单链表中相同的数据
ListNode *UnionSet(ListNode *list1, ListNode *list2);

//复杂链表的复制
//一个链表的每个结点，有一个指向next指针指向下一个结点，
//还有一个random指针指向这个链表中的随机一个结点或者NULL，
//现在要求实现复制这个链表，返回复制后的新链表
ComplexNode *CreateComNode(int data);
ComplexNode *CopyComplexList(ComplexNode **pFirst);
//判断两个链表是否相交，若相交，求交点（假设链表不带环）
ListNode *IsIntersect(ListNode *p1First, ListNode *p2First);
//判断单链表是否带环？若带环，求环的长度？求环的入口点？
//判断是否带环，带环返回快慢指针相遇结点
ListNode *IsCircleList(ListNode *p);
//求环的长度
int LenOfCircle(ListNode *p);
//求环的入口点
ListNode *EntryNode(ListNode *p);