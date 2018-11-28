#include "RPN.h"

//初始化
void StackInit(Stack *ps)
{
	ps->top = 0;
}
//销毁
void StackDestory(Stack *ps)
{
	ps->top = 0;
}
//压栈
void StackPush(Stack *ps, DataType data)
{
	assert(ps->top<MAX_SIZE);
	ps->data[ps->top++] = data;
}
//出栈
void StackPop(Stack *ps)
{
	assert(ps->top>0);
	ps->top--;
}
//返回栈顶元素
DataType StackTop(Stack *ps)
{
	assert(ps->top>0);
	return ps->data[ps->top-1];
}
//栈的元素个数
int StackSize(Stack *ps)
{
	return ps->top;
}
//判断栈是否为空
int StackEmpty(Stack *ps)
{
	if(ps->top==0)
		return 1;
	else
		return 0;
}

//逆波兰表达式
int RPN(Item *arr, int sz)
{
	int n1 = 0;
	int n2 = 0;
	OP tmp;
	Stack stack;
	StackInit(&stack);
	while(sz--)
	{
		if(arr->type==NUM)
		{
			StackPush(&stack, arr->data);
		}
		else if(arr->type==OPERATE)
		{
			tmp = arr->operate;
			n1 = StackTop(&stack);
			StackPop(&stack);
			n2 = StackTop(&stack);
			StackPop(&stack);
			switch(tmp)
			{
			case ADD:
				StackPush(&stack, n1+n2);
				break;
			case SUB:
				StackPush(&stack, n2-n1);
				break;
			case MUL:
				StackPush(&stack, n1*n2);
				break;
			case DIV:
				StackPush(&stack, n2/n1);
				break;
			default:
				break;
			}
		}
		arr++;
	}
	return StackTop(&stack);

}