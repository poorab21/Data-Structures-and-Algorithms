#include<iostream>
struct record{
	int sno;
	std::string name;
	record *next;
}*start=NULL,*last=NULL;
int size()
{
	int count=0;
	record *temp=start;
	do
	{
		temp=temp->next;
		count++;
	}
	while(temp != start);
	return count;
}
void input(record *z)
{
	std::cout<<"Enter Sno:";
	std::cin>>z->sno;
	std::cin.ignore();
	std::cout<<"Enter Name:";
	std::cin>>z->name;
}
void InsertFirst()
{
	if(start==NULL)
	{
		start=new record;
		input(start);
		last=start;
		last->next=start;
	}
	else
	{
		record *temp=new record;
		input(temp);
		temp->next=start;
		start=temp;
		last->next=start;
	}
}
void InsertLast()
{
	if(start==NULL)
	{
		start=new record;
		input(start);
		last=start;
		last->next=start;
	}
	else
	{
		record *temp=new record;
		input(temp);
		last->next=temp;
		last=temp;
		last->next=start;
	}
}
void InsertNode(int position)
{
	if(position==1 && start==NULL)
	{
		start=new record;
		input(start);
		last=start;
		last->next=start;
	}
	else if(position==1 && start != NULL)
	{
		record *temp=new record;
		input(temp);
		temp->next=start;
		start=temp;
		last->next=temp;
	}
	else if(position>1 && position<=size())
	{
		record *temp=start;
		for(int i=1;i<position-1;i++)
		{
			temp=temp->next;
		}
		record *z=new record;
		input(z);
		z->next=temp->next;
		temp->next=z;
	}
	else if(position>size())
	{
		std::cout<<"Position does not exist"<<std::endl;
	}
}
void DeleteFirst()
{
	if(start==NULL)
	{
		std::cout<<"List Empty"<<std::endl;
	}
	else if(start != NULL && start->next==start)
	{
		start=NULL;
		last=NULL;
	}
	else if(start != NULL && start->next != start)
	{
		record *z=start;
		start=start->next;
		last->next=start;
		delete z;
	}
}
void DeleteLast()
{
	if(start==NULL)
	{
		std::cout<<"List Empty"<<std::endl;
	}
	else if(start != NULL && start->next==start)
	{
		start=NULL;
		last=NULL;
	}
	else
	{
		record *temp=start;
		while(temp->next->next != start)
		{
			temp=temp->next;
		}
		record *z=last;
		last=temp;
		last->next=start;
		delete z;
	}
}
void DeletePosition(int position)
{
	if(start==NULL)
	{
		std::cout<<"List Empty"<<std::endl;
	}
	else if(start != NULL && start->next==start && position==1)
	{
		start=NULL;
		last=NULL;
	}
	else if(position==1 && position<size())
	{
		record *temp=start;
		start=start->next;
		last->next=start;
		delete temp;
	}
	else if(position>1 && position<size())
	{
		record *temp=start;
		for(int i=1;i<position-1;i++)
		{
			temp=temp->next;
		}
		record *z=temp->next;
		temp->next=temp->next->next;
		z->next=NULL;
		delete z;
	}
	else if(position==size())
	{
		record *temp=start;
		while(temp->next->next != start)
		{
			temp=temp->next;
		}
		record *z=last;
		last=temp;
		last->next=start;
		delete z;
	}
	else if(position>size())
	{
		std::cout<<"Position does not Exist"<<std::endl;
	}
}
void Forward_Traversing()
{
	if(start==NULL)
	{
		std::cout<<"No Elements in List"<<std::endl;
	}
	else
	{
	record *temp=start;
	do
	{
		std::cout<<"Sno = "<<temp->sno<<std::endl;
		std::cout<<"Name = "<<temp->name<<std::endl;
		std::cout<<std::endl;
		temp=temp->next;
	}
	while(temp != start);
	}
}
void Reverse_Traversing()
{
	record *z=last;
	while(z != start)
	{
		record *temp=start,*previous;
		while(temp != z)
		{
			previous=temp;
			temp=temp->next;
		}
		std::cout<<"Sno = "<<temp->sno<<std::endl;
		std::cout<<"Name = "<<temp->name<<std::endl;
		std::cout<<std::endl;
		z=previous;
	}
	if(z==start)
	{
		std::cout<<"Sno = "<<z->sno<<std::endl;
		std::cout<<"Name = "<<z->name<<std::endl;
		std::cout<<std::endl;
	}
}
int main()
{
	int choice,position,value;
	while(1)
	{
		std::cout<<"1.INSERT FIRST"<<std::endl;
		std::cout<<"2.INSERT LAST"<<std::endl;
		std::cout<<"3.INSERT NODE"<<std::endl;
		std::cout<<"4.FORWARD TRAVERSING"<<std::endl;
		std::cout<<"5.DELETE FIRST"<<std::endl;
		std::cout<<"6.DELETE LAST"<<std::endl;
		std::cout<<"7.DELETE POSITION"<<std::endl;
		std::cout<<"8.REVERSE TRAVERSING"<<std::endl;
		std::cout<<"9.EXIT"<<std::endl;
		std::cout<<"CHOOSE YOUR OPTION:";
		std::cin>>choice;
		if(choice==1)
		{
			system("cls");
			InsertFirst();
		}
		else if(choice==2)
		{
			system("cls");
			InsertLast();
		}
		else if(choice==3)
		{
			system("cls");
			std::cout<<"Enter Position:";
			std::cin>>position;
			InsertNode(position); 
		}
		else if(choice==4)
		{
			system("cls");
			Forward_Traversing();
		}
		else if(choice==5)
		{
			DeleteFirst();
		}
		else if(choice==6)
		{
			DeleteLast();
		}
		else if(choice==7)
		{
			std::cout<<"Enter Position:";
			std::cin>>position;
			DeletePosition(position);
		}
		else if(choice==8)
		{
			system("cls");
			Reverse_Traversing();
		}
		else if(choice==9)
		{
			return 0;
		}
	}
}
