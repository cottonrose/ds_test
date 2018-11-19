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

//初始化顺序表
void InitSeqList(pSeqList ps);
//打印顺序表
void ShowSeqList(pSeqList ps);
//尾部插入
void PushBack(pSeqList ps, DataType d);
//尾部删除
void PushFront(pSeqList ps, DataType d);
//头部插入
void PopBack(pSeqList ps);
//头部删除
void PopFront(pSeqList ps);
//查找指定元素
int Find(pSeqList ps, DataType d);
//指定位置插入 (在查找到的元素之前插入)
void Insert(pSeqList ps,int pos, DataType d);
//删除指定位置元素
void Erase(pSeqList ps,int pos);
//删除指定元素
void Remove(pSeqList ps, DataType d);

#endif //__SEQLIST_H__

////删除指定位置元素
//void Erase(PSeqList pSeq, int pos);
////删除指定元素
//void Remove(PSeqList pSeq, DataType data);
////删除所有的指定元素
//void RemoveAll(PSeqList pSeq, DataType data);
////返回顺序表的大小
//int Size(PSeqList pSeq);
////判断顺序表是否为空
//int Empty(PSeqList pSeq);
////冒泡排序
//void BubbleSort(PSeqList pSeq);
////选择排序
//void SelectSort(PSeqList pSeq);
////优化版本
//void SelectSort_OP(PSeqList pSeq);
////二分查找
//int BinarySearch(PSeqList pSeq, DataType data);
////二分查找的递归写法
//int BinarySearch_R(PSeqList pSeq, DataType data);
////打印
//void PrintSeqList(PSeqList pSeq);