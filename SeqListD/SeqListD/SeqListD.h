#pragma once


#define CAP 5
typedef int DataType;

typedef struct SeqList
{
	DataType *array;
	int size;
	int capacity;
}SeqList;

//初始化
void InitSeqList(SeqList *ps); 
//销毁
void DestroySeqList(SeqList *ps); 
//尾插
void PushBack(SeqList *ps, DataType d); 
//打印顺序表
void PrintSeqList(const SeqList *ps); 
//尾删
void PopBack(SeqList *ps); 
//头插
void PushFront(SeqList *ps, DataType d); 
//头删
void PopFront(SeqList *ps); 
//指定位置插入
void Insert(SeqList *ps, int pos, DataType d); 
//排序
void Sort(SeqList *ps); 
//二分查找
int BinarySearch(SeqList *ps, DataType d); 
//寻找
int Find(SeqList ps, DataType d); 
//删除指定元素
void Remove(SeqList *ps, DataType d); 
//删除所有指定元素
void RemoveAll(SeqList *ps, DataType d);  
