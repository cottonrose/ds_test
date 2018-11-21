#include "SeqListD.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//��ʼ��
void InitSeqList(SeqList *ps)
{
	assert(ps);
	ps->capacity = CAP;
	ps->size = 0;
	ps->array = (DataType *)malloc(sizeof(DataType)*CAP);
	assert(ps->array);
}

//����
void DestroySeqList(SeqList *ps)
{
	assert(ps);
	free(ps->array);
	ps->capacity = 0;
	ps->size = 0;
}

//�ж��Ƿ���Ҫ����
void SeqIfExpend(SeqList *ps)
{
	int i = 0;
	DataType *new_array = NULL;
	DataType *result = NULL;
	assert(ps);
	//����Ҫ����
	if(ps->size<ps->capacity)
	{
		return ;
	}
	new_array = (DataType *)malloc((ps->capacity+CAP)*sizeof(DataType));
	if(new_array != NULL)
	{
		result = new_array;
		for(i=0; i<ps->size; i++)
		{
			result[i] = ps->array[i];
		}
		ps->array = result;
		ps->capacity = (ps->capacity+CAP)*sizeof(DataType);
	}

}
//β��
void PushBack(SeqList *ps, DataType d)
{
	assert(ps);
	SeqIfExpend(ps);
	ps->array[ps->size] = d;
	ps->size++;
}

//��ӡ
void PrintSeqList(const SeqList *ps)
{
	int i = 0;
	assert(ps);
	for(i=0; i<ps->size; i++)
	{
		printf("%d ",ps->array[i]);
	}
	printf("\n");
}