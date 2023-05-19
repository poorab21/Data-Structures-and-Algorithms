#include<iostream>
class maxheap{
	private:
		int arraysize;
		int heapsize;
		int *data;
	public:
		maxheap(const int);
		~maxheap();
		int getHeapSize()const;
		void insert(int);
		void Print();
		bool IsEmpty();
		void Heapify(int,int);
		void Swap(int &,int &);
		void Max_Heapify(int);
		void Delete();
};
