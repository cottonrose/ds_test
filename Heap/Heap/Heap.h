#pragma once

#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 10

typedef struct
{
	int array[MAX_SIZE];
	int size;
}Heap;

//���µ���(���)
void AdjustDownMax(int array[], int size, int root);
//���µ���(С��)
void AdjustDownMin(int array[], int size, int root);
//���ϵ���
void AdjustUp(int array[], int size, int child);
//�ѵĴ���(���)
void HeapInitMax(int array[], int size, Heap *pH);
//�ѵĴ���(С��)
void HeapInitMin(int array[], int size, Heap *pH);
//���ضѶ�Ԫ��
int HeapTop(Heap *pH);
//�ѵ�ɾ������ѣ�
void HeapErase(Heap *pH);
//�ѵ�ɾ����С�ѣ�
void HeapEraseMin(Heap *pH);
//�ѵĲ���
void HeapInsert(Heap *pH, int data);
//��������TopK
void TopK(int array[],int size,int k);

