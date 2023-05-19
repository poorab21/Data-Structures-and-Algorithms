#include<iostream>
struct stack{
	int sno;
	std::string name;
	stack *next;
}*start=NULL;
void info(stack *z)
{
	std::cout<<"Enter Sno:"<<std::endl;
	std::cin>>z->sno;
	std::cin.ignore();
	std::cout<<"Enter Name:"<<std::endl;
	getline(std::cin,z->name);
}
void append()
{
	if(start==NULL)
	{
		start=new stack;
		info(start);
		start->next=NULL;
	}
	else
	{
		stack *z=new stack;
		z->next=start;
		info(z);
		start=z;
	}
}
void Delete()
{
	if(start==NULL)
	{
		std::cout<<"Stack Underflow"<<std::endl;
	}
	else
	{
	stack *temp=start;
	start=start->next;
	delete temp;
	}
}
void display()
{
	for(stack *temp=start;temp != NULL;temp=temp->next)
	{
		std::cout<<"SNO = "<<temp->sno<<std::endl;
		std::cout<<"Name = "<<temp->name<<std::endl;
		std::cout<<std::endl;
	}
}
int main()
{
	int choice;
	while(1)
	{
		std::cout<<"1.APPEND"<<std::endl;
		std::cout<<"2.DISPLAY"<<std::endl;
		std::cout<<"3.DELETE"<<std::endl;
		std::cout<<"4.EXIT"<<std::endl;
		std::cout<<"ENTER YOUR CHOICE:";
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
			Delete();
		}
		else if(choice==4)
		{
			return 0;
		}
	}
}
