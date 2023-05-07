#include<iostream>
int main()
{
	int element,sub,left=0,right,mid,count=0;
	int arr[100];
	for(int i=0;i<100;i++)
	{
		arr[i]=i+1;
	}
	for(int i=0;i<100;i++)
	{
		for(int j=i+1;j<100;j++)
		{
			if(arr[i]>arr[j])
			{
				sub=arr[i];
				arr[i]=arr[j];
				arr[j]=sub;
			}
		}
	}
	for(int i=0;i<100;i++)
	{
		std::cout<<"Array["<<i<<"] = "<<arr[i]<<std::endl;
	}
	right=99;
	std::cout<<"Enter Element to Search:";
	std::cin>>element;
	while(left<=right)
	{
		count++;
		mid=(left+right)/2;
		if(arr[mid]<element)
		{
			left=mid+1;
		}
		else if(arr[mid]>element)
		{
			right=mid-1;
		}
		else if(arr[mid]==element)
		{
			std::cout<<"Element Found at "<<mid<<" Index"<<std::endl;
			std::cout<<"Total Iterations = "<<count<<std::endl;
			break;
		}
	}
	if(left>right)
	{
		std::cout<<"Element Not found"<<std::endl;
		std::cout<<"Total Iterations = "<<count<<std::endl;
	}
}
