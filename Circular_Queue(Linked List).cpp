#include<iostream>
struct queue{
	int data;
	queue *next;
}*front=NULL,*rear;
void Enqueue(int data)
{
	queue *temp=new queue;
	temp->data=data;
	if(front==NULL)
	{
		front=temp;
		rear=temp;
		temp->next=front;
	}
	else
	{
		rear->next=temp;
		rear=rear->next;
		rear->next=front;
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
		std::cout<<front->data<<" has been removed from Queue"<<std::endl;
		front=NULL,rear=NULL;
	}
	else
	{
		std::cout<<front->data<<" has been removed from Queue"<<std::endl;
		queue *temp=front;
		front=front->next;
		temp->next=NULL;
		rear->next=front;
		delete temp;
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
void Display()
{
	queue *temp=front;
	if(front==NULL)
	{
		std::cout<<"Queue is Empty"<<std::endl;
	}
	else
	{
		do
		{
			std::cout<<temp->data<<" ";
			temp=temp->next;
		}	
		while(temp != front);
		std::cout<<std::endl;
	}
}
int main()
{
	int choice,value;
	while(1)
	{
		std::cout<<"1.ENQUEUE"<<std::endl;
		std::cout<<"2.DEQUEUE"<<std::endl;
		std::cout<<"3.DISPLAY"<<std::endl;
		std::cout<<"4.PEEK"<<std::endl;
		std::cout<<"5.IS QUEUE EMPTY"<<std::endl;
		std::cout<<"6.EXIT"<<std::endl;
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
			Display();
		}
		else if(choice==4)
		{
			system("cls");
			Peek();
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
