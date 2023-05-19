#include<iostream>
int main()
{
	int arr[100],size,sub,j;
	std::cout<<"Enter Size:";
	std::cin>>size;
	for(int i=0;i<size;i++)
	{
		std::cout<<"Enter Number:";
		std::cin>>arr[i];
	}
	for(int i=1;i<size;i++)
	{
		j=i;
		sub=arr[i];
		while(j>0 && arr[j-1]>sub)
		{
			arr[j]=arr[j-1];
			j--;
		}
			arr[j]=sub;
	}
	system("cls");
	for(int i=0;i<size;i++)
		{
			std::cout<<arr[i]<<"\n";
		}
}
