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

//��ʼ��
void ListInit(ListNode **pFirst);
//����
void ListDestory(ListNode **pFirst);
//��ӡ����
void ListPrint(ListNode **pFirst);
//β��
void ListPushBack(ListNode **pFirst, DataType data);
//ͷ��
void ListPushFront(ListNode **pFirst, DataType data);
// ��ֵ���ң����ص�һ���ҵ��Ľ��ָ�룬���û�ҵ������� NULL 
ListNode *ListFind(ListNode **pFirst, DataType data);
// ����������(���뵽���ǰ)
void ListInsert(ListNode **pFirst, ListNode *pos, DataType data);
//βɾ
void ListPopBack(ListNode **pFirst);
//ͷɾ
void ListPopFront(ListNode **pFirst);
//�������ɾ��
void ListErase(ListNode **pFirst, ListNode *pos);
//ɾ��ָ��Ԫ��
void ListRemove(ListNode **pFirst, DataType data);
//ɾ������ָ��Ԫ��
void ListRemoveAll(ListNode **pFirst, DataType data);

//����������
//�����ӡ����
//1��last��ʽ
void ReversePrint(ListNode **pFirst);
//2���ݹ鷽ʽ
void ReversePrintR(ListNode *pFirst);
//��������
ListNode *ReverseList(ListNode **pFirst);
//ɾ��һ����ͷ������ķ�β���
void RemoveNodeNotTail(ListNode *pos);
//��ͷ����ǰ����
void InsertNoHead(ListNode *pos, int data);
//������ʵ��Լɪ��
ListNode *JocephCircle(ListNode *pFirst, int k);
//ð������
void BubbleSort(ListNode **pFirst);
//�ϲ�������������
ListNode *MergeOrderedList(ListNode *p1First, ListNode *p2First);
//����������м��㣨ֻ�ܱ���һ������
ListNode *FindMid(ListNode *pFirst);
//���ҵ�����K����㣨ֻ�ܱ���һ������
ListNode *FindK(ListNode *pFirst, int k);
//ɾ��������K����㣨ֻ�ܱ���һ����������ʹ���滻��ɾ����
void RemoveK(ListNode **pFirst, int k);
//��������������������ͬ������
ListNode *UnionSet(ListNode *list1, ListNode *list2);

//��������ĸ���
//һ�������ÿ����㣬��һ��ָ��nextָ��ָ����һ����㣬
//����һ��randomָ��ָ����������е����һ��������NULL��
//����Ҫ��ʵ�ָ�������������ظ��ƺ��������
ComplexNode *CreateComNode(int data);
ComplexNode *CopyComplexList(ComplexNode **pFirst);
//�ж����������Ƿ��ཻ�����ཻ���󽻵㣨��������������
ListNode *IsIntersect(ListNode *p1First, ListNode *p2First);
//�жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿
//�ж��Ƿ�������������ؿ���ָ���������
ListNode *IsCircleList(ListNode *p);
//�󻷵ĳ���
int LenOfCircle(ListNode *p);
//�󻷵���ڵ�
ListNode *EntryNode(ListNode *p);