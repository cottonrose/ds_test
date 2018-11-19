#include <stdio.h>
#include "SeqList.h"

void TestPushBack()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq,1);
	PushBack(&seq,2);
	PushBack(&seq,3);
	PushBack(&seq,4);
	PushBack(&seq,5);
	ShowSeqList(&seq);
	PopBack(&seq);
	ShowSeqList(&seq);
}

void TestPushFront()
{
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq,1);
	PushFront(&seq,2);
	PushFront(&seq,3);
	PushFront(&seq,4);
	PushFront(&seq,5);
	ShowSeqList(&seq);
	PopFront(&seq);
	ShowSeqList(&seq);
}

void TestFind()
{
	SeqList seq;
	int ret = 0;
	InitSeqList(&seq);
	PushFront(&seq,1);
	PushFront(&seq,2);
	PushFront(&seq,5);
	PushFront(&seq,3);
	PushFront(&seq,4);
	PushFront(&seq,5);
	ret = Find(&seq,5);
	if(ret == -1)
	{
		printf("Ҫ���ҵ�Ԫ�ز�����\n");
	}
	else
	{
		printf("Ԫ�ز��ҵ��ˣ��±�Ϊ%d\n",ret);
	}
}

void TestInsert()
{
	SeqList seq;
	int ret = 0;
	InitSeqList(&seq);
	PushFront(&seq,1);
	PushFront(&seq,2);
	PushFront(&seq,5);
	PushFront(&seq,3);
	PushFront(&seq,4);
	PushFront(&seq,5);
	ret = Find(&seq,5);
	if(ret == -1)
	{
		printf("Ҫ���ҵ�Ԫ�ز�����\n");
	}
	else
	{
		printf("Ԫ�ز��ҵ��ˣ��±�Ϊ%d\n",ret);
		Insert(&seq,ret,9);
	}
	ShowSeqList(&seq);

}

void TestErase()
{
	SeqList seq;
	int ret = 0;
	InitSeqList(&seq);
	PushFront(&seq,1);
	PushFront(&seq,2);
	PushFront(&seq,5);
	PushFront(&seq,3);
	PushFront(&seq,4);
	PushFront(&seq,5);
	ret = Find(&seq,5);
	if(ret == -1)
	{
		printf("Ҫ���ҵ�Ԫ�ز�����\n");
	}
	else
	{
		printf("Ԫ�ز��ҵ��ˣ��±�Ϊ%d\n",ret);
		Erase(&seq,ret);
	}
	ShowSeqList(&seq);
}

void TestRemove()
{
	SeqList seq;
	int ret = 0;
	InitSeqList(&seq);
	PushFront(&seq,1);
	PushFront(&seq,2);
	PushFront(&seq,5);
	PushFront(&seq,3);
	PushFront(&seq,4);
	PushFront(&seq,5);
	ShowSeqList(&seq);
	Remove(&seq,5);
	ShowSeqList(&seq);

}

int main()
{
	//TestPushBack();
	//TestPushFront();
	//TestFind();
	//TestInsert();
	//TestErase();
	TestRemove();
	return 0;
}