#include"minheap.h"
minheap::minheap()
{
	this->arraysize=0;
	this->heapsize=0;
}
minheap::minheap(int size)
{
	this->arraysize=size;
	this->heapsize=0;
	this->data=new int[size];
}
minheap::~minheap()
{
	this->arraysize=0;
	this->heapsize=0;
	delete[] data;
}
int minheap::getLeftChild(int ParentNode)
{
	return (ParentNode*2)+1;
}
int minheap::getRightChild(int ParentNode)
{
	return (ParentNode*2)+2;
}
int minheap::getParentNode(int node)
{
	return (node-1)/2;
}
bool minheap::isEmpty()
{
	if(heapsize==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void minheap::Insert(int data)
{
	if(heapsize==arraysize)
	{
		std::cout<<"Heap Overflow"<<std::endl;
		return;
	}
	heapsize++;
	this->data[heapsize-1]=data;
	shiftUp(heapsize-1);
}
void minheap::Print()
{
	if(isEmpty())
	{
		std::cout<<"Heap is Empty"<<std::endl;
	}
	else
	{
		for(int i=0;i<heapsize;i++)
		{
			std::cout<<data[i]<<" ";
		}
		std::cout<<std::endl;
	}
}
void minheap::shiftUp(int nodeIndex)
{
	int parent=getParentNode(nodeIndex);
	if(nodeIndex != 0)
	{
		if(data[parent]>=data[nodeIndex])
		{
			int temp=data[parent];
			data[parent]=data[nodeIndex];
			data[nodeIndex]=temp;
			shiftUp(parent);
		}
	}
}
void minheap::shiftDown(int nodeIndex)
{
	int leftChild=getLeftChild(nodeIndex),minIndex;
	int rightChild=getRightChild(nodeIndex);
	if(rightChild>=heapsize)
	{
		if(leftChild>=heapsize)
		{
			return;
		}
		else
		{
			minIndex=leftChild;
		}
	}
	else
	{
		if(data[leftChild]<=data[rightChild])
		{
			minIndex=leftChild;
		}
		else
		{
			minIndex=rightChild;
		}
	}
		if(data[nodeIndex]>=data[minIndex])
		{
			int temp=data[nodeIndex];
			data[nodeIndex]=data[minIndex];
			data[minIndex]=temp;
			shiftDown(minIndex);
		}
}
void minheap::RemoveMin()
{
	if(heapsize==0)
	{
		std::cout<<"Heap is Empty"<<std::endl;
	}
	else
	{
		data[0]=data[heapsize-1];
		heapsize--;
		if(heapsize>=1)
		{
			shiftDown(0);
		}
	}
}
