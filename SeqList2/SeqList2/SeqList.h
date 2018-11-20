#pragma once

#define MAX_SIZE 100
typedef int DataType;
typedef struct SeqList
{
	DataType data[MAX_SIZE];
	int size;
}SeqList;

//初始化
void SeqInit(SeqList *pSeq);
//销毁
void SeqDestory(SeqList *pSeq);
//打印
void SeqShow(SeqList *pSeq);
//尾插
void PushBack(SeqList *pSeq, DataType num);
//头插
void PushFront(SeqList *pSeq, DataType num);
//查找元素位置
int Find(SeqList *pSeq, DataType num);
//在指定位置插入
void Insert(SeqList *pSeq, DataType num, DataType d);
//尾删
void PopBack(SeqList *pSeq);
//头删
void PopFront(SeqList *pSeq);
//指定位置删除（下标删除）
void Erase(SeqList *pSeq, int pos);
//指定元素删除（数据删除）
void Remove(SeqList *pSeq, DataType d);
//指定所有元素删除（数据删除）
void RemoveAll(SeqList *pSeq, DataType d);
//查看是否为空属性
int Empty(SeqList *pSeq);
//查看顺序表是否满了
int Full(SeqList *pSeq);
//查看顺序表长度
int Size(SeqList *pSeq);
//冒泡排序
void BubbleSort(SeqList *pSeq);
//选择排序
void SelectSort(SeqList *pSeq);
//用二分查找查找一个数
int BinarySearch(SeqList *pSeq, DataType d); 