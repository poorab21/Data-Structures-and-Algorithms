#include<iostream>
void Display(int *arr,const int size)
{
	for(int i=0;i<size;i++)
	{
		std::cout<<"Array["<<i<<"]:"<<arr[i]<<std::endl;
	}
}
void Insert(int *arr,int size,int index,int value)
{
	int determine=0;
		for(int i=0;i<size;i++)
		{
			if(arr[i] != 0 && i==size-1 && index<size)
			{
				std::cout<<"Overflow Error"<<std::endl;
				determine=1;
				break;
			}
			else if(arr[i]==0)
			{
				break;
			}
		}
	if(arr[index] != 0 && index==size-1 && determine==0)
	{
		std::cout<<"Will Cause Overflow"<<std::endl;
	}
	if(determine==0 && index<size)
	{
		if(arr[index]==0)
		{
		arr[index]=value;
		}
		else if(arr[index] != 0)
		{
		for(int i=size-1;i>index;i--)
		{
		if(arr[i]==0)
		{
			for(int j=i;j>index;j--)
			{
				arr[j]=arr[j-1];
			}
			arr[index]=value;
			break;
		}
		else if(arr[i] != 0 && i==index+1)
		{
			std::cout<<"Will Cause Overflow"<<std::endl;
			break;
		}
		}
		}
	}
	else if(index>size-1)
	{
		std::cout<<"Index Exceeds Array Size"<<std::endl;
	}
} 
void Delete(int *arr,int size,int index)
{
	int determine=0;
	static int x=0;
	for(int i=0;i<size;i++)
		{
			if(arr[i]==0 && i==size-1 && index<size)
			{
				std::cout<<"Underflow Error"<<std::endl;
				determine=1;
			}
			else if(arr[i] != 0)
			{
				break;
			}
		}
	if(index>=size)
	{
		std::cout<<"Index Exceeds Array Size"<<std::endl;
	}
	else if(index<size && arr[index] != 0 && determine==0)
	{
			for(int i=index;i<size-1;i++)
			{
				arr[i]=arr[i+1];
			}
			arr[(size-1)-x]=0;
			x++;
	}
	else if(index<size && arr[index]==0 && determine==0)
	{
		std::cout<<"Nothing to Delete"<<std::endl;
	}
}
int main()
{
	int arr[100],size,index,value;
	char ch='y';
	std::cout<<"Enter Size:";
	std::cin>>size;
	for(int i=0;i<size;i++)
	{
		arr[i]=0;
	}
	while(ch=='y')
	{
		std::cout<<"Would you like to Insert Value in Array:";
		std::cin>>ch;
		if(ch=='y')
		{
			Display(arr,size);
			std::cout<<"Enter Index:";
			std::cin>>index;
			std::cout<<"Enter Value:";
			std::cin>>value;
			Insert(arr,size,index,value);
		}
		else if(ch=='n')
		{
			break;
		}
	} 
	ch='y';
	while(ch=='y')
	{
		std::cout<<"Would you like to Delete Value in Array:";
		std::cin>>ch;
		if(ch=='y')
		{
			Display(arr,size);
			std::cout<<"Enter Index:";
			std::cin>>index;
			Delete(arr,size,index);
		}
		else if(ch=='n')
		{
			break;
		}
	}
}
