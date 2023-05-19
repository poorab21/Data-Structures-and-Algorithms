#include<iostream>
struct record{
	int data;
	record *next;
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
void append(int value)
{
	if(start==NULL)
	{
		start=new record;
		last=start;
		last->data=value;
	}
	else
	{
		last->next=new record;
		last=last->next;
		last->data=value;
	}
	last->next=NULL;
}
void Display()
{
	for(record *z=start;z != NULL;z=z->next)
	{
		std::cout<<z->data<<" ";
	}
	std::cout<<std::endl;
}
void Central_Node()
{
	int capacity;
	record *z=start;
	if(Size()%2==0)
	{
		capacity=(Size())/2;
		for(int i=1;i<capacity;i++)
		{
			z=z->next;
		}
		std::cout<<"Central Nodes Value = "<<z->data<<" and "<<z->next->data<<"\n";
	}
	else
	{
		capacity=(Size())/2;
		for(int i=1;i<=capacity;i++)
		{
			z=z->next;
		}
		std::cout<<"Central Node Value = "<<z->data<<"\n";
	}
}
int main()
{
	int choice,value;
	while(1)
	{
		std::cout<<"1.APPEND"<<std::endl;
		std::cout<<"2.DISPLAY"<<std::endl;
		std::cout<<"3.CENTRAL NODE"<<std::endl;
		std::cout<<"4.EXIT"<<std::endl;
		std::cout<<"Enter Option:";
		std::cin>>choice;
		if(choice==1)
		{
			system("cls");
			std::cout<<"Enter Value:";
			std::cin>>value;
			append(value);
		}
		else if(choice==2)
		{
			system("cls");
			Display();
		}
		else if(choice==3)
		{
			Central_Node();
		}
		else if(choice==4)
		{
			return 0;
		}
	}
}
