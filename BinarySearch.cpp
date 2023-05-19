#include<iostream>
#include<math.h>
int binarysearch(int *arr,int left,int right,int element)
{
	double mid;
	int mid2;
	while(left<=right)
	{
		mid=(left+right)/2;
		mid2=ceil(mid);
		if(arr[mid2]<element)
		{
			left=mid2+1;
		}
		else if(arr[mid2]>element)
		{
			right=mid2-1;
		}
		else if(arr[mid2]==element)
		{
			return mid2;
		}
	}
	return -1;
}
int main()
{
	int size,element,sub,left=0,right;
	std::cout<<"Enter Size:";
	std::cin>>size;
	int *arr=new int[size];
	for(int i=0;i<size;i++)
	{
		std::cout<<"Enter Number:";
		std::cin>>arr[i];
	}
	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(arr[i]>arr[j])
			{
				sub=arr[i];
				arr[i]=arr[j];
				arr[j]=sub;
			}
		}
	}
	for(int i=0;i<size;i++)
	{
		std::cout<<"Array["<<i<<"] = "<<arr[i]<<std::endl;
	}
	right=size-1;
	std::cout<<"Enter Element to Search:";
	std::cin>>element;
	if(binarysearch(arr,left,right,element)==-1)
	{
		std::cout<<"Element not Found"<<std::endl;
	}
	else
	{
		std::cout<<"Element Found at "<<binarysearch(arr,left,right,element)<<" Index "<<std::endl; 
	}
	delete[] arr;
}
