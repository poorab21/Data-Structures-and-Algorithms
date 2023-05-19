#include<iostream>
void swap(int &x,int &y)
{
	int sub=x;
	x=y;
	y=sub;
}
void Max_Heapify(int *arr,int i,int size)
{
	int leftchild=(2*i)+1;
	int rightchild=(2*i)+2;
	int largest=i;
	if(arr[largest]<arr[leftchild] && leftchild<size)
	{
		largest=leftchild;
	}
	if(arr[largest]<arr[rightchild] && rightchild<size)
	{
		largest=rightchild;
	}
	if(largest != i)
	{
		swap(arr[i],arr[largest]);
		Max_Heapify(arr,largest,size);
	}
	else
	{
		return;
	}
}
void Build_Heap(int *arr,int size)
{
	int n=(size/2)-1;
	for(int i=n;i>=0;i--)
	{
		Max_Heapify(arr,i,size);
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
	Build_Heap(arr,size);
	std::cout<<"Max Heap = ";
	for(int i=0;i<size;i++)
	{
		std::cout<<arr[i]<<" ";
	}
}
