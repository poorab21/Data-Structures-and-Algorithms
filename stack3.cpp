#include<iostream>
char stack2[100];
int count=0;
void push(char x,int size)
{
	stack2[count]=x;
	count--;
}
void pop()
{
	stack2[count]='\0';
	count++;
}
int determine(char *arr,int size)
{
	count=size;
	int size2=0,size3=0;
	if(size%2==0)
	{
		for(int i=0;i<size;i++)
		{
			if(arr[i]=='(')
			{
				push(arr[i],count);
				size2++;
			}
			else if(arr[i]==')')
			{
				pop();
				size3++;
			}
		}
		for(int i=0;i<size;i++)
		{
			if(stack2[i]=='(' || stack2[i]==')')
			{
				return 0;
			}
		}
		if(size3 != size2)
		{
			return 0;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	for(int i=0;i<100;i++)
	{
		stack2[i]='\0';
	}
	char stack[100];
	int size;
	std::cout<<"Enter Size:";
	std::cin>>size;
	for(int i=0;i<size;i++)
	{
		std::cout<<"Enter Parenthesis:"<<std::endl;
		std::cin>>stack[i];
	}
	system("cls");
	for(int i=0;i<size;i++)
	{
		std::cout<<stack[i];
	}
	if(determine(stack,size)==0)
	{
		std::cout<<std::endl<<"Unbalance"<<std::endl;
	}
	else if(determine(stack,size)==1)
	{
		std::cout<<std::endl<<"Balanced"<<std::endl;
	}
}
