#pragma once

#define MAX_SIZE 100
typedef int DataType;
typedef struct SeqList
{
	DataType data[MAX_SIZE];
	int size;
}SeqList;

//��ʼ��
void SeqInit(SeqList *pSeq);
//����
void SeqDestory(SeqList *pSeq);
//��ӡ
void SeqShow(SeqList *pSeq);
//β��
void PushBack(SeqList *pSeq, DataType num);
//ͷ��
void PushFront(SeqList *pSeq, DataType num);
//����Ԫ��λ��
int Find(SeqList *pSeq, DataType num);
//��ָ��λ�ò���
void Insert(SeqList *pSeq, DataType num, DataType d);
//βɾ
void PopBack(SeqList *pSeq);
//ͷɾ
void PopFront(SeqList *pSeq);
//ָ��λ��ɾ�����±�ɾ����
void Erase(SeqList *pSeq, int pos);
//ָ��Ԫ��ɾ��������ɾ����
void Remove(SeqList *pSeq, DataType d);
//ָ������Ԫ��ɾ��������ɾ����
void RemoveAll(SeqList *pSeq, DataType d);
//�鿴�Ƿ�Ϊ������
int Empty(SeqList *pSeq);
//�鿴˳����Ƿ�����
int Full(SeqList *pSeq);
//�鿴˳�����
int Size(SeqList *pSeq);
//ð������
void BubbleSort(SeqList *pSeq);
//ѡ������
void SelectSort(SeqList *pSeq);
//�ö��ֲ��Ҳ���һ����
int BinarySearch(SeqList *pSeq, DataType d); 