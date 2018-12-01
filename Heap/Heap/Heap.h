#pragma once

#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 10

typedef struct
{
	int array[MAX_SIZE];
	int size;
}Heap;

//向下调整(大堆)
void AdjustDownMax(int array[], int size, int root);
//向下调整(小堆)
void AdjustDownMin(int array[], int size, int root);
//向上调整
void AdjustUp(int array[], int size, int child);
//堆的创建(大堆)
void HeapInitMax(int array[], int size, Heap *pH);
//堆的创建(小堆)
void HeapInitMin(int array[], int size, Heap *pH);
//返回堆顶元素
int HeapTop(Heap *pH);
//堆的删除（大堆）
void HeapErase(Heap *pH);
//堆的删除（小堆）
void HeapEraseMin(Heap *pH);
//堆的插入
void HeapInsert(Heap *pH, int data);
//海量数据TopK
void TopK(int array[],int size,int k);

