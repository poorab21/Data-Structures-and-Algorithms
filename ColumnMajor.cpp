#include<iostream>
int main()
{
	int arr[100][100],arr2[100],size=0,rows,columns;
	int searchrow,searchcolumn;
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
	for(int i=0;i<columns;i++)
	{
		for(int j=0;j<rows;j++)
		{
			arr2[size]=arr[j][i];
			size++;
		}
	}
	std::cout<<"Enter Row:";
	std::cin>>searchrow;
	std::cout<<"Enter Column:";
	std::cin>>searchcolumn;
	searchrow-=1;
	searchcolumn-=1;
	std::cout<<"Array["<<(searchrow+searchcolumn)+((rows-1)*(searchcolumn))<<"] = "<<arr2[(searchrow+searchcolumn)+((rows-1)*(searchcolumn))];
}
