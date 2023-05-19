#include<iostream>
int main()
{
	int arr[100][100],rows,columns,count=0;
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
	int *arr2=new int[rows*columns];
	for(int i=0;i<columns;i++)
	{
		for(int j=0;j<rows;j++)
		{
			arr2[count]=arr[j][i];
			count++;
		}
	}
	std::cout<<"Enter Row to Search:";
	std::cin>>searchrow;
	std::cout<<"Enter Column to Search:";
	std::cin>>searchcolumn;
	std::cout<<"Array["<<((searchcolumn-1)*rows)+(searchrow-1)<<"] = "<<arr2[((searchcolumn-1)*rows)+(searchrow-1)]<<"\n";
	delete[] arr2;
}
