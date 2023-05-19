#include<iostream>
int main()
{
	int arr[100][100],rows,columns,count=0;
	std::cout<<"Enter Rows:";
	std::cin>>rows;
	std::cout<<"Enter Columns:";
	std::cin>>columns;
	int *arr2=new int[rows*columns];
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			std::cout<<"Enter Array["<<i<<","<<j<<"]:";
			std::cin>>arr[i][j];
		}
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			std::cout<<arr[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			arr2[j*rows+i]=arr[i][j];
		}
	}
	std::cout<<std::endl;
	for(int i=0;i<(rows*columns);i++)
	{
		std::cout<<arr2[i]<<" ";
	}
	delete[] arr2;
}
