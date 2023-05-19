#include<iostream>
struct queue{
	int data;
	queue *next;
}*front=NULL,*rear=NULL;
void Enqueue(int data)
{
	if(front==NULL)
	{
		front=new queue;
		rear=front;
		rear->data=data;
		rear->next=NULL;
	}
	else
	{
		rear->next=new queue;
		rear=rear->next;
		rear->data=data;
		rear->next=NULL;
	}
}
void Dequeue()
{
	if(front==NULL)
	{
		std::cout<<"Queue is Empty"<<std::endl;
	}
	else if(front==rear)
	{
		front=NULL;
		rear=NULL;
	}
	else
	{
		queue *temp=front;
		front=front->next;
		delete temp;
	}
}
void IsEmpty()
{
	if(front==NULL)
	{
		std::cout<<"Queue is Empty"<<std::endl;
	}
	else
	{
		std::cout<<"Queue is not Empty"<<std::endl;
	}
}
void Peek()
{
	if(front==NULL)
	{
		std::cout<<"Queue is Empty"<<std::endl;
	}
	else
	{
		std::cout<<"Front Value = "<<front->data<<std::endl;
	}
}
void Display()
{
	for(queue *z=front;z != NULL;z=z->next)
	{
		std::cout<<z->data<<" ";
	}
	std::cout<<std::endl;
}
int main()
{
	int choice,value;
	while(1)
	{
		std::cout<<"1.ENQUEUE"<<std::endl;
		std::cout<<"2.DEQUEUE"<<std::endl;
		std::cout<<"3.PEEK"<<std::endl;
		std::cout<<"4.DISPLAY"<<std::endl;
		std::cout<<"5.IS QUEUE EMPTY"<<std::endl;
		std::cout<<"6.EXIT"<<std::endl;
		std::cout<<"ENTER YOUR OPTION:";
		std::cin>>choice;
		if(choice==1)
		{
			system("cls");
			std::cout<<"Enter Value:";
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
			Peek();
		}
		else if(choice==4)
		{
			system("cls");
			Display();
		}
		else if(choice==5)
		{
			system("cls");
			IsEmpty();
		}
		else if(choice==6)
		{
			return 0;
		}
	}
}
