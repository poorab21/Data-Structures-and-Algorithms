#include<iostream>
int size,i=0,n2=-1;
int* ArrayCreate(int *arr,int size)
{
	arr=new int[size];
	for(int i=0;i<size;i++)
	{
		arr[i]=0;
	}
	return arr;
}
void Insert(int *arr,int data)
{
	if(i==size)
	{
		std::cout<<"Array Overflow"<<std::endl;
	}
	else
	{
		arr[i]=data;
		i++;
		n2++;
	}
}
void Delete(int *arr,int data)
{
	int n=0;
	if(i==0)
	{
		std::cout<<"Array Underflow"<<std::endl;
	}
	else
	{
		for(int j=0;j<size;j++)
		{
			if(data==arr[j])
			{
				for(int k=j;k<size-1;k++)
				{
					arr[k]=arr[k+1];
				}
				arr[n2]=0;
				n2--;
				n=1;
				i--;
			}
		}
		if(n==0)
		{
			std::cout<<"Element not Found"<<std::endl;
		}
	}
}
void Display(int *arr)
{
	for(int i=0;i<size;i++)
	{
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}
int main()
{
	int choice,value,*arr;
	std::cout<<"Enter Size:";
	std::cin>>size;
	arr=ArrayCreate(arr,size);
	while(1)
	{
		std::cout<<"1.INSERT VALUE"<<std::endl;
		std::cout<<"2.DELETE VALUE"<<std::endl;
		std::cout<<"3.DISPLAY"<<std::endl;
		std::cout<<"4.EXIT"<<std::endl;
		std::cout<<"Choose Option:";
		std::cin>>choice;
		if(choice==1)
		{
			system("cls");
			std::cout<<"Enter Value to Insert:";
			std::cin>>value;
			Insert(arr,value);
		}
		else if(choice==2)
		{
			system("cls");
			std::cout<<"Enter Value to Delete:";
			std::cin>>value;
			Delete(arr,value);
		}
		else if(choice==3)
		{
			system("cls");
			Display(arr);
		}
		else if(choice==4)
		{
			return 0;
		}
	}
}
