#include "maze.h"

void test1()
{
	int arr[6][6] = {
		{0,0,0,0,0,0},
		{0,0,1,0,0,0},
		{0,0,1,0,0,0},
		{0,0,1,1,1,0},
		{0,0,1,0,1,1},
		{0,0,1,0,0,0},};
	DataType entry;
	entry.x = 5;
	entry.y = 2;
	FindExport1(arr, &entry);
}

void test2()
{
	int arr[6][6] = {
		{0,0,0,0,0,0},
		{0,1,1,1,1,1},
		{0,1,0,0,0,0},
		{0,1,0,0,0,0},
		{0,1,1,1,1,1},
		{0,1,0,0,0,0},};
	DataType entry;
	entry.x = 5;
	entry.y = 1;
	FindExport2(arr, &entry);
}

void test3()
{
	int arr[6][6] = {
		{0,0,0,0,0,0},
		{0,1,1,1,0,0},
		{0,1,0,1,0,0},
		{0,1,0,1,0,0},
		{0,1,1,1,1,1},
		{0,1,0,0,0,0},};
	DataType entry;
	entry.x = 5;
	entry.y = 1;
	FindExport3(arr, &entry);
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}