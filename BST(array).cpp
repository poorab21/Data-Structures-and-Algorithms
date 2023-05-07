#include<iostream>
int arr[50];
int root=0;
void Insert(int data)
{
	if(arr[root]=='\0')
	{
		arr[root]=data;
	}
	else
	{
		int root=0,i=0;
		while(arr[i] != '\0')
		{
			if(data<arr[i])
			{
				i=(i*2)+1;
			}
			else if(data>arr[i])
			{
				i=(i*2)+2;
			}
			else if(data==arr[i])
			{
				std::cout<<"Error!Value already in Tree"<<std::endl;
			}
		}
		arr[i]=data;
	}
}
void LevelOrder()
{
	for(int i=0;i<20;i++)
	{
		if(arr[i]=='\0')
		{
			continue;
		}
		else
		{
			std::cout<<arr[i]<<" ";
		}
	}
	std::cout<<std::endl;
}
void Search(int value)
{
	if(arr[root]=='\0')
	{
		std::cout<<"Tree is Empty"<<std::endl;
	}
	else
	{
		int i=0;
		while(arr[i] != '\0')
		{
			if(value>arr[i])
			{
				i=(i*2)+2;
			}
			else if(value<arr[i])
			{
				i=(i*2)+1;
			}
			else if(value==arr[i])
			{
				std::cout<<"Value found at "<<i<<" Index"<<std::endl;
				break;
			}
		}
		if(arr[i]=='\0')
		{
			std::cout<<"Value not found in Tree"<<std::endl;
		}
	}
}
void ParentNode(int value)
{
	if(arr[root]=='\0')
	{
		std::cout<<"Tree is Empty"<<std::endl;
	}
	else
	{
		int i=0,previous=0;
		while(arr[i] != '\0')
		{
			if(value<arr[i])
			{
				previous=i;
				i=(i*2)+1;
			}
			else if(value>arr[i])
			{
				previous=i;
				i=(i*2)+2;
			}
			else if(value==arr[i])
			{
				break;
			}
		}
		if(arr[i]=='\0')
		{
			std::cout<<"Node does not Exist"<<std::endl;
		}
		else
		{
			std::cout<<"Parent Node = "<<arr[previous]<<std::endl;
		}
	}
}
void PreOrder(int x)
{
	if(arr[x]=='\0')
	{
		return;
	}
	std::cout<<arr[x]<<" ";
	PreOrder((x*2)+1);
	PreOrder((x*2)+2);
}
void InOrder(int x)
{
	if(arr[x]=='\0')
	{
		return;
	}
	InOrder((x*2)+1);
	std::cout<<arr[x]<<" ";
	InOrder((x*2)+2);
}
void PostOrder(int x)
{
	if(arr[x]=='\0')
	{
		return;
	}
	PostOrder((x*2)+1);
	PostOrder((x*2)+2);
	std::cout<<arr[x]<<" ";
}
int main()
{
	int choice,value;
	while(1)
	{
		std::cout<<"1.INSERT NODE"<<std::endl;
		std::cout<<"2.LEVEL ORDER TRAVERSAL"<<std::endl;
		std::cout<<"3.SEARCH NODE"<<std::endl;
		std::cout<<"4.PARENT NODE"<<std::endl;
		std::cout<<"5.PREORDER TRAVERSAL"<<std::endl;
		std::cout<<"6.INORDER TRAVERSAL"<<std::endl;
		std::cout<<"7.POSTORDER TRAVERSAL"<<std::endl;
		std::cout<<"8.EXIT"<<std::endl;
		std::cout<<"CHOOSE YOUR OPTION:";
		std::cin>>choice;
		if(choice==1)
		{
			system("cls");
			std::cout<<"Enter Node Value:";
			std::cin>>value;
			Insert(value);
		}
		else if(choice==2)
		{
			system("cls");
			LevelOrder();
		}
		else if(choice==3)
		{
			system("cls");
			std::cout<<"Enter Node Value:";
			std::cin>>value;
			Search(value);
		}
		else if(choice==4)
		{
			system("cls");
			std::cout<<"Enter Node Value:";
			std::cin>>value;
			ParentNode(value);
		}
		else if(choice==5)
		{
			PreOrder(root);
			std::cout<<std::endl;
		}
		else if(choice==6)
		{
			InOrder(root);
			std::cout<<std::endl;
		}
		else if(choice==7)
		{
			PostOrder(root);
			std::cout<<std::endl;
		}
		else if(choice==8)
		{
			return 0;
		}
	}
}
