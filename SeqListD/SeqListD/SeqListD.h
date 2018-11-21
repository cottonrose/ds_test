#pragma once


#define CAP 5
typedef int DataType;

typedef struct SeqList
{
	DataType *array;
	int size;
	int capacity;
}SeqList;

//��ʼ��
void InitSeqList(SeqList *ps); 
//����
void DestroySeqList(SeqList *ps); 
//β��
void PushBack(SeqList *ps, DataType d); 
//��ӡ˳���
void PrintSeqList(const SeqList *ps); 
//βɾ
void PopBack(SeqList *ps); 
//ͷ��
void PushFront(SeqList *ps, DataType d); 
//ͷɾ
void PopFront(SeqList *ps); 
//ָ��λ�ò���
void Insert(SeqList *ps, int pos, DataType d); 
//����
void Sort(SeqList *ps); 
//���ֲ���
int BinarySearch(SeqList *ps, DataType d); 
//Ѱ��
int Find(SeqList ps, DataType d); 
//ɾ��ָ��Ԫ��
void Remove(SeqList *ps, DataType d); 
//ɾ������ָ��Ԫ��
void RemoveAll(SeqList *ps, DataType d);  
