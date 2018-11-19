#include "SeqList.h"

//初始化顺序表
void InitSeqList(pSeqList ps)
{
	assert(ps);
	ps->sz = 0;
	memset(ps->data,0,sizeof(ps->data));
}
//头部插入
void PushBack(pSeqList ps, DataType d)
{
	assert(ps);
	if(ps->sz == MAX)
	{
		printf("顺序表已满\n");
		return ;
	}
	ps->data[ps->sz] = d;
	ps->sz++;
}
//打印顺序表
void ShowSeqList(pSeqList ps)
{
	int i = 0;
	assert(ps);
	for(i=0; i<ps->sz; i++)
	{
		printf("%d ",ps->data[i]);
	}
	printf("\n");
}
//尾部删除
void PopBack(pSeqList ps)
{
	assert(ps);
	if(ps->sz == 0)
	{
		printf("顺序表已空\n");
	}
	ps->sz--;
}
//头部插入
void PushFront(pSeqList ps, DataType d)
{
	int i = 0;
	assert(ps);
	if(ps->sz == MAX)
	{
		printf("顺序表已满\n");
	}
	for(i=ps->sz; i>0; i--)
	{
		ps->data[i] = ps->data[i-1];
	}
	ps->data[0] = d;
	ps->sz++;
}
//头部删除
void PopFront(pSeqList ps)
{
	int i = 0;
	assert(ps);
	if(ps->sz == 0)
	{
		printf("顺序表为空\n");
		return;
	}
	for(i=1; i<ps->sz ;i++)
	{
		ps->data[i-1] = ps->data[i];
	}
	ps->sz--;
}
//查找指定元素
int Find(pSeqList ps, DataType d)
{
	int i = 0;
	assert(ps);
	for(i=0; i<ps->sz; i++)
	{
		if(ps->data[i] == d)
		{
			return i;
		}
	}
	return -1;
}
//在指定位置插入元素
void Insert(pSeqList ps,int pos, DataType d)
{
	int i = 0;
	assert(ps);
	if(ps->sz == MAX)
	{
		printf("顺序表已满\n");
		return ;
	}
	for(i=ps->sz; i>pos; i--)
	{
		ps->data[i] = ps->data[i-1];
	}
	ps->data[pos] = d;
	ps->sz++;
}
//删除指定位置元素
void Erase(pSeqList ps,int pos)
{
	int i = 0;
	assert(ps);
	if(ps->sz == 0)
	{
		return ;
	}
	for(i=pos; i<ps->sz-1; i++)
	{
		ps->data[i] = ps->data[i+1];
	}
	ps->sz--;
}

