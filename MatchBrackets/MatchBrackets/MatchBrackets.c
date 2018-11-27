#include "MatchBrackets.h"

//��ʼ��
void StackInit(Stack *ps)
{
	ps->top = 0;
}
//����
void StackDestory(Stack *ps)
{
	ps->top = 0;
}
//ѹջ
void StackPush(Stack *ps, DataType data)
{
	assert(ps->top<MAX_SIZE);
	ps->data[ps->top++] = data;
}
//��ջ
void StackPop(Stack *ps)
{
	assert(ps->top>0);
	ps->top--;
}
//����ջ��Ԫ��
DataType StackTop(Stack *ps)
{
	assert(ps->top>0);
	return ps->data[ps->top-1];
}
//ջ��Ԫ�ظ���
int StackSize(Stack *ps)
{
	return ps->top;
}
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack *ps)
{
	if(ps->top==0)
		return 1;
	else
		return 0;
}

//����ƥ������
void MatchBrackets(char *str)
{
	Stack stack;
	StackInit(&stack);
	while(*str != '\0')
	{
		if(*str=='('||*str=='['||*str=='{')
		{
			StackPush(&stack, *str);
		}
		else if(*str==')'||*str==']'||*str=='}')
		{
			if(StackEmpty(&stack))
			{
				printf("���Ų�ƥ�䣬�����Ŷ�\n");
				return ;
			}
			else if((StackTop(&stack)=='(' && *str==')')
				||(StackTop(&stack)=='[' && *str==']')
				||(StackTop(&stack)=='{' && *str=='}'))
			{
				StackPop(&stack);
			}
			else
			{
				printf("���Ų�ƥ�䣬�������Ŵ�����ȷ\n");
				return ;
			}
		}
		str++;
	}
	if(StackEmpty(&stack))
	{
		printf("��������ƥ��\n");
	}
	else
	{
		printf("���Ų�ƥ�䣬�����Ŷ�\n");
	}
}