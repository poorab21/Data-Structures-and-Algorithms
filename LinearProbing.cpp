#include<iostream>
int arr[100],size;
void CreateArray(int *arr,int size)
{
	for(int i=0;i<size;i++)
	{
		arr[i]=0;
	}
}
void InsertKey(int value,int *arr,int size)
{
	int h=(value%size)+1,i=0;
	if(h>=size)
	{
		h=(h%size);
	}
	while(1)
	{
		if(i==size)
		{
			std::cout<<"Overflow Error"<<std::endl;
			break;
		}
		if(arr[h]==0)
		{
			arr[h]=value;
			break;
		}
		h=((h+1)%size);
		i++;
	}
}
void Search(int value,int *arr,int size)
{
	int h=(value%size)+1,i=0;
	if(h>=size)
	{
		h=(h%size);
	}
	while(arr[h] != value && i<size)
	{
		h=((h+1)%size);
		i++;
	}
	if(i==size)
	{
		std::cout<<"Element not Found"<<std::endl;
	}
	else
	{
		std::cout<<"Element Found at "<<h<<" Index"<<std::endl;
	}
}
void Delete(int value,int *arr,int size)
{
	int h=(value%size)+1,i=0;
	if(h>=size)
	{
		h=(h%size);
	}
	while(arr[h] != value && i<size)
	{
		h=((h+1)%size);
		i++;
	}
	if(i==size)
	{
		std::cout<<"Element Not Found"<<std::endl;
	}
	else
	{
		arr[h]='\0';
	}
}
void Display(int *arr,int size)
{
	for(int i=0;i<size;i++)
	{
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}
int main()
{
	int value,choice;
	while(1)
	{
		std::cout<<"1.CREATE ARRAY"<<std::endl;
		std::cout<<"2.INSERT KEY"<<std::endl;
		std::cout<<"3.SEARCH KEY"<<std::endl;
		std::cout<<"4.DELETE KEY"<<std::endl;
		std::cout<<"5.DISPLAY ARRAY"<<std::endl;
		std::cout<<"6.EXIT"<<std::endl;
		std::cout<<"Enter Choice:";
		std::cin>>choice;
		switch(choice)
		{
			case 1:
				std::cout<<"Enter Size:";
				std::cin>>size;
				system("cls");
				break;
			case 2:
				system("cls");
				for(int i=0;i<size;i++)
				{
					std::cout<<arr[i]<<" ";
				}
				std::cout<<std::endl;
				std::cout<<"Enter Key:";
				std::cin>>value;
				InsertKey(value,arr,size);
				break;
			case 3:
				system("cls");
				std::cout<<"Enter Key to Search:";
				std::cin>>value;
				Search(value,arr,size);
				break;
			case 4:
				system("cls");
				std::cout<<"Enter Key to Delete:";
				std::cin>>value;
				Delete(value,arr,size);
				break;
			case 5:
				system("cls");
				Display(arr,size);
				break;
		}
	}
}
