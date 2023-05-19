#include<iostream>
void swap(int &x,int &y)
{
	int sub=x;
	x=y;
	y=sub;
}
void Min_Heapify(int arr[],int i,int size)
{
	int left=(i*2)+1,right=(i*2)+2,smallest=i;
	if(arr[i]>arr[left] && left<size)
	{
		smallest=left;
	}
	if(arr[smallest]>arr[right] && right<size)
	{
		smallest=right;
	}
	if(smallest != i)
	{
		swap(arr[i],arr[smallest]);
		Min_Heapify(arr,smallest,size);
	}
}
void build_Heap(int arr[],int size)
{
	for(int i=(size/2)-1;i>=0;i--)
	{
		Min_Heapify(arr,i,size);
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
	build_Heap(arr,size);
	std::cout<<"Min Heap = ";
	for(int i=0;i<size;i++)
	{
		std::cout<<arr[i]<<" ";
	}
}
