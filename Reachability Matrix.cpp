#include<iostream>
int main()
{
	int **arr,size;
	std::cout<<"Enter Number of Vertices:";
	std::cin>>size;
	arr=new int*[size];
	for(int i=0;i<size;i++)
	{
		arr[i]=new int[size];
	}
	for(int i=0;i<size;i++)
	{
		std::cout<<"Enter Elements for row "<<i+1<<":"<<std::endl;
		for(int j=0;j<size;j++)
		{
			std::cout<<"Enter Element:";
			std::cin>>arr[i][j];
		}
		std::cout<<std::endl;
	}
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			std::cout<<arr[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	for(int k=0;k<size;k++)
	{
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				if(arr[i][k]==1 && arr[k][j]==1)
				{
					arr[i][j]=1;
				}
			}
		}
	}
	std::cout<<"Reachability Matrix"<<std::endl;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			std::cout<<arr[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	for(int i=0;i<size;i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
