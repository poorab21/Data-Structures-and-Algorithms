#include<iostream>
int front=-1,rear=-1,queue[100],size;
bool IsEmpty()
{
	if(front==-1 && rear==-1)
	{
		return true;
	}
	return false;
}
bool IsFull()
{
	if(rear==size-1)
	{
		return true;
	}
	return false;
}
void Enqueue(int x)
{
	if(IsEmpty())
	{
		front++;
		rear++;
		queue[rear]=x;
	}
	else if(IsFull())
	{
		std::cout<<"Queue is Full"<<std::endl;
	}
	else
	{
		rear++;
		queue[rear]=x;
	}
}
void Dequeue()
{
	if(IsEmpty())
	{
		std::cout<<"Queue is Empty"<<std::endl;
	}
	else if(front==rear)
	{
		std::cout<<queue[front]<<" has been removed from Queue"<<std::endl;
		front=-1,rear=-1;
	}
	else
	{
		std::cout<<queue[front]<<" has been removed from Queue"<<std::endl;
		front++;
	}
}
void Peek()
{
	if(front==-1 && rear==-1)
	{
		std::cout<<"Queue is Empty"<<std::endl;
	}
	else
	{
		std::cout<<"Front Value = "<<queue[front]<<std::endl;
	}
}
void Display()
{
	if(front<=rear && front != -1 && rear != -1)
	{
		for(int i=rear;i>=front;i--)
		{
			std::cout<<queue[i]<<" ";
		}
		std::cout<<std::endl;
	}
	else
	{
		std::cout<<"Queue is Empty"<<std::endl;
	}
}
int main()
{
	int choice,value;
	std::cout<<"Enter Size:";
	std::cin>>size;
	while(1)
	{
		std::cout<<"1.ENQUEUE"<<std::endl;
		std::cout<<"2.DEQUEUE"<<std::endl;
		std::cout<<"3.IS QUEUE EMPTY?"<<std::endl;
		std::cout<<"4.IS QUEUE FULL?"<<std::endl;
		std::cout<<"5.PEEK"<<std::endl;
		std::cout<<"6.DISPLAY"<<std::endl;
		std::cout<<"7.EXIT"<<std::endl;
		std::cout<<"ENTER YOUR OPTION:";
		std::cin>>choice;
		if(choice==1)
		{
			system("cls");
			std::cout<<"Enter Value to Insert in queue:";
			std::cin>>value;
			Enqueue(value);
		}
		else if(choice==2)
		{
			system("cls");
			Dequeue();
		}
		else if(choice==3)
		{
			system("cls");
			if(IsEmpty())
			{
				std::cout<<"Queue is Empty"<<std::endl;
			}
			else
			{
				std::cout<<"Queue is not Empty"<<std::endl;
			}
		}
		else if(choice==4)
		{
			system("cls");
			if(IsFull())
			{
				std::cout<<"Queue is Full"<<std::endl;
			}
			else
			{
				std::cout<<"Queue is not Full"<<std::endl;
			}
		}
		else if(choice==5)
		{
			system("cls");
			Peek();
		}
		else if(choice==6)
		{
			system("cls");
			Display();
		}
		else if(choice==7)
		{
			return 0;
		}
	}
}
