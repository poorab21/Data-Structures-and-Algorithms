#include<iostream>
#include<stdlib.h>
struct record{
	int sno;
	std::string name;
	int age;
	record *next;
	record *prev;
}*start=NULL,*last=NULL;
void input(record *z)
{
	std::cout<<"Enter SNO:";
	std::cin>>z->sno;
	std::cin.ignore();
	std::cout<<"Enter Name:"<<std::endl;
	getline(std::cin,z->name);
	std::cout<<"Enter Age:"<<std::endl;
	std::cin>>z->age;
}
void append()
{
	if(start==NULL)
	{
		start=new record;
		last=start;
		last->prev=NULL;
	}
	else
	{
		last->next=new record;
		last->next->prev=last;
		last=last->next;
	}
	input(last);
	last->next=NULL;
}
void display()
{
	for(record *z=start;z != NULL;z=z->next)
	{
		std::cout<<"SNO = "<<z->sno<<std::endl;
		std::cout<<"Name = "<<z->name<<std::endl;
		std::cout<<"Age = "<<z->age<<std::endl;
		std::cout<<std::endl;
	}	
	std::cout<<std::endl;
}
record* Search(int value)
{
	for(record *z=start;z != NULL;z=z->next)
	{
		if(z->sno==value)
		{
			return z;
		}
	}
	return NULL;
}
void Delete(int value)
{
	record *temp=NULL;
	if(Search(value) != NULL)
	{
		for(record *z=start;z != NULL;z=z->next)
		{	
		if(z->sno==value && z==start)
		{
			start=start->next;
			free(z);
			break;
		}
		else if(z->sno==value && z==last)
		{
			temp->next=z->next;
			z->prev=NULL;
			last=temp;
			free(z);
			break;
		}
		else if(z->sno==value && z != last && z != start)
		{
			temp->next=z->next;
			z->next->prev=temp;
			free(z);
			break;
		}
		temp=z;
		}	
	}
	else
	{
		std::cout<<"Record Not Found"<<std::endl;
	}
}
void InsertAfter(int value)
{
	record *temp=new record;
	record *z=Search(value);
	if(z != NULL)
	{
		input(temp);
		temp->next=z->next;
		temp->prev=z;
		z->next=temp;
		if(z->sno==last->sno)
		{
		last=temp;
		}
	}
	else
	{
		std::cout<<"Record Not Found"<<std::endl;
	}
}
void InsertBefore(int value)
{
	record *temp=new record;
	record *z=Search(value);
	if(z != NULL && z != start)
	{
		input(temp);
		temp->next=z;
		temp->prev=z->prev;
		z->prev->next=temp;
		z->prev=temp;
	}
	else if(z != NULL && z==start)
	{
		input(temp);
		temp->next=start;
		temp->prev=NULL;
		start->prev=temp;
		start=temp;
	}
	else
	{
		std::cout<<"Record Not Found"<<std::endl;
	}
}
int main()
{
	int choice,value;
	while(1)
	{
		std::cout<<"1.OPEN NEW NODE"<<std::endl;
		std::cout<<"2.DISPLAY NODES"<<std::endl;
		std::cout<<"3.DELETE NODES"<<std::endl;
		std::cout<<"4.INSERT AFTER NODES"<<std::endl;
		std::cout<<"5.INSERT BEFORE NODES"<<std::endl;
		std::cout<<"6.EXIT"<<std::endl;
		std::cout<<"ENTER YOUR OPTION:"<<std::endl;
		std::cin>>choice;
		if(choice==1)
		{
			system("cls");
			append();
		}
		else if(choice==2)
		{
			system("cls");
			display();
		}
		else if(choice==3)
		{
			system("cls");
			std::cout<<"Enter Record Sno:";
			std::cin>>value;
			Delete(value);
		}
		else if(choice==4)
		{
			system("cls");
			std::cout<<"Enter Record Sno to insert after:";
			std::cin>>value;
			InsertAfter(value);
		}
		else if(choice==5)
		{
			system("cls");
			std::cout<<"Enter Record Sno to insert before:";
			std::cin>>value;
			InsertBefore(value);
		}
		else if(choice==6)
		{
			return 0;
		}
	}
}
