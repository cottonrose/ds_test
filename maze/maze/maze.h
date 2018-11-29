#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <windows.h>

#define MAX_SIZE 100

typedef struct
{
	int x;
	int y;
}Position;
typedef Position DataType;
typedef struct Stack
{
	DataType data[MAX_SIZE];
	int top;
}Stack;

//��ʼ��
void StackInit(Stack *ps);
//����
void StackDestory(Stack *ps);
//ѹջ
void StackPush(Stack *ps, DataType data);
//��ջ
void StackPop(Stack *ps);
//����ջ��Ԫ��
DataType StackTop(Stack *ps);
//ջ��Ԫ�ظ���
int StackSize(Stack *ps);
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack *ps);

//���Թ�
void FindExport1(int arr[][6], DataType *p);
void FindExport2(int arr[][6], DataType *p);
void FindExport3(int arr[][6], DataType *p);
