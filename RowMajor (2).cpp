#include<iostream>
int main()
{
	int arr[100][100],rows,columns,count=0;
	int rowsearch,columnsearch;
	std::cout<<"Enter Rows:";
	std::cin>>rows;
	std::cout<<"Enter Columns:";
	std::cin>>columns;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			std::cout<<"Enter Array["<<i+1<<","<<j+1<<"]:";
			std::cin>>arr[i][j];
		}
	}
	int *arr2=new int[rows*columns];
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			arr2[count]=arr[i][j];
			count++;
		}
	}
	std::cout<<"Enter Row to Search:";
	std::cin>>rowsearch;
	std::cout<<"Enter Column to Search:";
	std::cin>>columnsearch;
	std::cout<<"Array["<<((rowsearch-1)*columns)+(columnsearch-1)<<"] = "<<arr2[((rowsearch-1)*columns)+(columnsearch-1)]<<"\n";
	delete[] arr2;
}
