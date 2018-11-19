#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAX 10
typedef int DataType;

typedef struct SeqList
{
	DataType data[MAX];
	int sz;
}SeqList,*pSeqList;

//��ʼ��˳���
void InitSeqList(pSeqList ps);
//��ӡ˳���
void ShowSeqList(pSeqList ps);
//β������
void PushBack(pSeqList ps, DataType d);
//β��ɾ��
void PushFront(pSeqList ps, DataType d);
//ͷ������
void PopBack(pSeqList ps);
//ͷ��ɾ��
void PopFront(pSeqList ps);
//����ָ��Ԫ��
int Find(pSeqList ps, DataType d);
//ָ��λ�ò��� (�ڲ��ҵ���Ԫ��֮ǰ����)
void Insert(pSeqList ps,int pos, DataType d);
//ɾ��ָ��λ��Ԫ��
void Erase(pSeqList ps,int pos);
//ɾ��ָ��Ԫ��
void Remove(pSeqList ps, DataType d);

#endif //__SEQLIST_H__

////ɾ��ָ��λ��Ԫ��
//void Erase(PSeqList pSeq, int pos);
////ɾ��ָ��Ԫ��
//void Remove(PSeqList pSeq, DataType data);
////ɾ�����е�ָ��Ԫ��
//void RemoveAll(PSeqList pSeq, DataType data);
////����˳���Ĵ�С
//int Size(PSeqList pSeq);
////�ж�˳����Ƿ�Ϊ��
//int Empty(PSeqList pSeq);
////ð������
//void BubbleSort(PSeqList pSeq);
////ѡ������
//void SelectSort(PSeqList pSeq);
////�Ż��汾
//void SelectSort_OP(PSeqList pSeq);
////���ֲ���
//int BinarySearch(PSeqList pSeq, DataType data);
////���ֲ��ҵĵݹ�д��
//int BinarySearch_R(PSeqList pSeq, DataType data);
////��ӡ
//void PrintSeqList(PSeqList pSeq);