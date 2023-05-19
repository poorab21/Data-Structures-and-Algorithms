#include"circular.h"
queue::queue()
{
	this->next=NULL;
	this->data=0;
}
queue::queue(int data)
{
	this->next=NULL;
	this->data=data;
}
queue::~queue(){}
void queue::Enqueue(int data)
{
	queue *temp=new queue(data);
	if(this->front==NULL)
	{
		this->front=temp;
		this->rear=temp;
		temp->next=this->front;
	}
	else
	{
		this->rear->next=temp;
		this->rear=this->rear->next;
		this->rear->next=this->front;
	}
}
void queue::Dequeue()
{
	if(this->front==NULL)
	{
		std::cout<<"Queue is Empty"<<std::endl;
	}
	else if(this->front==this->rear)
	{
		std::cout<<this->front->data<<" has been removed from Queue"<<std::endl;
		this->front=NULL,this->rear=NULL;
	}
	else
	{
		std::cout<<this->front->data<<" has been removed from Queue"<<std::endl;
		queue *temp=this->front;
		this->front=this->front->next;
		temp->next=NULL;
		this->rear->next=this->front;
		delete temp;
	}
}
void queue::Peek()
{
	if(this->front==NULL)
	{
		std::cout<<"Queue is Empty"<<std::endl;
	}
	else
	{
		std::cout<<"Front Value = "<<this->front->data<<std::endl;
	}
}
void queue::IsEmpty()
{
	if(this->front==NULL)
	{
		std::cout<<"Queue is Empty"<<std::endl;
	}
	else
	{
		std::cout<<"Queue is not Empty"<<std::endl;
	}
}
void queue::Display()
{
	queue *temp=this->front;
	if(this->front==NULL)
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
		while(temp != this->front);
		std::cout<<std::endl;
	}
}
