#include "List.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//��ʼ��
void ListInit(ListNode **pFirst)
{
	*pFirst = NULL; 
}
//����
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
//��ӡ����
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
//����һ���½��
ListNode *CreateNode(DataType data)
{
	ListNode *NewNode = (ListNode *)malloc(sizeof(DataType));
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}
//β��
void ListPushBack(ListNode **pFirst, DataType data)
{
	ListNode *cur = NULL;
	//�������Ϊ��
	if(*pFirst == NULL)
	{
		*pFirst = CreateNode(data);
		return ;
	}
	//����Ϊ��
	cur = *pFirst;
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = CreateNode(data);
}
//ͷ��
void ListPushFront(ListNode **pFirst, DataType data)
{
	ListNode *cur = NULL;
	//�������Ϊ��
	if(*pFirst == NULL)
	{
		*pFirst = CreateNode(data);
		return ;
	}
	//����Ϊ��
	cur = *pFirst;
	*pFirst = CreateNode(data);
	(*pFirst)->next = cur;
}
// ��ֵ���ң����ص�һ���ҵ��Ľ��ָ�룬���û�ҵ������� NULL 
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
// ����������(���뵽���ǰ)
void ListInsert(ListNode **pFirst, ListNode *pos, DataType data)
{
	ListNode *cur = NULL;
	ListNode *NewNode = NULL;
	assert(*pFirst != NULL);
	if(pos == NULL)
		return ;
	//����ڵ�һ��Ԫ��λ��ǰ���룬����ͷ�庯��
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
//βɾ
void ListPopBack(ListNode **pFirst)
{
	ListNode *cur = NULL;
	ListNode *del = NULL;
	assert(*pFirst != NULL);
	//�������ֻ��һ��Ԫ��
	if((*pFirst)->next == NULL)
		*pFirst = NULL;
	//��������ж��Ԫ��
	cur = *pFirst;
	while(cur->next->next != NULL)
	{
		cur = cur->next;
	}
	del = cur->next->next;
	cur->next = NULL;
	free(del);
}
//ͷɾ
void ListPopFront(ListNode **pFirst)
{
	ListNode *del = NULL;
	assert(*pFirst != NULL);
	//�������ֻ��һ��Ԫ��
	if((*pFirst)->next == NULL)
	{
		*pFirst = NULL;
	}
	//��������ж��Ԫ��
	del = *pFirst;
	*pFirst = (*pFirst)->next; 
	//free(del);
}
//�������ɾ��
void ListErase(ListNode **pFirst, ListNode *pos)
{
	ListNode *del = NULL;
	ListNode *cur = NULL;
	assert(*pFirst != NULL);
	//���������㲻����
	if(pos == NULL)
		return ;
	//�����������ǵ�һ��Ԫ��
	if(pos == *pFirst)
	{
		ListPopFront(pFirst);
		return ;
	}
	//���������������һ��
	else if(pos->next == NULL)
	{
		ListPopBack(pFirst);
		return ;
	}
	//�����������ǳ���β��Ԫ��
	cur = *pFirst;
	while(cur->next != pos)
	{
		cur = cur->next;
	}
	cur->next = cur->next->next;
	//free(pos);
}
//ɾ��ָ��Ԫ��
void ListRemove(ListNode **pFirst, DataType data)
{
	ListNode *cur = NULL;
	ListNode *del = NULL;
	assert(*pFirst != NULL);
	//���ɾ����Ԫ��Ϊ��һ��Ԫ��
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
//ɾ������ָ��Ԫ��
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


//����������

//�����ӡ����
//1��last��ʽ
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
//2���ݹ鷽ʽ
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
//��������
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
//ɾ��һ����ͷ������ķ�β���
void RemoveNodeNotTail(ListNode *pos)
{
	if(pos == NULL)
	{
		return ;
	}
	pos->data = pos->next->data;
	pos->next = pos->next->next;
}
//��ͷ����ǰ����
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
//������ʵ��Լɪ��
ListNode *JocephCircle(ListNode *pFirst, int k)
{
	ListNode *result = NULL;
	ListNode *pre = NULL;
	ListNode *cur = NULL;
	int i = 0;
	assert(pFirst != NULL);
	cur = pFirst;
	//��ʹ������һ���������һ������next���ڵ�һ����㣩
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = pFirst;
	//���������ʣ���㳬��һ����ÿ���ҵ���k����㣬ɾ����
	cur = pFirst;
	while(cur->next != cur)
	{
		for(i=0; i<k-1; i++)
		{
			pre = cur;
			cur = cur->next;
		}
		//ɾ��Ԫ��
		pre->next = cur->next;
		//free(cur);
		cur = pre->next;
	}
	result = cur;
	result->next = NULL;
	return result;
}
//ð������
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
//�ϲ�������������
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
//����������м��㣨ֻ�ܱ���һ������
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
//���ҵ�����K����㣨ֻ�ܱ���һ������
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
//ɾ��������K����㣨ֻ�ܱ���һ����������ʹ���滻��ɾ����
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
//��������������������ͬ������
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


//��������ĸ���
//һ�������ÿ����㣬��һ��ָ��nextָ��ָ����һ����㣬
//����һ��randomָ��ָ����������е����һ��������NULL��
//����Ҫ��ʵ�ָ�������������ظ��ƺ��������
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
	//1.����ÿ����㣬���½������Ͻ�����
	cur = *pFirst;
	while(cur != NULL)
	{
		newNode = CreateComNode(cur->data);
		newNode->next = cur->next;
		cur->next = newNode;
		cur = newNode->next;
	}
	//2������random
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
	//3����һ����������������
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
//�ж����������Ƿ��ཻ�����ཻ���󽻵㣨��������������
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
	if(cur1 == cur2)//�������������˵���ཻ
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
		return cur1; //�ҵ�����
	}
	else
		return NULL;
}

//�жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿
//�ж��Ƿ�������������ؿ���ָ���������
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
//�󻷵ĳ���
int LenOfCircle(ListNode *p)
{
	int count = 0;
	ListNode *cur = NULL;
	ListNode *NodeInCircle = NULL;
	//��ͷ���������ҵ�������
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
//�󻷵���ڵ�
ListNode *EntryNode(ListNode *p)
{
	ListNode *dot = NULL;
	ListNode *ret = NULL;
	ListNode *cur = NULL;
	ListNode *NodeInCircle = NULL;
	//��ͷ���������ҵ�������
	NodeInCircle = IsCircleList(p);
	cur = p;
	//�ҳ��������ǰһ����㣬������Ϊ��ָ�룬�൱�ڴ�������Ͽ���
	//Ȼ�������������ཻ�ĽǶ�����ڵ㣬���������ཻ�����ǻ�����ڵ�
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

//�ж����������Ƿ��ཻ�����ཻ���󽻵㣨��������������������桿
