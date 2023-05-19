#include<iostream>
#include<math.h>
char Tree[50];
void Insert_Root(char x)
{
	if(Tree[0]=='\0')
	{
		Tree[0]=x;
	}
	else
	{
		std::cout<<"Tree already has root"<<std::endl;
	}
}
void Left_Child(char parent)
{
	char value;
	int index;
	for(int i=0;i<50;i++)
	{
		if(Tree[i]==parent)
		{
			index=(i*2)+1;
			if(Tree[index]=='\0')
			{
				std::cout<<"Enter Value for Left Child:";
				std::cin>>value;
				Tree[index]=value;
			}
			else
			{
				std::cout<<"Left Child is already filled"<<std::endl;
			}
			break;
		}
		else if(i==49 && Tree[i] != parent)
		{
			std::cout<<"Parent Tree does not Exist"<<std::endl;
		}
	}
}
void Right_Child(char parent)
{
	char value;
	int index;
	for(int i=0;i<50;i++)
	{
		if(Tree[i]==parent)
		{
			index=(i*2)+2;
			if(Tree[index]=='\0')
			{
				std::cout<<"Enter Value for Right Child:";
				std::cin>>value;
				Tree[index]=value;
			}
			else
			{
				std::cout<<"Right Child already Filled"<<std::endl;
			}
			break;
		}
		else if(i==49 && Tree[i] != parent)
		{
			std::cout<<"Parent Tree does not Exist"<<std::endl;
		}
	}
}
void Display()
{
	for(int i=0;i<50;i++)
	{
		if(Tree[i]=='\0')
		{
			std::cout<<"_";
		}
		else
		{
			std::cout<<Tree[i];
		}
	}
	std::cout<<std::endl;
}
int main()
{
	int choice;
	char value,parent;
	while(1)
	{
		std::cout<<"1.INSERT ROOT"<<std::endl;
		std::cout<<"2.INSERT LEFT CHILD"<<std::endl;
		std::cout<<"3.INSERT RIGHT CHILD"<<std::endl;
		std::cout<<"4.DISPLAY"<<std::endl;
		std::cout<<"5.EXIT"<<std::endl;
		std::cout<<"CHOOSE YOUR OPTION:";
		std::cin>>choice;
		if(choice==1)
		{
			std::cout<<"Enter Value for Root:";
			std::cin>>value;
			system("cls");
			Insert_Root(value);
		}
		else if(choice==2)
		{
			std::cout<<"Enter Parent of left child:";
			std::cin>>parent;
			//system("cls");
			Left_Child(parent);
		}
		else if(choice==3)
		{
			std::cout<<"Enter Parent of Right Child:";
			std::cin>>parent;
			system("cls");
			Right_Child(parent);
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
