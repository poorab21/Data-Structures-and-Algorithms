#include<iostream>
int size;
void Display(int**);
void Floyd_Warshall(int**);
int main()
{
	int **arr;
	std::cout<<"Enter Size:";
	std::cin>>size;
	arr=new int*[size];
	for(int i=0;i<size;i++)
	{
		arr[i]=new int[size];
	}
	for(int i=0;i<size;i++)
	{
		std::cout<<"Enter Elements for Row "<<i+1<<std::endl;
		for(int j=0;j<size;j++)
		{
			std::cin>>arr[i][j];
		}
		std::cout<<std::endl;
	}
	std::cout<<"Before Applying Floyd Warshall Algorithm"<<std::endl;
	Display(arr);
	std::cout<<"After Applying Floyd Warshall Algorithm"<<std::endl;
	Floyd_Warshall(arr);
	Display(arr);
}
void Display(int** arr)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			std::cout<<arr[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
void Floyd_Warshall(int **arr)
{
	for(int k=0;k<size;k++)
	{
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				if((arr[i][k]+arr[k][j])<arr[i][j])
				{
					arr[i][j]=(arr[i][k]+arr[k][j]);
				}
			}
		}
	}
}
