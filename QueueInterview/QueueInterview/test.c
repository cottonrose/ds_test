#include "Interview.h"

void test1()
{
	SDataType ret = 0;
	MinStack stack;
	MinStackInit(&stack);
	MinStackPush(&stack, 7);
	MinStackPush(&stack, 2);
	MinStackPush(&stack, 3);
	MinStackPush(&stack, 4);
	MinStackPush(&stack, 5);
	MinStackPush(&stack, 6);
	ret = MinStackTop(&stack);
	printf("%d\n",ret);
}
void test2()
{
	DouStaQueue queue;
	DouStaQueueInit(&queue);
	DouStaQueueInsert(&queue, 1);
	DouStaQueueInsert(&queue, 2);
	DouStaQueueInsert(&queue, 3);
	DouStaQueueInsert(&queue, 4);
	DouStaQueueInsert(&queue, 5);
	DouStaQueueErase(&queue);
}
void test3()
{
	DouQueStack stack;
	DouQueStackInit(&stack);
	DouQueStackInsert(&stack,1);
	DouQueStackInsert(&stack,2);
	DouQueStackInsert(&stack,3);
	DouQueStackInsert(&stack,4);
	DouQueStackInsert(&stack,5);
	DouQueStackErase(&stack);
}
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}