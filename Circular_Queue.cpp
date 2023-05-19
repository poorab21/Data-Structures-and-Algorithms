#include<iostream>
int arr[100],size,front=-1,rear=-1;
bool IsFull()
{
	if(rear==front-1 || (rear+1)%size==front)
	{
		return 1;
	}
		return 0;
}
bool IsEmpty()
{
	if(front==-1 && rear==-1)
	{
		return 1;
	}
	return 0;
}
void Peek()
{
	if(IsEmpty())
	{
		std::cout<<"Queue is Empty"<<std::endl;
	}
	else
	{
		std::cout<<"Front = "<<arr[front]<<std::endl;
	}
}
void Enqueue(int x)
{
	if(IsFull())
	{
		std::cout<<"Queue is Full"<<std::endl;
	}
	else if(front==-1 && rear==-1)
	{
		front=0,rear=0;
		arr[front]=x;
	}
	else if((rear+1)%size != front)
	{
		rear=((rear+1)%size);
		arr[rear]=x;
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
		std::cout<<arr[front]<<" has been removed from queue"<<std::endl;
		arr[front]=0;
		front=-1,rear=-1;
	}
	else
	{
		std::cout<<arr[front]<<" has been removed from queue"<<std::endl;
		arr[front]=0;
		front=(front+1)%size;
	}
}
void Display()
{
	for(int i=0;i<size;i++)
	{
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}
int main()
{
	int choice,value;
	std::cout<<"Enter Size:";
	std::cin>>size;
	for(int i=0;i<size;i++)
	{
		arr[i]=0;
	}
	while(1)
	{
		std::cout<<"1.ENQUEUE"<<std::endl;
		std::cout<<"2.DEQUEUE"<<std::endl;
		std::cout<<"3.PEEK"<<std::endl;
		std::cout<<"4.IS QUEUE FULL"<<std::endl;
		std::cout<<"5.IS QUEUE EMPTY"<<std::endl;
		std::cout<<"6.DISPLAY"<<std::endl;
		std::cout<<"7.EXIT"<<std::endl;
		std::cout<<"Enter your option:";
		std::cin>>choice;
		if(choice==1)
		{
			system("cls");
			std::cout<<"Enter Value to Enqueue:";
			std::cin>>value;
			Enqueue(value);
		}
		else if(choice==2)
		{
			Dequeue();
		}
		else if(choice==3)
		{
			system("cls");
			Peek();
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
				std::cout<<"Queue is not full"<<std::endl;
			}
		}
		else if(choice==5)
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
