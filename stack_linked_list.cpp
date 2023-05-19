#include"stack_linked_list.h"
stack::stack()
{
	this->data=0;
	this->start=NULL;
	this->next=NULL;
}
stack::~stack(){}
stack::stack(int data)
{
	this->data=data;
	this->next=NULL;
}
void stack::Push(int value)
{
	if(this->start==NULL)
	{
		this->start=new stack(value);
	}
	else
	{
		stack *temp=new stack(value);
		temp->next=this->start;
		this->start=temp;
	}
}
void stack::Pop()
{
	if(this->start==NULL)
	{
		std::cout<<"Underflow Error"<<std::endl;
	}
	else
	{
		stack *temp=this->start;
		this->start=this->start->next;
		delete temp;
	}
}
void stack::IsEmpty()
{
	if(this->start==NULL)
	{
		std::cout<<"Stack is Empty"<<std::endl;
	}
	else
	{
		std::cout<<"Stack is not Empty"<<std::endl;
	}
}
int stack::Peek()
{
	return this->start->data;
}
void stack::Display()
{
	for(stack *z=start;z != NULL;z=z->next)
	{
		std::cout<<z->data<<" ";
	}
	std::cout<<std::endl;
}
