#include<iostream>
#define SIZE 100
int arr[SIZE],front=-1,rear=-1;
void Insert(int value)
{
	if(rear==SIZE-1)
	{
		std::cout<<"Queue is Full"<<std::endl;
	}
	else if(front==-1 && rear==-1)
	{
		front++,rear++;
		arr[rear]=value;
	}
	else
	{
		for(int i=0;i<=rear;i++)
		{
			if(value>=arr[i])
			{
				for(int j=rear+1;j>i;j--)
				{
					arr[j]=arr[j-1];
				}
				arr[i]=value;
				rear++;
				break;
			}
			else if(value<arr[i] && i==rear)
			{
				rear++;
				arr[rear]=value;
				break;
			}
		}
	}
}
void Delete(int data)
{
	if(front==-1 && rear==-1)
	{
		std::cout<<"Queue is Empty"<<std::endl;
	}
	else
	{
		for(int i=0;i<=rear;i++)
		{
			if(data==arr[i])
			{
				for(int j=i;j<=rear;j++)
				{
					arr[j]=arr[j+1];
				}
				rear--;
				break;
			}
			else if(data != arr[i] && i==rear)
			{
				std::cout<<"Element not in Queue"<<std::endl;
			}
		}
	}
	if(rear==-1)
	{
		front=-1;
	}
}
int HighestPriority()
{
	if(front==-1 && rear==-1)
	{
		std::cout<<"Queue is Empty"<<std::endl;
	}
	else
	{
		std::cout<<"Element of Highest Priority = "<<arr[front]<<std::endl;
	}
}
int LowestPriority()
{
	if(front==-1 && rear==-1)
	{
		std::cout<<"Queue is Empty"<<std::endl;
	}
	else
	{
		std::cout<<"Element of Lowest Priority = "<<arr[rear]<<std::endl;
	}
}
void Display()
{
	if(front==-1 && rear==-1)
	{
		std::cout<<"Queue is Empty"<<std::endl;
	}
	else
	{
		for(int i=0;i<=rear;i++)
		{
			std::cout<<arr[i]<<std::endl;
		}
	}
}
int main()
{
	int choice,size,value;
	while(1)
	{
		std::cout<<"1.INSERT ELEMENT"<<std::endl;
		std::cout<<"2.DELETE ELEMENT"<<std::endl;
		std::cout<<"3.ELEMENT OF HIGHEST PRIORITY"<<std::endl;
		std::cout<<"4.ELEMENT OF LOWEST PRIORITY"<<std::endl;
		std::cout<<"5.DISPLAY QUEUE"<<std::endl;
		std::cout<<"6.EXIT"<<std::endl;
		std::cout<<"ENTER OPTION:";
		std::cin>>choice;
		if(choice==1)
		{
			system("cls");
			std::cout<<"Enter Element to Insert:";
			std::cin>>value;
			Insert(value);
		}
		else if(choice==2)
		{
			system("cls");
			std::cout<<"Enter Element to Delete:";
			std::cin>>value;
			Delete(value);
		}
		else if(choice==3)
		{
			HighestPriority();
		}
		else if(choice==4)
		{
			LowestPriority();
		}
		else if(choice==5)
		{
			Display();
		}
		else if(choice==6)
		{
			return 0;
		}
	}
}
