#include<iostream>
int stack[100],size;
void push(int value)
{
	for(int i=size-1;i>=0;i--)
	{
		if(stack[i]==0)
		{
			stack[i]=value;
			break;
		}
		else if(i==0 && stack[i] != 0)
		{
			std::cout<<"Stack Overflow"<<std::endl;
		}
	}
}
void pop()
{
	for(int i=0;i<=size;i++)
	{
		if(stack[i] != 0)
		{
			stack[i]=0;
			break;
		}
		else if(i==size)
		{
			std::cout<<"Stack Underflow"<<std::endl;
		}
	}
}
void display()
{
	for(int i=0;i<size;i++)
	{
		std::cout<<stack[i]<<std::endl;
	}
}
int main()
{
	int choice,value;
	std::cout<<"Enter Size:";
	std::cin>>size;
	for(int i=0;i<size;i++)
	{
		stack[i]=0;	
	}
	while(1)
	{
		display();
		std::cout<<"1.PUSH"<<std::endl;
		std::cout<<"2.POP"<<std::endl;
		std::cout<<"3.EXIT"<<std::endl;
		std::cout<<"ENTER YOUR CHOICE:";
		std::cin>>choice;
		if(choice==1)
		{
			std::cout<<"Enter Value:";
			std::cin>>value;
			system("cls");
			push(value);
		}
		else if(choice==2)
		{
			system("cls");
			pop();
		}
		else if(choice==3)
		{
			return 0;
		}
	}
}
