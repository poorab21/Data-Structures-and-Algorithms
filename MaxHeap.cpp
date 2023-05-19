#include"MaxHeap.h"
void maxheap::Swap(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
bool maxheap::IsEmpty()
{
	if(this->heapsize==0)
	{
		return true;
	}
	return false;
}
maxheap::maxheap(int size)
{
	this->arraysize=size;
	this->heapsize=0;
	data=new int[size];
}
maxheap::~maxheap()
{
	this->arraysize=0;
	this->heapsize=0;
	delete[] data;
}
void maxheap::Heapify(int i,int size)
{
	int left=(i*2)+1,right=(i*2)+2,largest=i;
	if(data[largest]<data[left] && left<heapsize)
	{
		largest=left;
	}
	if(data[largest]<data[right] && right<heapsize)
	{
		largest=right;
	}
	if(largest != i)
	{
		Swap(data[i],data[largest]);
		Heapify(largest,size);
	}
	else
	{
		return;
	}
}
void maxheap::Max_Heapify(int size)
{
	int n=(heapsize/2)-1;
	for(int i=n;i>=0;i--)
	{
		Heapify(i,size);
	}
}
void maxheap::insert(int value)
{
	if(heapsize==arraysize)
	{
		std::cout<<"Heap Overflow"<<std::endl;
		return;
	}
	data[heapsize]=value;
	heapsize++;
	this->Max_Heapify(heapsize);
}
void maxheap::Delete()
{
	if(IsEmpty())
	{
		std::cout<<"Heap is Empty"<<std::endl;
	}
	else
	{
		data[0]=data[this->heapsize-1];
		Heapify(0,heapsize);
		heapsize--;
	}
}
int maxheap::getHeapSize()const
{
	return this->heapsize;
}
void maxheap::Print()
{
	if(IsEmpty())
	{
		std::cout<<"Heap is Empty"<<std::endl;
	}
	else
	{
		for(int i=0;i<this->heapsize;i++)
		{
			std::cout<<data[i]<<" ";
		}
		std::cout<<std::endl;
	}
}
