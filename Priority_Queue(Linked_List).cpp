#include<iostream>
struct record{
	int data;
	int priority;
	record *next;
}*start=NULL,*rear=NULL;
void input(record *z)
{
	std::cout<<"Enter Element Value:";
	std::cin>>z->data;
	std::cout<<"Enter Priority:";
	std::cin>>z->priority;
}
void Push()
{
	record *temp=new record;
	input(temp);
	if(start==NULL)
	{
		start=temp;
		temp->next=NULL;
	}
	else if(temp->priority<start->priority)
	{
		temp->next=start;
		start=temp;
	}
	else
	{
		record *z=start,*previous;
		while(1)
		{
			if(z->priority < temp->priority && z->next != NULL)
			{
				previous=z;
				z=z->next;
			}
			else if(z->priority < temp->priority && z->next==NULL)
			{
				z->next=temp;
				temp->next=NULL;
				break;
			}
			else if(z->priority > temp->priority)
			{
				previous->next=temp;
				temp->next=z;
				break;
			}
			else if(z->priority==temp->priority)
			{
				temp->next=z->next;
				z->next=temp;
				break;
			}
		}
	}
}
void Pop()
{
	if(start==NULL)
	{
		std::cout<<"Queue is Empty"<<std::endl;
	}
	else if(start->next==NULL)
	{
		start=NULL;
	}
	else
	{
		record *temp=start;
		start=start->next;
		temp->next=NULL;
		delete temp;
	}
}
void Peek()
{
	if(start==NULL)
	{
		std::cout<<"Queue is Empty"<<std::endl;
	}
	else
	{
		std::cout<<"Peek = "<<start->data<<std::endl;
	}
}
void Display()
{
	if(start==NULL)
	{
		std::cout<<"Queue is Empty"<<std::endl;
	}
	else
	{
		for(record *z=start;z != NULL;z=z->next)
		{
			std::cout<<z->data<<" ";
		}
		std::cout<<std::endl;
	}
}
int main()
{
	int choice;
	while(1)
	{
		std::cout<<"1.PUSH ELEMENT"<<std::endl;
		std::cout<<"2.POP ELEMENT"<<std::endl;
		std::cout<<"3.PEEK"<<std::endl;
		std::cout<<"4.DISPLAY"<<std::endl;
		std::cout<<"5.EXIT"<<std::endl;
		std::cout<<"Choose your Option:";
		std::cin>>choice;
		if(choice==1)
		{
			system("cls");
			Push();
		}
		else if(choice==2)
		{
			system("cls");
			Pop();
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
			return 0;
		}
	}
}
