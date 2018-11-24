#include "Queue.h"

void test()
{
	Queue queue;
	QueueInit(&queue);
	QueueInsert(&queue, 1);
	QueueInsert(&queue, 2);
	QueueInsert(&queue, 3);
	QueueInsert(&queue, 4);
	QueueInsert(&queue, 5);
	QueuePrint(&queue);
	QueueErase(&queue);
	QueuePrint(&queue);

}
int main()
{
	test();
	return 0;
}