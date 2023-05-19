#include<iostream>
#define SIZE 10
int top=-1;
bool IsFull()
{
	if(top==SIZE-1)
	{
		return 1;
	}
	return 0;
}
bool IsEmpty()
{
	if(top==-1)
	{
		return 1;
	}
	return 0;
}
void Push(int *arr,int value)
{
	if(IsFull())
	{
		std::cout<<"Overflow Error"<<std::endl;
	}
	else
	{
		top++;
		arr[top]=value;
	}
}
void Pop()
{
	if(IsEmpty())
	{
		std::cout<<"Underflow Error"<<std::endl;
	}
	else
	{
		top--;
	}
}
void Display(int *arr)
{
	for(int i=top;i>=0;i--)
	{
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}
int Peek(int *arr)
{
	return arr[top];
}
int main()
{
	int arr[SIZE],choice,value;
	while(1)
	{
		std::cout<<"1.PUSH VALUE INTO STACK"<<std::endl;
		std::cout<<"2.POP VALUE FROM STACK"<<std::endl;
		std::cout<<"3.TOP VALUE IN STACK"<<std::endl;
		std::cout<<"4.IS STACK EMPTY?"<<std::endl;
		std::cout<<"5.IS STACK FULL?"<<std::endl;
		std::cout<<"6.DISPLAY"<<std::endl;
		std::cout<<"7.EXIT"<<std::endl;
		std::cout<<"Enter your choice:";
		std::cin>>choice;
		if(choice==1)
		{
			std::cout<<"Enter Value to push in stack:";
			std::cin>>value;
			Push(arr,value);
		}
		else if(choice==2)
		{
			Pop();
		}
		else if(choice==3)
		{
			system("cls");
			std::cout<<"Top Value in Stack = "<<Peek(arr)<<std::endl;
		}
		else if(choice==4)
		{
			system("cls");
			if(IsEmpty())
			{
				std::cout<<"Stack is Empty"<<std::endl;
			}
			else
			{
				std::cout<<"Stack is not Empty"<<std::endl;
			}
		}
		else if(choice==5)
		{
			system("cls");
			if(IsFull())
			{
				std::cout<<"Array is Full"<<std::endl;
			}
			else
			{
				std::cout<<"Array is not Full"<<std::endl;
			}
		}
		else if(choice==6)
		{
			system("cls");
			Display(arr);
		}
		else if(choice==7)
		{
			return 0;
		}
	}
}
