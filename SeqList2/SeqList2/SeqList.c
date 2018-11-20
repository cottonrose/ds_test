#include "SeqList.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

//��ʼ��
void SeqInit(SeqList *pSeq)
{
	assert(pSeq != NULL);
	memset(pSeq,0,MAX_SIZE*sizeof(DataType));
	pSeq->size = 0;
}
//����
void SeqDestory(SeqList *pSeq)
{
	assert(pSeq != NULL);
	memset(pSeq,0,MAX_SIZE*sizeof(DataType));
	pSeq->size = 0;
}
//��ӡ
void SeqShow(SeqList *pSeq)
{
	int i = 0;
	assert(pSeq != NULL);
	for(i=0; i<pSeq->size; i++)
	{
		printf("%d ",pSeq->data[i]);
	}
	printf("\n");
}
//β��
void PushBack(SeqList *pSeq, DataType num)
{
	assert(pSeq != NULL);
	assert(pSeq->size != MAX_SIZE);
	pSeq->data[pSeq->size] = num;
	pSeq->size++;
}
//ͷ��
void PushFront(SeqList *pSeq, DataType num)
{
	int i = 0;
	int j = 0;
	assert(pSeq != NULL);
	assert(pSeq->size < MAX_SIZE);
#if 1
	//i ���� �����±� [size-1,0]
	for(i=pSeq->size-1; i>=0; i--)
	{
		pSeq->data[i+1] = pSeq->data[i];
	}
	pSeq->data[i+1] = num;
	pSeq->size++;
#else
	//j ���� �ռ��±� [size,0)
	for(j=pSeq->size; j>0; j--)
	{
		pSeq->data[j] = pSeq->data[j-1];
	}
	pSeq->data[j] = num;
	pSeq->size++;
#endif
}
//����Ԫ��
int Find(SeqList *pSeq, DataType num)
{
	int i = 0;
	assert(pSeq != NULL);
	for(i=0; i<pSeq->size; i++)
	{
		if(pSeq->data[i]==num)
		{
			return i;
		}
	}
	return -1;
}
//��ָ��λ�ò���Ԫ��
void Insert(SeqList *pSeq, DataType num, DataType d)
{
	int pos = 0;
	int i = 0;
	int j = 0;
	assert(pSeq != NULL);
	assert(pSeq->size < MAX_SIZE);
	pos = Find(pSeq,num);
#if 1
	//i ���� �����±� [size-1,pos]
	for(i=pSeq->size-1; i>=pos; i--)
	{
		pSeq->data[i+1] = pSeq->data[i];
	}
	pSeq->data[pos+1] = d;
	pSeq->size++;
#else
	//j ���� �ռ��±� [size,pos)
	for(j=pSeq->size; j>pos; j--)
	{
		pSeq->data[j] = pSeq->data[j-1];
	}
	pSeq->[pos] = d;
	pSeq->size++;
#endif
}
//βɾ
void PopBack(SeqList *pSeq)
{
	assert(pSeq != NULL);
	assert(pSeq->size != 0);
	pSeq->size--;
}
//ͷɾ
void PopFront(SeqList *pSeq)
{
	int i = 0;
	int j = 0;
	assert(pSeq != NULL);
	assert(pSeq->size != 0);
#if 1
	//i ���� �����±� [0,size-2]
	for(i=0; i<=pSeq->size-2; i++)
	{
		pSeq->data[i] = pSeq->data[i+1];
	}
	pSeq->size--;
#else
	//j ���� �ռ��±� [1,size)
	for(j=1; j<pSeq->size; j++)
	{
		pSeq->data[j-1] = pSeq->data[j];
	}
	pSeq->size--;
#endif
}
//ָ��λ��ɾ�����±�ɾ����
void Erase(SeqList *pSeq, int pos)
{
	int i = 0;
	assert(pSeq != NULL);
	assert(pSeq->size != 0);
	for(i=pos+1; i<pSeq->size; i++)
	{
		pSeq->data[i-1] = pSeq->data[i];
	}
	pSeq->size--;
}
//ָ��Ԫ��ɾ��������ɾ����
void Remove(SeqList *pSeq, DataType d)
{
	int i = 0;
	int pos = 0;
	assert(pSeq != NULL);
	assert(pSeq->size != 0);
	pos = Find(pSeq, d);
	if(pos == -1)
	{
		printf("û���ҵ���Ԫ��\n");
		return;
	}
	else
	{
		for(i=pos; i<pSeq->size; i++)
		{
			pSeq->data[i] = pSeq->data[i+1];
		}
		pSeq->size--;
	}
}
//ָ������Ԫ��ɾ��������ɾ����
void RemoveAll(SeqList *pSeq, DataType d)
{
	int i = 0;
	int j = 0;
	assert(pSeq != NULL);
	assert(pSeq->size>0 && pSeq->size<MAX_SIZE);
	for(i=0,j=0; i<pSeq->size; i++)
	{
		if(pSeq->data[i]!=d)
		{
			pSeq->data[j] = pSeq->data[i];
			j++;
		}
	}
	pSeq->size = j;
}
//�鿴�Ƿ�Ϊ������
int Empty(SeqList *pSeq)
{
	assert(pSeq != NULL);
	if(pSeq->size == 0)
		return 0;
	else
		return -1;
}
//�鿴˳����Ƿ�����
int Full(SeqList *pSeq)
{
	assert(pSeq != NULL);
	if(pSeq->size == MAX_SIZE)
		return 0;
	else
		return -1;
}
//�鿴˳�����
int Size(SeqList *pSeq)
{
	return pSeq->size;
}
//ð������
void BubbleSort(SeqList *pSeq)
{
	int i = 0;
	int j = 0;
	assert(pSeq != NULL);
	for(i=0; i<pSeq->size-1; i++)
	{
		for(j=i+1; j<pSeq->size; j++)
		{
			if(pSeq->data[i]>pSeq->data[j])
			{
				int tmp = pSeq->data[i];
				pSeq->data[i] = pSeq->data[j];
				pSeq->data[j] = tmp;
			}
		}
	}
}
//ѡ������
void SelectSort(SeqList *pSeq)
{
	int i = 0;
	int minSpace = 0;
	int maxSpace = 0;
	int max = 0;
	int min = 0;
	int ret1 = 0;
	int ret2 = 0;
	assert(pSeq != NULL);
	for(i=0; i<=pSeq->size/2; i++)
	{
		min = pSeq->data[minSpace];
		max = pSeq->data[maxSpace];
		for(minSpace = i,maxSpace = i; minSpace<pSeq->size; minSpace++,maxSpace++)
		{
			if(pSeq->data[minSpace]<min)
			{
				int tmp = pSeq->data[minSpace];
				pSeq->data[minSpace] = min;
				min = tmp;
			}
			if(pSeq->data[maxSpace]>max)
			{
				int tmp = pSeq->data[maxSpace];
				pSeq->data[maxSpace] = max;
				max = tmp;
			}
		}
		ret1 = max;
		ret2 = min;
		pSeq->data[minSpace] = ret2;
		pSeq->data[maxSpace] = ret1;
	}
}

//�ö��ֲ��Ҳ���һ����
int BinarySearch(SeqList *pSeq, DataType d)
{
	int pos = 0;
	int left = 0;
	int right = pSeq->size;
	while(left<right)
	{
		int mid = (right-left)/2+left;
		if(d<pSeq->data[mid])
		{
			right = mid - 1;
		}
		else if(d>pSeq->data[mid])
		{
			left = mid+1;
		}
		else
		{
			pos = mid;
			break;
		}
	}
	if(left>right)
		return -1;
	return pos;
}