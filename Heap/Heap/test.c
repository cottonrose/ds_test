#include "Heap.h"

void test()
{
	int array[100] = {0};
	int i = 0;
	int size = sizeof(array)/sizeof(array[0]);
	for(i=0; i<100; i++)
	{
		array[i] = i;
	}
	//int array[] = {53,17,78,9,45,65,87,23,31};
	//int size = sizeof(array)/sizeof(array[0]);
	//Heap heap;
	//HeapInitMin(array, size, &heap);
	//printf("%d\n",HeapTop(&heap));
	//HeapEraseMin(&heap);
	//printf("%d\n",HeapTop(&heap));
	//HeapInsert(&heap,76);
	//printf("%d\n",HeapTop(&heap));
	TopK(array,size,5);
}

int main()
{
	test();
	return 0;
}
