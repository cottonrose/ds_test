#include "RPN.h"


int main()
{
	int result = 0;
	Item a[] = {{NUM,3,DEFAULT},
	{NUM,4,DEFAULT},
	{OPERATE,-1,ADD},
	{NUM,5,DEFAULT},
	{NUM,6,DEFAULT},
	{OPERATE,-1,MUL},
	{OPERATE,-1,ADD},
	{NUM,7,DEFAULT},
	{OPERATE,-1,SUB}};
	int sz = sizeof(a)/sizeof(a[0]);
	result = RPN(a,sz);
	printf("%d\n",result);
	return 0;
}