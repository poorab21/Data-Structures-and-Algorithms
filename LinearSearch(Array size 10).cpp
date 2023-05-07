#include<iostream>
int main()
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	int size,element,count=0;
	for(int i=0;i<10;i++)
	{
		std::cout<<"Array["<<i<<"] = "<<arr[i]<<"\n";
	}
	std::cout<<"Enter Element to Search:";
	std::cin>>element;
	for(int i=0;i<10;i++)
	{
		count++;
		if(arr[i]==element)
		{
			std::cout<<"Element Found at "<<i<<" Index"<<std::endl;
			std::cout<<"Total Iterations = "<<count<<std::endl;
			break;
		}
		else if(arr[i] != element && i==9)
		{
			std::cout<<"Element Not Found"<<std::endl;
			std::cout<<"Total Iterations = "<<count<<std::endl;
		}
	}
	
}
