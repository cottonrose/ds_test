#include "SeqList.h"
#include <stdio.h>

//尾插
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
//头插
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
//查找指定元素
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
		printf("要查找的元素不存在\n");
	}
	else
	{
		printf("找到了，下标是%d\n",pos);
	}
	SeqShow(&seqlist);
	SeqDestory(&seqlist);
}
//在指定位置插入元素
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
//尾删
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
//头删
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
//指定位置删除（下标删除）
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
//删除指定数据（数据删除）
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
//删除所有指定数据（数据删除）
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
//查看是否为空属性
void EmptyTest()
{
	int ret = 0;
	SeqList seqlist;
	SeqInit(&seqlist);
	ret = Empty(&seqlist);
	if(ret != 0)
	{
		printf("非空顺序表\n");
	}
	else
	{
		printf("空顺序表\n");
	}
}
//查看是否满了
void FullTest()
{
	int ret = 0;
	SeqList seqlist;
	SeqInit(&seqlist);
	ret = Full(&seqlist);
	if(ret != 0)
	{
		printf("非满顺序表\n");
	}
	else
	{
		printf("满顺序表\n");
	}
}
//查看顺序表长度
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
	printf("顺序表长度为%d\n",sz);
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
		printf("要查找的元素不存在\n");
	}
	else
	{
		printf("找到了，下标是%d\n",pos);
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
