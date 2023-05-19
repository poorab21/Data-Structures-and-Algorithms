#include<iostream>
int main()
{
	int arr[100],size,sub,position,count;
	std::cout<<"Enter Size:";
	std::cin>>size;
	for(int i=0;i<size;i++)
	{
		std::cout<<"Enter Number:";
		std::cin>>arr[i];
	}
	for(int i=0;i<size-1;i++)
	{
		count=0;
		sub=arr[i];
		for(int j=i+1;j<size;j++)
		{
			if(sub>arr[j])
			{
				sub=arr[j];
				position=j;
				count=1;
			}
		}
		if(count>0)
		{
		arr[position]=arr[i];
		arr[i]=sub;
		}	
	}
	system("cls");
	for(int i=0;i<size;i++)
	{
		std::cout<<arr[i]<<std::endl;
	}
}
