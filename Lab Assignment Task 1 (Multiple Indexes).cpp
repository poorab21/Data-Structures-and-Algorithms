#include<iostream>
int counter=0;
int* LinearSearch(int *arr,int size,int element)
{
	int length=0;
	for(int i=0;i<size;i++)
	{
		if(arr[i]==element)
		{
			length++;
		}
	}
	int *arr2=new int[length];
	if(length>0)
	{
	for(int i=0;i<size;i++)
	{
		if(arr[i]==element)
		{
			arr2[counter]=i;
			counter++;
		}
	}
	}
	return arr2;
}
int main()
{
	int size,element;
	std::cout<<"Enter Size:";
	std::cin>>size;
	int *arr=new int[size];
	for(int i=0;i<size;i++)
	{
		std::cout<<"Enter Array["<<i<<"]:";
		std::cin>>arr[i];
	}
	std::cout<<"Enter Element to Search:";
	std::cin>>element;
	int *arr2=LinearSearch(arr,size,element);
	if(counter>0)
	{
		std::cout<<"Element Found in Following Index Numbers\n";
		for(int i=0;i<counter;i++)
		{
		std::cout<<arr2[i]<<"\n";
		}
	}
	else if(counter==0)
	{
	std::cout<<"Element Not Found"<<std::endl;	
	}
	delete[] arr;
	delete[] arr2;
}
