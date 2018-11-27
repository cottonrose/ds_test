#include "MatchBrackets.h"

//≥ı ºªØ
void StackInit(Stack *ps)
{
	ps->top = 0;
}
//œ˙ªŸ
void StackDestory(Stack *ps)
{
	ps->top = 0;
}
//—π’ª
void StackPush(Stack *ps, DataType data)
{
	assert(ps->top<MAX_SIZE);
	ps->data[ps->top++] = data;
}
//≥ˆ’ª
void StackPop(Stack *ps)
{
	assert(ps->top>0);
	ps->top--;
}
//∑µªÿ’ª∂•‘™Àÿ
DataType StackTop(Stack *ps)
{
	assert(ps->top>0);
	return ps->data[ps->top-1];
}
//’ªµƒ‘™Àÿ∏ˆ ˝
int StackSize(Stack *ps)
{
	return ps->top;
}
//≈–∂œ’ª «∑ÒŒ™ø’
int StackEmpty(Stack *ps)
{
	if(ps->top==0)
		return 1;
	else
		return 0;
}

//¿®∫≈∆•≈‰Œ Ã‚
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
				printf("¿®∫≈≤ª∆•≈‰£¨”“¿®∫≈∂‡\n");
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
				printf("¿®∫≈≤ª∆•≈‰£¨◊Û”“¿®∫≈¥Œ–Ú≤ª’˝»∑\n");
				return ;
			}
		}
		str++;
	}
	if(StackEmpty(&stack))
	{
		printf("◊Û”“¿®∫≈∆•≈‰\n");
	}
	else
	{
		printf("¿®∫≈≤ª∆•≈‰£¨◊Û¿®∫≈∂‡\n");
	}
}