#include<iostream>
#include<queue>
struct Tree{
	int data;
	Tree *left;
	Tree *right;
}*root=NULL;
void InsertNode(int data)
{
	Tree *temp=new Tree;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		std::queue<Tree*> q;
		q.push(root);
		while(1)
		{
			Tree *sub=q.front();
			if(sub->left != NULL)
			{
				q.push(sub->left);
			}
			if(sub->right != NULL)
			{
				q.push(sub->right);
			}
			if(sub->left==NULL)
			{
				sub->left=temp;
				break;
			}
			else if(sub->right==NULL)
			{
				sub->right=temp;
				break;
			}
			q.pop();
		}
	}
}
void Display()
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
void PreOrder(Tree *t)
{
	if(t==NULL)
	{
		return;
	}
	else
	{
		std::cout<<t->data<<" ";
		PreOrder(t->left);
		PreOrder(t->right);
	}
}
void InOrder(Tree *t)
{
	if(t==NULL)
	{
		return;
	}
	else
	{
		InOrder(t->left);
		std::cout<<t->data<<" ";
		InOrder(t->right);
	}
}
void PostOrder(Tree *t)
{
	if(t==NULL)
	{
		return;
	}
	else
	{
		PostOrder(t->left);
		PostOrder(t->right);
		std::cout<<t->data<<" ";
	}
}
int main()
{
	int choice,value;
	while(1)
	{
		std::cout<<"1.INSERT NODE"<<std::endl;
		std::cout<<"2.DISPLAY"<<std::endl;
		std::cout<<"3.PREORDER TRAVERSAL"<<std::endl;
		std::cout<<"4.INORDER TRAVERSAL"<<std::endl;
		std::cout<<"5.POSTORDER TRAVERSAL"<<std::endl;
		std::cout<<"6.EXIT"<<std::endl;
		std::cout<<"Choose your options:";
		std::cin>>choice;
		if(choice==1)
		{
			std::cout<<"Enter Value:";
			std::cin>>value;
			InsertNode(value);
		}
		else if(choice==2)
		{
			system("cls");
			Display();
		}
		else if(choice==3)
		{
			system("cls");
			PreOrder(root);
			std::cout<<std::endl;
		}
		else if(choice==4)
		{
			system("cls");
			InOrder(root);
			std::cout<<std::endl;
		}
		else if(choice==5)
		{
			system("cls");
			PostOrder(root);
			std::cout<<std::endl;
		}
		else if(choice==6)
		{
			return 0;
		}
	}
}
