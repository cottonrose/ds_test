#include "SeqListD.h"
#include <stdio.h>

void PushBackTest()
{
	SeqList seqlist;
	InitSeqList(&seqlist);
	PushBack(&seqlist,1);
	PushBack(&seqlist,2);
	PushBack(&seqlist,3);
	PushBack(&seqlist,4);
	PushBack(&seqlist,5);
	PushBack(&seqlist,6);
	PushBack(&seqlist,7);
	PushBack(&seqlist,8);

	PrintSeqList(&seqlist);

	DestroySeqList(&seqlist);


}
int main()
{
	PushBackTest();
	//PushFrontTest();
	//FindTest();
	//InsertTest();
	//PopBackTest();
	//PopFrontTest();
	//EraseTest();
	//RemoveTest();
	//RemoveAllTest();
	//BinarySearchTest();
	return 0;
}