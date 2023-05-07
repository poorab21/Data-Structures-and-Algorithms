#include"linked_list.h"
linkedlist::linkedlist(){}
int linkedlist::Size()
{
	int count=0;
	for(linkedlist *z=start;z != NULL;z=z->next)
	{
		count++;
	}
	return count;
}
linkedlist::linkedlist(int value)
{
	this->data=value;
	this->next=NULL;
}
void linkedlist::InsertStart(int value)
{
	linkedlist *temp=new linkedlist(value);
	if(this->start==NULL)
	{
		this->start=temp;
	}
	else
	{
	temp->next=this->start;
	this->start=temp;	
	}
}
void linkedlist::InsertEnd(int value)
{
	linkedlist *z=start;
	linkedlist *temp=new linkedlist(value);
	if(this->start==NULL)
	{
		this->start=temp;
		this->start->next=NULL;
	}
	else
	{
		while(z->next != NULL)
		{
		z=z->next;
		}
		z->next=temp;
		temp->next=NULL;
	}
}
void linkedlist::InsertPosition(int value,int position)
{
	int capacity=this->Size();
	linkedlist *temp=new linkedlist(value);
	linkedlist *z=this->start;
	linkedlist *previous=NULL;
	if(position==1)
	{
		temp->next=this->start;
		this->start=temp;
	}
	else if(position>1 && position<=capacity)
	{
		for(int i=1;i<position;i++)
		{
			previous=z;
			z=z->next;
		}
		previous->next=temp;
		temp->next=z;
	}
	else if(position>capacity)
	{
		std::cout<<"No Position Found in List"<<std::endl;
	}
}
void linkedlist::Forward_Traversing()
{
	for(linkedlist *z=start;z != NULL;z=z->next)
	{
		std::cout<<z->data<<std::endl;
	}
	std::cout<<std::endl;
}
linkedlist::~linkedlist(){}
void linkedlist::DeleteFirst()
{
	if(this->start==NULL)
	{
		std::cout<<"List Empty"<<std::endl;
	}
	else
	{
		linkedlist *temp=this->start;
		this->start=this->start->next;
		delete temp;
	}
}
void linkedlist::DeleteLast()
{
	linkedlist *z=this->start;
	if(this->start==NULL)
	{
		std::cout<<"List Empty"<<std::endl;
	}
	else if(this->start->next==NULL)
	{
		this->start=NULL;
	}
	else
	{
		while(z->next->next != NULL)
		{
		z=z->next;
		}
		z->next=NULL;
	}
}
void linkedlist::DeletePosition(int position)
{
	linkedlist *z=this->start;
	linkedlist *previous;
	int count=Size();
	if(start==NULL)
	{
		std::cout<<"List is Empty"<<std::endl;
	}
	else if(position==1)
	{
		linkedlist *temp=this->start;
		this->start=this->start->next;
		delete temp;
	}
	else if(position>1 && position<=count)
	{
		for(int i=1;i<position;i++)
		{
			previous=z;
			z=z->next;
		}
		previous->next=z->next;
		delete z;
	}
	else if(position>1 && position>count)
	{
		std::cout<<"Position does not Exist"<<std::endl;
	}
}
void linkedlist::Search(int value)
{
	int count=0,position=1;
	for(linkedlist *z=this->start;z != NULL;z=z->next)
	{
		if(z->data==value)
		{
			std::cout<<"Node Found at Position "<<position<<std::endl;
			count=1;
		}
		position++;
	}
	if(count==0)
	{
		std::cout<<"Not Found in List"<<std::endl;
	}
}
void linkedlist::Reverse_Traversing()
{
	int count=1;
	linkedlist *z=this->start;
	while(z->next != NULL)
	{
		count++;
		z=z->next;
	}
	for(int i=0;i<count;i++)
	{
		z=this->start;
		for(int j=0;j<(count-i-1);j++)
		{
			z=z->next;
		}
		std::cout<<z->data<<std::endl;
	}
}
void linkedlist::DeleteNode(int value)
{
	linkedlist *z=start,*previous;
	while(z != NULL)
	{
		if(z->data==value && z==start)
		{
			this->start=start->next;
			linkedlist *temp=z;
			z=z->next;
			delete temp;
		}
		else if(z->data==value && z != start)
		{
			for(linkedlist *temp=start;temp != z;temp=temp->next)
			{
				previous=temp;
			}
			previous->next=z->next;
			linkedlist *temp=z;
			z=z->next;
			delete temp;
		}
		else if(z->data != value)
		{
			z=z->next;
		}
	}
}
