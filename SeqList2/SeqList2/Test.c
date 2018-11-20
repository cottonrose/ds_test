#include "SeqList.h"
#include <stdio.h>

//β��
void PushBackTest()
{
	SeqList seqlist;
	SeqInit(&seqlist);
	PushBack(&seqlist,1);
	PushBack(&seqlist,2);
	PushBack(&seqlist,3);
	PushBack(&seqlist,4);
	PushBack(&seqlist,5);

	SeqShow(&seqlist);
	SeqDestory(&seqlist);
}
//ͷ��
void PushFrontTest()
{
	SeqList seqlist;
	SeqInit(&seqlist);
	PushFront(&seqlist,1);
	PushFront(&seqlist,2);
	PushFront(&seqlist,3);
	PushFront(&seqlist,4);
	PushFront(&seqlist,5);

	SeqShow(&seqlist);
	SeqDestory(&seqlist);
}
//����ָ��Ԫ��
void FindTest()
{
	int pos = 0;
	SeqList seqlist;
	SeqInit(&seqlist);
	PushFront(&seqlist,1);
	PushFront(&seqlist,2);
	PushFront(&seqlist,3);
	PushFront(&seqlist,4);
	PushFront(&seqlist,5);
	pos = Find(&seqlist,3);
	if(pos==-1)
	{
		printf("Ҫ���ҵ�Ԫ�ز�����\n");
	}
	else
	{
		printf("�ҵ��ˣ��±���%d\n",pos);
	}
	SeqShow(&seqlist);
	SeqDestory(&seqlist);
}
//��ָ��λ�ò���Ԫ��
void InsertTest()
{
	SeqList seqlist;
	SeqInit(&seqlist);
	PushFront(&seqlist,1);
	PushFront(&seqlist,2);
	PushFront(&seqlist,3);
	PushFront(&seqlist,4);
	PushFront(&seqlist,5);
	Insert(&seqlist,3,6);
	SeqShow(&seqlist);
	SeqDestory(&seqlist);
}
//βɾ
void PopBackTest()
{
	SeqList seqlist;
	SeqInit(&seqlist);
	PushFront(&seqlist,1);
	PushFront(&seqlist,2);
	PushFront(&seqlist,3);
	PushFront(&seqlist,4);
	PushFront(&seqlist,5);

	SeqShow(&seqlist);

	PopBack(&seqlist);
	SeqShow(&seqlist);

	SeqDestory(&seqlist);
}
//ͷɾ
void PopFrontTest()
{
	SeqList seqlist;
	SeqInit(&seqlist);
	PushFront(&seqlist,1);
	PushFront(&seqlist,2);
	PushFront(&seqlist,3);
	PushFront(&seqlist,4);
	PushFront(&seqlist,5);

	SeqShow(&seqlist);

	PopFront(&seqlist);
	SeqShow(&seqlist);

	SeqDestory(&seqlist);
}
//ָ��λ��ɾ�����±�ɾ����
void EraseTest()
{
	SeqList seqlist;
	SeqInit(&seqlist);
	PushFront(&seqlist,1);
	PushFront(&seqlist,2);
	PushFront(&seqlist,3);
	PushFront(&seqlist,4);
	PushFront(&seqlist,5);

	SeqShow(&seqlist);

	Erase(&seqlist,2);
	SeqShow(&seqlist);

	SeqDestory(&seqlist);
}
//ɾ��ָ�����ݣ�����ɾ����
void RemoveTest()
{
    SeqList seqlist;
	SeqInit(&seqlist);
	PushFront(&seqlist,1);
	PushFront(&seqlist,2);
	PushFront(&seqlist,3);
	PushFront(&seqlist,4);
	PushFront(&seqlist,5);

	SeqShow(&seqlist);

	Remove(&seqlist,3);
	SeqShow(&seqlist);

	SeqDestory(&seqlist);
}
//ɾ������ָ�����ݣ�����ɾ����
void RemoveAllTest()
{
    SeqList seqlist;
	SeqInit(&seqlist);
	PushFront(&seqlist,1);
	PushFront(&seqlist,3);
	PushFront(&seqlist,2);
	PushFront(&seqlist,3);
	PushFront(&seqlist,4);
	PushFront(&seqlist,3);
	PushFront(&seqlist,5);

	SeqShow(&seqlist);

	RemoveAll(&seqlist,3);
	SeqShow(&seqlist);

	SeqDestory(&seqlist);
}
//�鿴�Ƿ�Ϊ������
void EmptyTest()
{
	int ret = 0;
	SeqList seqlist;
	SeqInit(&seqlist);
	ret = Empty(&seqlist);
	if(ret != 0)
	{
		printf("�ǿ�˳���\n");
	}
	else
	{
		printf("��˳���\n");
	}
}
//�鿴�Ƿ�����
void FullTest()
{
	int ret = 0;
	SeqList seqlist;
	SeqInit(&seqlist);
	ret = Full(&seqlist);
	if(ret != 0)
	{
		printf("����˳���\n");
	}
	else
	{
		printf("��˳���\n");
	}
}
//�鿴˳�����
void SizeTest()
{
	int sz = 0;
	SeqList seqlist;
	SeqInit(&seqlist);
	PushBack(&seqlist,1);
	PushBack(&seqlist,2);
	PushBack(&seqlist,3);
	PushBack(&seqlist,4);
	PushBack(&seqlist,5);

	SeqShow(&seqlist);
	sz = Size(&seqlist);
	printf("˳�����Ϊ%d\n",sz);
	SeqDestory(&seqlist);
}

