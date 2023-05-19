#include<iostream>
int main()
{
	int arr[100],size,sub,size2;
	std::cout<<"Enter Size:";
	std::cin>>size;
	size2=size;
	for(int i=0;i<size;i++)
	{
		std::cout<<"Enter Number:";
		std::cin>>arr[i];
	}
	for(int i=1;i<size;i++)
	{
		int j=0;
		while(j<size2-1)
		{
			if(arr[j]>arr[j+1])
			{
				sub=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=sub;
			}
			j++;
		}
		size2--;
	}
	system("cls");
	for(int i=0;i<size;i++)
	{
		std::cout<<arr[i]<<std::endl;
	}
}
