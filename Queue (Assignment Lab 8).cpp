#include"Queue.h"
queue::queue()
{
	this->next=NULL;
}
queue::queue(int data)
{
	this->data=data;
	this->next=NULL;
}
queue::~queue(){}
void queue::Enqueue(int data)
{
	queue *temp=new queue(data);
	if(this->front==NULL)
	{
		this->front=temp;
		this->rear=temp;
	}
	else
	{
		this->rear->next=temp;
		this->rear=temp;
	}
}
void queue::Dequeue()
{
	if(this->front==NULL)
	{
		std::cout<<"List is Empty"<<std::endl;
	}
	else if(this->front==this->rear)
	{
		this->front=NULL;
		this->rear=NULL;
	}
	else
	{
		queue *temp=this->front;
		this->front=this->front->next;
		delete temp;
	}
}
void queue::Display()
{
	for(queue *z=front;z != NULL;z=z->next)
	{
		std::cout<<z->data<<" ";
	}
	std::cout<<std::endl;
}
void queue::Peek()
{
	if(this->front==NULL)
	{
		std::cout<<"List is Empty"<<std::endl;
	}
	else
	{
		std::cout<<"Front Value = "<<front->data<<std::endl;
	}
}
void queue::IsEmpty()
{
	if(this->front==NULL)
	{
		std::cout<<"List is Empty"<<std::endl;
	}
	else
	{
		std::cout<<"List is not Empty"<<std::endl;
	}
}









