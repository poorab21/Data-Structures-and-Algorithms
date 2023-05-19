#include<iostream>
int main()
{
	int arr[100][100],arr2[100],rows,columns,size=0;
	int searchrow,searchcolumn;
	std::cout<<"Enter Rows:";
	std::cin>>rows;
	std::cout<<"Enter Columns:";
	std::cin>>columns;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			std::cout<<"Enter Number["<<i+1<<","<<j+1<<"]:";
			std::cin>>arr[i][j];
		}
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			arr2[size]=arr[i][j];
			size++;
		}
	}
	std::cout<<"Enter Row to search:";
	std::cin>>searchrow;
	std::cout<<"Enter Column to search:";
	std::cin>>searchcolumn;
	searchrow-=1;
	searchcolumn-=1;
	std::cout<<"Array["<<((searchrow+searchcolumn)+(searchrow*(columns-1)))<<"] = "<<arr2[(searchrow+searchcolumn)+(searchrow*(columns-1))];
}

