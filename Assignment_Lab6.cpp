#include<iostream>
struct record{
	int sno;
	record *next;
	record *prev;
}*start=NULL,*last=NULL;
int Size()
{
	int count=0;
	for(record *z=start;z != NULL;z=z->next)
	{
		count++;
	}
	return count;
}
void input(record *z)
{
	std::cout<<"Enter SNO:";
	std::cin>>z->sno;
}
void InsertBefore()
{
	record *temp=new record;
	input(temp);
	if(start==NULL)
	{
		start=temp;
		last=temp;
		start->next=NULL;
		start->prev=NULL;
	}
	else
	{
		temp->next=start;
		start->prev=temp;
		temp->prev=NULL;
		start=temp;
	}
}
void InsertAfter()
{
	record *temp=new record;
	input(temp);
	if(start==NULL)
	{
		start=temp;
		last=start;
		start->next=NULL;
		start->prev=NULL;
	}
	else
	{
		last->next=temp;
		temp->prev=last;
		last=temp;
		temp->next=NULL;
	}
}
void InsertPosition(int position)
{
	record *z=new record;
	input(z);
	record *temp=start;
	if(position==1 && start==NULL)
	{
		start=z;
		last=z;
		z->next=NULL;
		z->prev=NULL;
	}
	else if(position==1 && start != NULL)
	{
		z->next=start;
		start->prev=z;
		start=z;
		start->prev=NULL;
	}
	else if(position>1 && position<=Size())
	{
		record *temp=start;
		for(int i=1;i<position;i++)
		{
		temp=temp->next;
		}
		temp->prev->next=z;
		z->prev=temp->prev;
		z->next=temp;
		temp->prev=z;
	}
	else if(position>Size())
	{
		std::cout<<"Position Exceeds Number of Records"<<std::endl;
	}
}
void Forward_Traversing()
{
	for(record *z=start;z != NULL;z=z->next)
	{
		std::cout<<z->sno<<std::endl;
	}
	std::cout<<std::endl;
}
void Reverse_Traversing()
{
	for(record *z=last;z != NULL;z=z->prev)
	{
		std::cout<<z->sno<<std::endl;
	}
}
void DeleteFirst()
{
	if(start==NULL)
	{
		std::cout<<"List Empty"<<std::endl;
	}
	else if(start->next==NULL)
	{
		start=NULL;
	}
	else
	{
		record *z=start;
		start=start->next;
		start->prev=NULL;
		delete z;
	}
}
void DeleteLast()
{
	if(start==NULL)
	{
		std::cout<<"List Empty"<<std::endl;
	}
	else if(last==start && start->next==NULL)
	{
		start=NULL;
		last=NULL;
	}
	else if(last != start)
	{
		record *temp=last;
		last=last->prev;
		last->next=NULL;
		temp->prev=NULL;
		delete temp;
	}
}
void DeletePosition(int position)
{
	if(start==NULL)
	{
		std::cout<<"List Empty"<<std::endl;
	}
	else if(position==1 && start->next==NULL)
	{
		start=NULL;
	}
	else if(position==1 && start->next != NULL)
	{
		record *temp=start;
		start=start->next;
		start->prev=NULL;
		temp->next=NULL;
		delete temp;
	}
	else if(position==Size())
	{
		record *temp=last;
		last=last->prev;
		last->next=NULL;
		temp->prev=NULL;
		delete temp;
	}
	else if(position>1 && position<Size())
	{
		record *temp=start;
		for(int i=1;i<position;i++)
		{
			temp=temp->next;
		}
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		delete temp;
	}
	else if(position>Size())
	{
		std::cout<<"Position does not Exist"<<std::endl;
	}
}
void DeleteNode(int value)
{
	record *z=start;
	if(start==NULL)
	{
		std::cout<<"List Empty"<<std::endl;
	}
	while(z != NULL)
	{
		if(z==start && z->sno==value && start->next != NULL)
		{
			record *temp=z;
			start=start->next;
			start->prev=NULL;
			z=z->next;
			temp->next=NULL;
			delete temp;
		}
		else if(z==start && z->sno==value && start->next==NULL)
		{
			start=NULL;
			z=z->next;
		}
		else if(z->sno==value && z==last)
		{
			record *temp=last;
			last=last->prev;
			last->next=NULL;
			temp->prev=NULL;
			z=z->next;
			delete temp;
		}
		else if(z->sno==value && z->next != NULL)
		{
			z->prev->next=z->next;
			z->next->prev=z->prev;
			record *temp=z;
			z=z->next;
			temp->next=NULL;
			temp->prev=NULL;
			delete temp;
		}
		else if(z->sno != value)
		{
			z=z->next;
		}
	}
}
int main()
{
	int choice,position,value;
	while(1)
	{
		std::cout<<"1.INSERT BEFORE"<<std::endl;
		std::cout<<"2.INSERT AFTER"<<std::endl;
		std::cout<<"3.INSERT AT POSITION"<<std::endl;
		std::cout<<"4.FORWARD TRAVERSING"<<std::endl;
		std::cout<<"5.REVERSE TRAVERSING"<<std::endl;
		std::cout<<"6.DELETE FIRST"<<std::endl;
		std::cout<<"7.DELETE LAST"<<std::endl;
		std::cout<<"8.DELETE POSITION"<<std::endl;
		std::cout<<"9.DELETE NODES"<<std::endl;
		std::cout<<"10.EXIT"<<std::endl;
		std::cout<<"ENTER YOUR OPTION:";
		std::cin>>choice;
		if(choice==1)
		{
			InsertBefore();
			system("cls");
		}
		else if(choice==2)
		{
			InsertAfter();
			system("cls");
		}
		else if(choice==3)
		{
			std::cout<<"Enter Position:";
			std::cin>>position;
			InsertPosition(position);
		}
		else if(choice==4)
		{
			system("cls");
			Forward_Traversing();
		}
		else if(choice==5)
		{
			system("cls");
			Reverse_Traversing();
		}
		else if(choice==6)
		{
			DeleteFirst();
		}
		else if(choice==7)
		{
			DeleteLast();
		}
		else if(choice==8)
		{
			std::cout<<"Enter Position:";
			std::cin>>position;
			DeletePosition(position);
		}
		else if(choice==9)
		{
			std::cout<<"Enter Value:";
			std::cin>>value;
			DeleteNode(value);
		}
		else if(choice==10)
		{
			return 0;
		}
	}
}
