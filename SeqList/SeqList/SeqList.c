#include "SeqList.h"

//��ʼ��˳���
void InitSeqList(pSeqList ps)
{
	assert(ps);
	ps->sz = 0;
	memset(ps->data,0,sizeof(ps->data));
}
//ͷ������
void PushBack(pSeqList ps, DataType d)
{
	assert(ps);
	if(ps->sz == MAX)
	{
		printf("˳�������\n");
		return ;
	}
	ps->data[ps->sz] = d;
	ps->sz++;
}
//��ӡ˳���
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
//β��ɾ��
void PopBack(pSeqList ps)
{
	assert(ps);
	if(ps->sz == 0)
	{
		printf("˳����ѿ�\n");
	}
	ps->sz--;
}
//ͷ������
void PushFront(pSeqList ps, DataType d)
{
	int i = 0;
	assert(ps);
	if(ps->sz == MAX)
	{
		printf("˳�������\n");
	}
	for(i=ps->sz; i>0; i--)
	{
		ps->data[i] = ps->data[i-1];
	}
	ps->data[0] = d;
	ps->sz++;
}
//ͷ��ɾ��
void PopFront(pSeqList ps)
{
	int i = 0;
	assert(ps);
	if(ps->sz == 0)
	{
		printf("˳���Ϊ��\n");
		return;
	}
	for(i=1; i<ps->sz ;i++)
	{
		ps->data[i-1] = ps->data[i];
	}
	ps->sz--;
}
//����ָ��Ԫ��
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
//��ָ��λ�ò���Ԫ��
void Insert(pSeqList ps,int pos, DataType d)
{
	int i = 0;
	assert(ps);
	if(ps->sz == MAX)
	{
		printf("˳�������\n");
		return ;
	}
	for(i=ps->sz; i>pos; i--)
	{
		ps->data[i] = ps->data[i-1];
	}
	ps->data[pos] = d;
	ps->sz++;
}
//ɾ��ָ��λ��Ԫ��
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

