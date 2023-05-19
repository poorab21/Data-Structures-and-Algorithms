#include"minheap.h"
int main()
{
	minheap m1(10);
	m1.Insert(11);
	m1.Insert(3);
	m1.Insert(6);
	m1.Insert(15);
	m1.Insert(9);
	m1.Insert(8);
	m1.Print();
	m1.RemoveMin();
	m1.Print();
	m1.RemoveMin();
	m1.Print();
	m1.RemoveMin();
	m1.Print();
	m1.RemoveMin();
	m1.Print();
	m1.RemoveMin();
	m1.Print();
}

