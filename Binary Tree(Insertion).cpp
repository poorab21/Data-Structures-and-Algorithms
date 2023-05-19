#include<iostream>
#include<queue>
struct Tree{
	int data;
	Tree *left;
	Tree *right;
}*root=NULL;
void Insert(int data)
{
	Tree *t=new Tree;
	t->data=data;
	t->left=NULL;
	t->right=NULL;
	if(root==NULL)
	{
		root=t;
	}
	else
	{
		int root_value,determine=0;
		std::queue<Tree*> q;
		std::cout<<"Enter Root:";
		std::cin>>root_value;
		q.push(root);
		while(!q.empty())
		{
			Tree *temp=q.front();
			if(root_value==temp->data)
			{
				determine=1;
				if(temp->left != NULL && temp->right != NULL)
				{
					std::cout<<"Left and Right Child are filled"<<std::endl;
				}
				else if(temp->left != NULL)
				{
					temp->right=t;
					break;
				}
				else if(temp->right != NULL)
				{
					temp->left=t;
					break;
				}
				else if(temp->left==NULL && temp->right==NULL)
				{
					int child;
					std::cout<<"Enter in left child(1) or right child(2):";
					std::cin>>child;
					if(child==1)
					{
						temp->left=t;
					}
					else if(child==2)
					{
						temp->right=t;
					}
					break;
				}
			}
			if(temp->left != NULL)
			{
				q.push(temp->left);
			}
			if(temp->right != NULL)
			{
				q.push(temp->right);
			}
			q.pop();
		}
		if(determine==0)
		{
			std::cout<<"Root not Found"<<std::endl;
		}
	}
}
void Level_Order()
{
	std::queue<Tree*> q;
	q.push(root);
	while(!q.empty())
	{
		Tree *sub=q.front();
		std::cout<<sub->data<<" ";
		if(sub->left != NULL)
		{
			q.push(sub->left);
		}
		if(sub->right != NULL)
		{
			q.push(sub->right);
		}
		q.pop();
	}
	std::cout<<std::endl;
}
int Find_Height(Tree *t)
{
	if(t==NULL)
	{
		return -1;
	}
	int left_max=Find_Height(t->left);
	int right_max=Find_Height(t->right);
	if(left_max>=right_max)
	{
		return left_max+1;
	}
	else if(right_max>=left_max)
	{
		return right_max+1;
	}
}
void InOrder(Tree *t)
{
	if(t==NULL)
	{
		return;
	}
	InOrder(t->left);
	std::cout<<t->data<<" ";
	InOrder(t->right);
}
void PostOrder(Tree *t)
{
	if(t==NULL)
	{
		return;
	}
	PostOrder(t->left);
	PostOrder(t->right);
	std::cout<<t->data<<" ";
}
void PreOrder(Tree *t)
{
	if(t==NULL)
	{
		return;
	}
	std::cout<<t->data<<" ";
	PreOrder(t->left);
	PreOrder(t->right);
}
void All_Order_Display()
{
	for(int i=0;i<3;i++)
	{
		if(i==0)
		{
			std::cout<<"Pre-Order = ";
			PreOrder(root->right);
			std::cout<<std::endl;
		}
		else if(i==1)
		{
			std::cout<<"In-Order = ";
			InOrder(root->right);
			std::cout<<std::endl;
		}
		else if(i==2)
		{
			std::cout<<"Post-Order = ";
			PostOrder(root->right);
			std::cout<<std::endl;
		}
	}
}
int main()
{
	int choice,value;
	while(1)
	{
		std::cout<<"1.INSERT NODE"<<std::endl;
		std::cout<<"2.LEVEL ORDER DISPLAY"<<std::endl;
		std::cout<<"3.FIND HEIGHT"<<std::endl;
		std::cout<<"4.RIGHT SUBTREE ALL ORDER DISPLAY"<<std::endl;
		std::cout<<"5.EXIT"<<std::endl;
		std::cout<<"Enter your choice:";
		std::cin>>choice;
		if(choice==1)
		{
			system("cls");
			std::cout<<"Enter Value for Node:";
			std::cin>>value;
			Insert(value);
		}
		else if(choice==2)
		{
			system("cls");
			Level_Order();
		}
		else if(choice==3)
		{
			system("cls");
			std::cout<<"Height = "<<Find_Height(root)<<std::endl;
		}
		else if(choice==4)
		{
			All_Order_Display();
		}
		else if(choice==5)
		{
			return 0;
		}
	}
}
