#include<iostream>
int main()
{
	int arr[1000];
	int size,element,count=0;
	for(int i=0;i<1000;i++)
	{
		arr[i]=i+1;
	}
	for(int i=0;i<1000;i++)
	{
		std::cout<<"Array["<<i<<"] = "<<arr[i]<<"\n";
	}
	std::cout<<"Enter Element to Search:";
	std::cin>>element;
	for(int i=0;i<1000;i++)
	{
		count++;
		if(arr[i]==element)
		{
			std::cout<<"Element Found at "<<i<<" Index"<<std::endl;
			std::cout<<"Total Iterations = "<<count<<std::endl;
			break;
		}
		else if(arr[i] != element && i==999)
		{
			std::cout<<"Element Not Found"<<std::endl;
			std::cout<<"Total Iterations = "<<count<<std::endl;
		}
	}
	
}