void BubbleSortTest()
{
	SeqList seqlist;
	SeqInit(&seqlist);
	PushBack(&seqlist,1);
	PushBack(&seqlist,3);
	PushBack(&seqlist,5);
	PushBack(&seqlist,7);
	PushBack(&seqlist,9);
	PushBack(&seqlist,2);
	PushBack(&seqlist,4);
	PushBack(&seqlist,6);

	SeqShow(&seqlist);
	BubbleSort(&seqlist);
	SeqShow(&seqlist);

	SeqDestory(&seqlist);
}
void BinarySearchTest()
{
	int pos = 0;
	SeqList seqlist;
	SeqInit(&seqlist);
	PushBack(&seqlist,1);
	PushBack(&seqlist,2);
	PushBack(&seqlist,3);
	PushBack(&seqlist,4);
	PushBack(&seqlist,5);
	PushBack(&seqlist,6);
	PushBack(&seqlist,7);
	PushBack(&seqlist,8);
	pos = Find(&seqlist,6);
	if(pos==-1)
	{
		printf("Ҫ���ҵ�Ԫ�ز�����\n");
	}
	else
	{
		printf("�ҵ��ˣ��±���%d\n",pos);
	}
	SeqShow(&seqlist);
}
void SelectSortTest()
{
	SeqList seqlist;
	SeqInit(&seqlist);
	PushBack(&seqlist,1);
	PushBack(&seqlist,3);
	PushBack(&seqlist,5);
	PushBack(&seqlist,7);
	PushBack(&seqlist,9);
	PushBack(&seqlist,2);
	PushBack(&seqlist,4);
	PushBack(&seqlist,6);

	SeqShow(&seqlist);
	BubbleSort(&seqlist);
	SeqShow(&seqlist);

	SeqDestory(&seqlist);
}
int main()
{
	//PushBackTest();
	//PushFrontTest();
	//FindTest();
	//InsertTest();
	//PopBackTest();
	//PopFrontTest();
	//EraseTest();
	//RemoveTest();
	//RemoveAllTest();
	//EmptyTest();
	//FullTest();
	//SizeTest();
	//BubbleSortTest();
	//BinarySearchTest();
	SelectSortTest();
	return 0;
}
