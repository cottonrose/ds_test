#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef char DataType;
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

//����ƥ������
void MatchBrackets(char *str);