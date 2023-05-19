#include<iostream>
void swap(int &x,int &y)
{
	int sub=x;
	x=y;
	y=sub;
}
void Max_Heapify(int *arr,int i,int size)
{
	int leftchild=(2*i)+1,rightchild=(2*i)+2,largest=i;
	if(arr[i]<arr[leftchild] && leftchild<size)
	{
		largest=leftchild;
	}
	if(arr[largest]<arr[rightchild] && rightchild<size)
	{
		largest=rightchild;
	}
	if(largest != i)
	{
		swap(arr[largest],arr[i]);
		Max_Heapify(arr,largest,size);
	}
}
void HeapSort(int *arr,int size)
{
	for(int i=(size/2);i>=0;i--)
	{
		Max_Heapify(arr,i,size);
	}
	for(int i=size-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		Max_Heapify(arr,0,i);
	}
}
int main()
{
	int arr[100],size;
	std::cout<<"Enter Size:";
	std::cin>>size;
	for(int i=0;i<size;i++)
	{
		std::cout<<"Enter Element:";
		std::cin>>arr[i];
	}
	for(int i=0;i<size;i++)
	{
		std::cout<<arr[i]<<" ";
	}
	HeapSort(arr,size);
	std::cout<<"\nAfter Sorting"<<std::endl;
	for(int i=0;i<size;i++)
	{
		std::cout<<arr[i]<<" ";
	}
}
