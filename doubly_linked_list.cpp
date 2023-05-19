#include"doubly_linked_list.h"
doubly::doubly()
{
	this->value=0;
}
doubly::doubly(const int value)
{
	this->value=value;
	this->next=NULL;
	this->prev=NULL;
}
doubly::~doubly(){}
int doubly::Size()
{
	int count=0;
	for(doubly *z=start;z != NULL;z=z->next)
	{
		count++;
	}
	return count;
}
void doubly::InsertBefore(const int value)
{
	doubly *temp=new doubly(value);
	if(this->start==NULL)
	{
		this->start=temp;
		this->last=temp;
	}
	else
	{
		temp->next=this->start;
		this->start->prev=temp;
		this->start=temp;
	}
}
void doubly::InsertAfter(const int value)
{
	doubly *temp=new doubly(value);
	if(this->start==NULL)
	{
		this->start=temp;
		this->last=this->start;
	}
	else
	{
		this->last->next=temp;
		temp->prev=this->last;
		this->last=temp;
	}
}
void doubly::InsertPosition(const int value,const int position)
{
	doubly *z=new doubly(value);
	doubly *temp=this->start;
	if(position==1 && this->start==NULL)
	{
		this->start=z;
		this->last=z;
	}
	else if(position==1 && this->start != NULL)
	{
		z->next=this->start;
		this->start->prev=z;
		this->start=z;
	}
	else if(position>1 && position<=this->Size())
	{
		doubly *temp=this->start;
		for(int i=1;i<position;i++)
		{
		temp=temp->next;
		}
		temp->prev->next=z;
		z->prev=temp->prev;
		z->next=temp;
		temp->prev=z;
	}
	else if(position>this->Size())
	{
		std::cout<<"Position Exceeds Number of Records"<<std::endl;
	}
}
void doubly::Forward_Traversing()
{
	for(doubly *z=start;z != NULL;z=z->next)
	{
		std::cout<<z->value<<std::endl;
	}
	std::cout<<std::endl;
}
void doubly::Reverse_Traversing()
{
	for(doubly *z=last;z != NULL;z=z->prev)
	{
		std::cout<<z->value<<std::endl;
	}
}
void doubly::DeleteFirst()
{
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
		doubly *z=this->start;
		this->start=this->start->next;
		this->start->prev=NULL;
		delete z;
	}
}
void doubly::DeleteLast()
{
	if(this->start==NULL)
	{
		std::cout<<"List Empty"<<std::endl;
	}
	else if(this->last==this->start && this->start->next==NULL)
	{
		this->start=NULL;
		this->last=NULL;
	}
	else if(this->last != this->start)
	{
		doubly *temp=this->last;
		this->last=this->last->prev;
		this->last->next=NULL;
		temp->prev=NULL;
		delete temp;
	}
}
void doubly::DeletePosition(int position)
{
	if(this->start==NULL)
	{
		std::cout<<"List Empty"<<std::endl;
	}
	else if(position==1 && this->start->next==NULL)
	{
		this->start=NULL;
	}
	else if(position==1 && this->start->next != NULL)
	{
		doubly *temp=this->start;
		this->start=this->start->next;
		this->start->prev=NULL;
		temp->next=NULL;
		delete temp;
	}
	else if(position==this->Size())
	{
		doubly *temp=this->last;
		this->last=this->last->prev;
		this->last->next=NULL;
		temp->prev=NULL;
		delete temp;
	}
	else if(position>1 && position<this->Size())
	{
		doubly *temp=this->start;
		for(int i=1;i<position;i++)
		{
			temp=temp->next;
		}
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		delete temp;
	}
	else if(position>this->Size())
	{
		std::cout<<"Position does not Exist"<<std::endl;
	}
}
void doubly::DeleteNode(const int value)
{
	doubly *z=this->start;
	if(this->start==NULL)
	{
		std::cout<<"List Empty"<<std::endl;
	}
	while(z != NULL)
	{
		if(z==this->start && z->value==value && this->start->next != NULL)
		{
			doubly *temp=z;
			this->start=this->start->next;
			this->start->prev=NULL;
			z=z->next;
			temp->next=NULL;
			delete temp;
		}
		else if(z==this->start && z->value==value && this->start->next==NULL)
		{
			this->start=NULL;
			z=z->next;
		}
		else if(z->value==value && z==this->last)
		{
			doubly *temp=this->last;
			this->last=this->last->prev;
			this->last->next=NULL;
			temp->prev=NULL;
			z=z->next;
			delete temp;
		}
		else if(z->value==value && z->next != NULL)
		{
			z->prev->next=z->next;
			z->next->prev=z->prev;
			doubly *temp=z;
			z=z->next;
			temp->next=NULL;
			temp->prev=NULL;
			delete temp;
		}
		else if(z->value != value)
		{
			z=z->next;
		}
	}
}
void doubly::Merge(doubly l)
{
	this->last->next=l.start;
	l.start->prev=this->last;
	this->last=l.last;
}
void doubly::CommonElements(doubly l1)
{
	int count=0,arr[10],count2=0,determine=0;
	for(doubly *z=this->start;z != NULL;z=z->next)
	{
		count=0,determine=0;
		for(doubly *temp=l1.start;temp != NULL;temp=temp->next)
		{
			if(z->value==temp->value)
			{
				for(doubly *sub=this->start;sub != z;sub=sub->next)
				{
					if(sub->value==z->value)
					{
						determine=1;
						break;
					}
				}
				if(determine==0)
				{
					count++;
				}
			}
			else
			{
				continue;
			}
		}
		if(count>0)
		{
			arr[count2]=z->value;
			count2++;
		}
	}
	if(count2==0)
	{
		std::cout<<"No Common numbers Found in both Lists"<<std::endl;
	}
	else if(count2>0)
	{
		std::cout<<"Following are common numbers from both lists"<<std::endl;
		for(int i=0;i<count2;i++)
		{
			std::cout<<arr[i]<<std::endl;
		}
	}
}
