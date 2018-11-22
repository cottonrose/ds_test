#include "List.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//初始化
void ListInit(ListNode **pFirst)
{
	*pFirst = NULL; 
}
//销毁
void ListDestory(ListNode **pFirst)
{
	ListNode *cur = NULL;
	ListNode *del = NULL;
	assert(*pFirst);
	cur = *pFirst;
	while(cur->next != NULL)
	{
		del = cur;
		cur = cur->next;
		free(del);
	}
	free(cur);
}
//打印链表
void ListPrint(ListNode **pFirst)
{
	ListNode *cur = NULL;
	assert(*pFirst != NULL);
	cur = *pFirst;
	while(cur != NULL)
	{
		printf("%d ",cur->data);
		cur = cur->next;
	}
	printf("\n");
}
//创建一个新结点
ListNode *CreateNode(DataType data)
{
	ListNode *NewNode = (ListNode *)malloc(sizeof(DataType));
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}
//尾插
void ListPushBack(ListNode **pFirst, DataType data)
{
	ListNode *cur = NULL;
	//如果链表为空
	if(*pFirst == NULL)
	{
		*pFirst = CreateNode(data);
		return ;
	}
	//链表不为空
	cur = *pFirst;
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = CreateNode(data);
}
//头插
void ListPushFront(ListNode **pFirst, DataType data)
{
	ListNode *cur = NULL;
	//如果链表为空
	if(*pFirst == NULL)
	{
		*pFirst = CreateNode(data);
		return ;
	}
	//链表不为空
	cur = *pFirst;
	*pFirst = CreateNode(data);
	(*pFirst)->next = cur;
}
// 按值查找，返回第一个找到的结点指针，如果没找到，返回 NULL 
ListNode *ListFind(ListNode **pFirst, DataType data)
{
	ListNode *cur = NULL;
	assert(*pFirst != NULL);
	cur = *pFirst;
	while(cur != NULL)
	{
		if(cur->data == data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
// 给定结点插入(插入到结点前)
void ListInsert(ListNode **pFirst, ListNode *pos, DataType data)
{
	ListNode *cur = NULL;
	ListNode *NewNode = NULL;
	assert(*pFirst != NULL);
	if(pos == NULL)
		return ;
	//如果在第一个元素位置前插入，调用头插函数
	if(pos == *pFirst)
	{
		ListPushFront(pFirst, data);
	}
	cur = *pFirst;
	NewNode = CreateNode(data);
	while(cur->next != pos)
	{
		cur = cur->next;
	}
	cur->next = NewNode;
	NewNode->next = pos;
}
//尾删
void ListPopBack(ListNode **pFirst)
{
	ListNode *cur = NULL;
	ListNode *del = NULL;
	assert(*pFirst != NULL);
	//如果链表只有一个元素
	if((*pFirst)->next == NULL)
		*pFirst = NULL;
	//如果链表有多个元素
	cur = *pFirst;
	while(cur->next->next != NULL)
	{
		cur = cur->next;
	}
	del = cur->next->next;
	cur->next = NULL;
	free(del);
}
//头删
void ListPopFront(ListNode **pFirst)
{
	ListNode *del = NULL;
	assert(*pFirst != NULL);
	//如果链表只有一个元素
	if((*pFirst)->next == NULL)
	{
		*pFirst = NULL;
	}
	//如果链表有多个元素
	del = *pFirst;
	*pFirst = (*pFirst)->next; 
	//free(del);
}
//给定结点删除
void ListErase(ListNode **pFirst, ListNode *pos)
{
	ListNode *del = NULL;
	ListNode *cur = NULL;
	assert(*pFirst != NULL);
	//如果给定结点不存在
	if(pos == NULL)
		return ;
	//如果给定结点是第一个元素
	if(pos == *pFirst)
	{
		ListPopFront(pFirst);
		return ;
	}
	//如果给定结点是最后一个
	else if(pos->next == NULL)
	{
		ListPopBack(pFirst);
		return ;
	}
	//如果给定结点是除首尾外元素
	cur = *pFirst;
	while(cur->next != pos)
	{
		cur = cur->next;
	}
	cur->next = cur->next->next;
	//free(pos);
}
//删除指定元素
void ListRemove(ListNode **pFirst, DataType data)
{
	ListNode *cur = NULL;
	ListNode *del = NULL;
	assert(*pFirst != NULL);
	//如果删除的元素为第一个元素
	if((*pFirst)->data == data)
	{
		ListPopFront(pFirst);
		return ;
	}
	cur = *pFirst;
	while(cur != NULL)
	{
		if(cur->next->data == data)
		{
			del = cur->next;
			cur->next = cur->next->next;
			return ;
		}
		cur = cur->next;
	}
}
//删除所有指定元素
void ListRemoveAll(ListNode **pFirst, DataType data)
{
	ListNode *cur = NULL;
	assert(*pFirst != NULL);
	cur = *pFirst;
	while(cur != NULL)
	{
		if((*pFirst)->data == data)
		{
			*pFirst = (*pFirst)->next;
		}
		else if(cur->next->data == data)
		{
			cur->next = cur->next->next;
		}
		cur = cur->next;
	}
}


//链表面试题

//倒序打印链表
//1、last方式
void ReversePrint(ListNode **pFirst)
{
	ListNode *last = NULL;
	ListNode *cur = NULL;
	assert(*pFirst != NULL);
	while(last != *pFirst)
	{
		cur = *pFirst;
		while(cur != NULL)
		{
			if(cur->next == last)
			{
				printf("%d ",cur->data);
				last = cur;
			}
			cur = cur->next;
		}
	}
	printf("\n");
}
//2、递归方式
void ReversePrintR(ListNode *pFirst)
{
	if(pFirst == NULL)
	{
		return ;
	}
	if(pFirst->next == NULL)
	{
		printf("%d ",pFirst->data);
	}
	else
	{
		ReversePrintR(pFirst->next);
		printf("%d ",pFirst->data);
	}
}
//逆置链表
//N<---1<---2<---3<---4
ListNode *ReverseList(ListNode **pFirst)
{
	ListNode *tmp = NULL;
	ListNode *pre = NULL;
	ListNode *cur = NULL;
	ListNode *result = NULL;
	assert(*pFirst != NULL);
	cur = *pFirst;
	while(cur != NULL)
	{
		tmp = cur->next;
		if(cur->next == NULL)
		{
			result = cur;
		}
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	return result;
}
//删除一个无头单链表的非尾结点
void RemoveNodeNotTail(ListNode *pos)
{
	if(pos == NULL)
	{
		return ;
	}
	pos->data = pos->next->data;
	pos->next = pos->next->next;
}
//无头链表前插入
void InsertNoHead(ListNode *pos, int data)
{
	ListNode *NewNode = NULL;
	if(pos == NULL)
	{
		return ;
	}
	NewNode = CreateNode(data);
	NewNode->data = pos->data;
	NewNode->next = pos->next;
	pos->data = data;
	pos->next = NewNode;
}
//单链表实现约瑟夫环
ListNode *JocephCircle(ListNode *pFirst, int k)
{
	ListNode *result = NULL;
	ListNode *pre = NULL;
	ListNode *cur = NULL;
	int i = 0;
	assert(pFirst != NULL);
	cur = pFirst;
	//先使链表构成一个环（最后一个结点的next等于第一个结点）
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = pFirst;
	//如果链表中剩余结点超过一个，每次找到第k个结点，删除它
	cur = pFirst;
	while(cur->next != cur)
	{
		for(i=0; i<k-1; i++)
		{
			pre = cur;
			cur = cur->next;
		}
		//删除元素
		pre->next = cur->next;
		//free(cur);
		cur = pre->next;
	}
	result = cur;
	result->next = NULL;
	return result;
}
//冒泡排序
void BubbleSort(ListNode **pFirst)
{
	ListNode *cur = NULL;
	ListNode *last = NULL;
	ListNode *pre = NULL;
	DataType tmp = 0;
	DataType max = 0;
	assert(*pFirst != NULL);
	while(last != (*pFirst)->next)
	{
		cur = (*pFirst)->next;
		max = (*pFirst)->data;
		while(cur != last)
		{
			if(cur->data>max)
			{
				tmp = max;
				max = cur->data;
				cur->data = tmp;
			}
			pre = cur;
			cur = cur->next;
		}
		tmp = pre->data;
		pre->data = max;
		(*pFirst)->data = tmp;
		last = pre;
	}
}
//合并两个有序链表
ListNode *MergeOrderedList(ListNode *p1First, ListNode *p2First)
{
	ListNode *cur1 = NULL;
	ListNode *cur2 = NULL;
	ListNode *result = NULL;
	ListNode *tail = NULL;
	ListNode *node = NULL;
	assert(p1First);
	assert(p2First);
	cur1 = p1First;
	cur2 = p2First;
	while((cur1 != NULL)&&(cur2 != NULL))
	{
		if(cur1->data<=cur2->data)
		{
			node = cur1;
			cur1 = cur1->next;
			if(tail == NULL)
			{
				result = node;
			}
			else
			{
				tail->next = node;
			}
			node->next = NULL;
			tail = node;
		}
		else
		{
			node = cur2;
			cur2 = cur2->next;
			if(tail == NULL)
			{
				result = node;
			}
			else
			{
				tail->next = node;
			}
			node->next = NULL;
			tail = node;
		}
	}
	if(cur1 != NULL)
	{
		tail->next = cur1;
	}
	if(cur2 != NULL)
	{
		tail->next = cur2;
	}
	return result;
}
//查找链表的中间结点（只能遍历一次链表）
ListNode *FindMid(ListNode *pFirst)
{
	ListNode *cur = NULL;
	ListNode *mid = NULL;
	int count = 0;
	assert(pFirst != NULL);
	cur = pFirst;
	mid = pFirst;
	while(cur != NULL)
	{
		cur = cur->next;
		count++;
		if((count%2)==0)
		{
			mid = mid->next;
			count = 0;
		}
		//cur = cur->next;
		//count++;
	}
	return mid;
}
//查找倒数第K个结点（只能遍历一次链表）
ListNode *FindK(ListNode *pFirst, int k)
{
	ListNode *fast = NULL;
	ListNode *slow = NULL;
	assert(pFirst != NULL);
	fast = pFirst;
	slow = pFirst;
	while(k)
	{
		fast = fast->next;
		k--;
	}
	while(fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
//删除倒数第K个结点（只能遍历一次链表，不能使用替换法删除）
void RemoveK(ListNode **pFirst, int k)
{
	ListNode *del = NULL;
	ListNode *fast = NULL;
	ListNode *slow = NULL;
	assert(*pFirst != NULL);
	fast = *pFirst;
	slow = *pFirst;
	while(k+1)
	{
		fast = fast->next;
		k--;
	}
	while(fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	del = slow->next;
	slow->next = slow->next->next;
	//free(del);
}
//求两个已排序单链表中相同的数据
ListNode *UnionSet(ListNode *list1, ListNode *list2)
{
	ListNode *cur1 = NULL;
	ListNode *cur2 = NULL;
	ListNode *result = NULL;
	ListNode *tail = NULL;
	ListNode *node = NULL;
	assert(list1 != NULL);
	assert(list2 != NULL);
	cur1 = list1;
	cur2 = list2;
	while((cur1 != NULL)&&(cur2 != NULL))
	{
		if(cur1->data<cur2->data)
		{
			cur1 = cur1->next;
		}
		else if(cur1->data>cur2->data)
		{
			cur2 = cur2->next;
		}
		else
		{
			node = cur1;
			cur1 = cur1->next;
			cur2 = cur2->next;
			if(tail == NULL)
			{
				result = node;
			}
			else
			{
				tail->next = node;
			}
			node->next = NULL;
			tail = node;
		}
	}
	return result;
}


//复杂链表的复制
//一个链表的每个结点，有一个指向next指针指向下一个结点，
//还有一个random指针指向这个链表中的随机一个结点或者NULL，
//现在要求实现复制这个链表，返回复制后的新链表
ComplexNode *CreateComNode(int data)
{
	ComplexNode *newNode = (ComplexNode *)malloc(sizeof(ComplexNode));
	newNode->data = data;
	newNode->next = NULL;
	newNode->random = NULL;
	return newNode;
}
ComplexNode *CopyComplexList(ComplexNode **pFirst)
{
	ComplexNode *newNode = NULL;
	ComplexNode *cur = NULL;
	//1.复制每个结点，让新结点跟在老结点后面
	cur = *pFirst;
	while(cur != NULL)
	{
		newNode = CreateComNode(cur->data);
		newNode->next = cur->next;
		cur->next = newNode;
		cur = newNode->next;
	}
	//2、复制random
	cur = *pFirst;
	while(cur != NULL)
	{
		newNode = cur->next;
		if(cur->random != NULL)
		{
			newNode->random = cur->random->next;
		}
		cur = newNode->next;
	}
	//3、把一个链表拆成两个链表
	ComplexNode *newNext = NULL;
	ComplexNode *next = NULL;
	ComplexNode *result = NULL;
	int flag = 1;
	cur = *pFirst;
	while(cur != NULL)
	{
		newNode = cur->next;
		if(flag)
		{
			result = newNode;
			flag = 0;
		}
		next = newNode->next;
		if(next == NULL)
		{
			newNext = NULL;
		}
		else
		{
			newNext = next->next;
		}
		cur->next = next;
		newNode->next = newNext;
		cur = next;
	}
	return result;
}
//判断两个链表是否相交，若相交，求交点（假设链表不带环）
int GetListLen(ListNode *p)
{
	int count = 0;
	ListNode *cur = p;
	while(cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
ListNode *IsIntersect(ListNode *p1, ListNode *p2)
{
	ListNode *cur1 = p1;
	ListNode *cur2 = p2;
	int len1 = 0;
	int len2 = 0;
	int ret = 0;
	while(cur1 != NULL)
	{
		cur1 = cur1->next;
	}
	while(cur2 = cur2->next)
	{
		cur2 = cur2->next;
	}
	if(cur1 == cur2)//如果条件成立，说明相交
	{
		cur1 = p1;
		cur2 = p2;
		len1 = GetListLen(p1);
		len2 = GetListLen(p2);
		if(len1>len2)
		{
			ret = len1-len2;
			while(ret--)
			{
				cur1 = cur1->next;
			}
		}
		else if(len1<len2)
		{
			ret = len2-len1;
			while(ret--)
			{
				cur2 = cur2->next;
			}
		}
		while(cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1; //找到交点
	}
	else
		return NULL;
}

//判断单链表是否带环？若带环，求环的长度？求环的入口点？
//判断是否带环，带环返回快慢指针相遇结点
ListNode *IsCircleList(ListNode *p)
{
	int count = 0;
	ListNode *fast = p;
	ListNode *slow = p;
	while(fast != NULL)
	{
		fast = fast->next;
		count++;
		if(count%2==0)
		{
			slow = slow->next;
		}
		if(fast == NULL)
		{
			break;
		}
		if(fast == slow)
		{
			return fast;
		}
	}
	return NULL;
}
//求环的长度
int LenOfCircle(ListNode *p)
{
	int count = 0;
	ListNode *cur = NULL;
	ListNode *NodeInCircle = NULL;
	//从头遍历链表，找到相遇点
	NodeInCircle = IsCircleList(p);
	cur = p;
	while(cur != NodeInCircle)
	{
		cur = cur->next;
	}
	while(cur->next != NodeInCircle)
	{
		cur = cur->next;
		count++;
	}
	count++;
	return count;
}
//求环的入口点
ListNode *EntryNode(ListNode *p)
{
	ListNode *dot = NULL;
	ListNode *ret = NULL;
	ListNode *cur = NULL;
	ListNode *NodeInCircle = NULL;
	//从头遍历链表，找到相遇点
	NodeInCircle = IsCircleList(p);
	cur = p;
	//找出相遇点的前一个结点，将它置为空指针，相当于从相遇点断开环
	//然后以两条链表相交的角度找入口点，两条链表相交处就是环的入口点
	while(cur->next != NodeInCircle)
	{
		cur = cur->next;
	}
	dot = cur;
	cur->next = NULL;
	cur = NodeInCircle;
	ret = p;
	while(cur != ret)
	{
		cur = cur->next;
		ret = ret->next;
	}
	dot->next = NodeInCircle;
	return cur;
}

//判断两个链表是否相交，若相交，求交点（假设链表带环）【升级版】
