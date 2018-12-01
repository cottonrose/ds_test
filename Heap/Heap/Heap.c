#include "Heap.h"

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//向下调整(大堆)
void AdjustDownMax(int array[], int size, int root)
{
	while(1)
	{
		int left = 2 * root + 1;
		int right = 2 * root +2;
		int max = 0;
		if(left >= size)
		{
			return ;
		}
		max = left;
		if(right < size && array[right] > array[left])
		{
			max = right;
		}
		if(array[root] >= array[max])
		{
			return ;
		}
		else
		{
			Swap(&array[max], &array[root]);
		}
		root = max;
	}
}
//向下调整(小堆)
void AdjustDownMin(int array[], int size, int root)
{
	while(1)
	{
		int left = 2 * root + 1;
		int right = 2 * root +2;
		int min = 0;
		if(left >= size)
		{
			return ;
		}
		min = left;
		if(right < size && array[right] < array[left])
		{
			min = right;
		}
		if(array[root] <= array[min])
		{
			return ;
		}
		else
		{
			Swap(&array[min], &array[root]);
		}
		root = min;
	}
}
//向上调整
void AdjustUp(int array[], int size, int child)
{
	while(child > 0)
	{
		int parent = (child-1)/2;
		if(array[child] <= array[parent])
		{
			return ;
		}
		else
		{
			Swap(&array[child],&array[parent]);
		}
		child = parent;
	}
}
//堆的创建（大堆）
void HeapInitMax(int array[], int size, Heap *pH)
{
	int i = 0;
	int j = 0;
	assert(pH != NULL);
	for(i=0; i<size; i++)
	{
		pH->array[i] = array[i];
	}
	pH->size = size;
	for(i=0; i<=(size-2)/2; i++)
	{
		for(j=0; j<=(size-2)/2; j++)
		{
			AdjustDownMax(pH->array,pH->size,j);
		}
	}
}
//堆的创建(小堆)
void HeapInitMin(int array[], int size, Heap *pH)
{
	int i = 0;
	int j = 0;
	assert(pH != NULL);
	for(i=0; i<size; i++)
	{
		pH->array[i] = array[i];
	}
	pH->size = size;
	for(i=0; i<=(size-2)/2; i++)
	{
		for(j=0; j<=(size-2)/2; j++)
		{
			AdjustDownMin(pH->array,pH->size,j);
		}
	}
}
//返回堆顶元素
int HeapTop(Heap *pH)
{
	assert(pH != NULL);
	return pH->array[0];
}
//堆的删除(大堆)
void HeapEraseMax(Heap *pH)
{
	assert(pH != NULL);
	pH->array[0] = pH->array[pH->size-1];
	pH->size--;
	AdjustDownMax(pH->array,pH->size,0);
}
//堆的删除（小堆）
void HeapEraseMin(Heap *pH)
{
	assert(pH != NULL);
	pH->array[0] = pH->array[pH->size-1];
	pH->size--;
	AdjustDownMin(pH->array,pH->size,0);
}
//堆的插入
void HeapInsert(Heap *pH, int data)
{
	assert(pH != NULL);
	pH->array[pH->size] = data;
	pH->size++;
	AdjustUp(pH->array,pH->size,pH->size-1);
}
//海量数据TopK
void TopK(int array[],int size,int k)
{
	int i = 0;
	Heap minHeap;
	HeapInitMin(array,k,&minHeap);
	for(i=k;i<size;i++)
	{
		if(array[i]>HeapTop(&minHeap))
		{
			HeapEraseMin(&minHeap);
			HeapInsert(&minHeap,array[i]);
			AdjustDownMin(minHeap.array,k,0);
		}
		else
		{
			continue;
		}
	}
	for(i=0; i<k; i++)
	{
		printf("%d ",minHeap.array[i]);
	}
	printf("\n");
}