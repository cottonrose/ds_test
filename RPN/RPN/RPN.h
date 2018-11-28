#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef char DataType;

typedef enum
{
	NUM,
	OPERATE
}Type;

typedef enum
{
	ADD,
	SUB,
	MUL,
	DIV,
	DEFAULT
}OP;

typedef struct
{
	Type type;
	int data;
	OP operate;

}Item;

typedef struct Stack
{
	DataType data[MAX_SIZE];
	int top;
}Stack;

//初始化
void StackInit(Stack *ps);
//销毁
void StackDestory(Stack *ps);
//压栈
void StackPush(Stack *ps, DataType data);
//出栈
void StackPop(Stack *ps);
//返回栈顶元素
DataType StackTop(Stack *ps);
//栈的元素个数
int StackSize(Stack *ps);
//判断栈是否为空
int StackEmpty(Stack *ps);

//逆波兰表达式
int RPN(Item *arr, int sz);