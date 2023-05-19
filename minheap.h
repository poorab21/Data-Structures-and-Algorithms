#include<iostream>
#ifndef MINHEAP
#define MINHEAP
class minheap{
	private:
	int arraysize;
	int heapsize;
	int *data;
	public:
		minheap();
		minheap(const int);
		~minheap();
		int getLeftChild(int);
		int getRightChild(int);
		int getParentNode(int);
		bool isEmpty();
		void Print();
		void Insert(int);
		void shiftDown(int);
		void shiftUp(int);
		void RemoveMin();
};
#endif
