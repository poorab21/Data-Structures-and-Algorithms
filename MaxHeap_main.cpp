#include"MaxHeap.h"
int main()
{
	maxheap m1(6);
	m1.insert(10);
	m1.insert(5);
	m1.insert(3);
	m1.insert(2);
	m1.insert(4);
	m1.insert(15);
	m1.Print();
	m1.Delete();
	m1.Print();
	m1.Delete();
	m1.Print();
	m1.Delete();
	m1.Print();
	m1.Delete();
	m1.Print();
	m1.Delete();
	m1.Print();
	m1.Delete();
	m1.Print();
}
