#include<iostream>
void SelectionSort(int *arr,int size)
{
	int min,sub;
	for(int i=0;i<size-1;i++)
	{
		min=i;
		for(int j=i+1;j<size;j++)
		{
			if(arr[min]>arr[j])
			{
				min=j;
			}
		}
		if(min != i)
		{
			sub=arr[i];
			arr[i]=arr[min];
			arr[min]=sub;
		}
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
	SelectionSort(arr,size);
	for(int i=0;i<size;i++)
	{
		std::cout<<arr[i]<<std::endl;
	}
}
