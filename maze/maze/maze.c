#include "maze.h"

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
	//assert(ps->top>0);
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

//��ӡ�Թ�
void PrintMaze(int arr[][6])
{
	int i = 0;
	int j = 0;
	for(i=0; i<6; i++)
	{
		for(j=0; j<6; j++)
		{
			if(arr[i][j]==1)
			{
				printf("  ");
			}
			else if(arr[i][j]==0)
			{
				printf("��");
			}
			else if(arr[i][j]==3)
			{
				printf("��");
			}
			else
			{
				printf("��");
			}
		}
		printf("\n");
	}
	printf("\n");
}
//���Թ�
void FindExport1(int arr[][6], DataType *p)
{
	Position pos;
	Stack stack;
	StackInit(&stack);
	pos.x = p->x;
	pos.y = p->y;
	StackPush(&stack, pos);
	while(1)
	{
		arr[pos.x][pos.y] = 2;
		//��
		if(arr[pos.x][pos.y-1]==1)
		{
			pos.y -=1;
			StackPush(&stack,pos);
			arr[pos.x][pos.y] = 2;
			if((pos.x==0||pos.x==5)||(pos.y==0||pos.y==5))
			{
				PrintMaze(arr);
				printf("�ҵ�����\n");
				return ;
			}
		}
		//��
		else if(arr[pos.x-1][pos.y]==1)
		{
			pos.x -=1;
			StackPush(&stack,pos);
			arr[pos.x][pos.y] = 2;
			if((pos.x==0||pos.x==5)||(pos.y==0||pos.y==5))
			{
				PrintMaze(arr);
				printf("�ҵ�����\n");
				return ;
			}
		}
		//��
		else if(arr[pos.x][pos.y+1]==1)
		{
			pos.y +=1;
			StackPush(&stack,pos);
			arr[pos.x][pos.y] = 2;
			if((pos.x==0||pos.x==5)||(pos.y==0||pos.y==5))
			{
				PrintMaze(arr);
				printf("�ҵ�����\n");
				return ;
			}
		}
		//��
		else if(arr[pos.x+1][pos.y]==1)
		{
			pos.x +=1;
			StackPush(&stack,pos);
			arr[pos.x][pos.y] = 2;
			if((pos.x==0||pos.x==5)||(pos.y==0||pos.y==5))
			{
				PrintMaze(arr);
				printf("�ҵ�����\n");
				return;
			}
		}
		else
		{
			arr[StackTop(&stack).x][StackTop(&stack).y] = 3;
			StackPop(&stack);
			pos = StackTop(&stack);
		}
		system("cls");
		PrintMaze(arr);
		Sleep(300);
	}
}

//ͨ·������
void FindExport2(int arr[][6], DataType *p)
{
	Position pos;
	Stack stack;
	StackInit(&stack);
	pos.x = p->x;
	pos.y = p->y;
	StackPush(&stack, pos);
	while(1)
	{
		arr[pos.x][pos.y] = 2;
		//��
		if(arr[pos.x][pos.y-1]==1)
		{
			pos.y -=1;
			StackPush(&stack,pos);
			arr[pos.x][pos.y] = 2;
			if((pos.x==0||pos.x==5)||(pos.y==0||pos.y==5))
			{
				PrintMaze(arr);
				printf("�ҵ�����\n");
				system("pause");
				continue;
			}
		}
		//��
		else if(arr[pos.x-1][pos.y]==1)
		{
			pos.x -=1;
			StackPush(&stack,pos);
			arr[pos.x][pos.y] = 2;
			if((pos.x==0||pos.x==5)||(pos.y==0||pos.y==5))
			{
				PrintMaze(arr);
				printf("�ҵ�����\n");
				system("pause");
				continue;
			}
		}
		//��
		else if(arr[pos.x][pos.y+1]==1)
		{
			pos.y +=1;
			StackPush(&stack,pos);
			arr[pos.x][pos.y] = 2;
			if((pos.x==0||pos.x==5)||(pos.y==0||pos.y==5))
			{
				PrintMaze(arr);
				printf("�ҵ�����\n");
				system("pause");
				continue;
			}
		}
		//��
		else if(arr[pos.x+1][pos.y]==1)
		{
			pos.x +=1;
			StackPush(&stack,pos);
			arr[pos.x][pos.y] = 2;
			if((pos.x==0||pos.x==5)||(pos.y==0||pos.y==5))
			{
				PrintMaze(arr);
				printf("�ҵ�����\n");
				system("pause");
				continue;
			}
		}
		else
		{
			arr[StackTop(&stack).x][StackTop(&stack).y] = 3;
			StackPop(&stack);
			pos = StackTop(&stack);
		}
		if(StackEmpty(&stack))
		{
			printf("���޳���\n");
			return ;
		}
		system("cls");
		PrintMaze(arr);
		Sleep(300);
	}
}

//ͨ·����
void FindExport3(int arr[][6], DataType *p)
{
	Position nextpos;
	arr[p->x][p->y] = 2;
	system("cls");
	PrintMaze(arr);
	Sleep(300);
	if(p->y==5)
	{
		printf("�ҵ�����\n");
		PrintMaze(arr);
		arr[p->x][p->y] = 1;
		system("pause");
		return ;
	}
	//��
	if(arr[p->x][(p->y)-1]==1)
	{
		nextpos = *p;
		nextpos.y -=1;
		FindExport3(arr, &nextpos);
	}
	//��
	if(arr[(p->x)-1][p->y]==1)
	{
		nextpos = *p;
		nextpos.x -=1;
		FindExport3(arr, &nextpos);
	}
	//��
	if(arr[p->x][(p->y)+1]==1)
	{
		nextpos = *p;
		nextpos.y +=1;
		FindExport3(arr, &nextpos);
	}
	//��
	if(arr[(p->x)+1][p->y]==1)
	{
		nextpos = *p;
		nextpos.x +=1;
		FindExport3(arr, &nextpos);
	}
	arr[p->x][p->y] = 1;
}