#include<iostream>
#include<queue>
#include<stack>
struct Tree{
	int data;
	Tree *left;
	Tree *right;
}*root=NULL;
void InsertNode(int data)
{
	Tree *node=new Tree;
	node->data=data;
	if(root==NULL)
	{
		root=node;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		Tree *temp=root;
		while(temp != NULL)
		{
			if(data<temp->data)
			{
				if(temp->left==NULL)
				{
					temp->left=node;
					temp->left->left=NULL;
					temp->left->right=NULL;
					temp=NULL;
				}
				else
				{
					temp=temp->left;
				}
			}
			else if(data>temp->data)
			{
				if(temp->right==NULL)
				{
					temp->right=node;
					temp->right->left=NULL;
					temp->right->right=NULL;
					temp=NULL;
				}
				else
				{
					temp=temp->right;
				}
			}
		}
	}
}
void Search(int data)
{
	if(root==NULL)
	{
		std::cout<<"Tree is Empty"<<std::endl;
	}
	else
	{
		Tree *temp=root;
		while(temp->data != data)
		{
			if(data<temp->data)
			{
				temp=temp->left;
				if(temp==NULL)
				{
					break;
				}
			}
			else if(data>temp->data)
			{
				temp=temp->right;
				if(temp==NULL)
				{
					break;
				}
			}
		}
		if(temp != NULL)
		{
			std::cout<<"Node Found at "<<temp<<std::endl;
		}
		else
		{
			std::cout<<"Not Found"<<std::endl;
		}
	}
}
void ParentSearch(int data)
{
	if(root==NULL)
	{
		std::cout<<"Tree is Empty"<<std::endl;
	}
	else if(root->data==data)
	{
		std::cout<<"Root does not have Parent"<<std::endl;
	}
	else
	{
		Tree *temp=root;
		Tree *previous;
		while(temp->data != data)
		{
			if(data<temp->data)
			{
				previous=temp;
				temp=temp->left;
				if(temp==NULL)
				{
					std::cout<<"Node does not Exist"<<std::endl;
					break;
				}
			}
			else if(data>temp->data)
			{
				previous=temp;
				temp=temp->right;
				if(temp==NULL)
				{
					std::cout<<"Node does not Exist"<<std::endl;
					break;
				}
			}
		}
		if(temp != NULL)
		{
			std::cout<<"Parent Node = "<<previous->data<<std::endl;
		}
	}
}
void DeleteNode(int data)
{
	if(root==NULL)
	{
		std::cout<<"Tree is Empty"<<std::endl;
	}
	else
	{
		Tree *temp=root;
		Tree *previous;
		while(temp->data != data)
		{
			if(data<temp->data)
			{
				previous=temp;
				temp=temp->left;
				if(temp==NULL)
				{
					std::cout<<"Node does not Exist"<<std::endl;
					break;
				}
			}
			else if(data>temp->data)
			{
				previous=temp;
				temp=temp->right;
				if(temp==NULL)
				{
					std::cout<<"Node does not Exist"<<std::endl;
					break;
				}
			}
		}
	if(temp != NULL)
	{
		if(previous->right==temp)
		{
			if(temp->left==NULL && temp->right==NULL)
			{
				previous->right=NULL;
			}
			else if(temp->left==NULL && temp->right != NULL)
			{
				previous->right=temp->right;
			}
			else if(temp->left != NULL && temp->right==NULL)
			{
				previous->right=temp->left;
			}
			else if(temp->left != NULL && temp->right != NULL)
			{
				Tree *sub=temp->right,*previous2;
				while(sub->left != NULL)
				{
					previous2=sub;
					sub=sub->left;
				}
				if(sub->right != NULL)
				{
					previous2->left=sub->right;
				}
				else
				{
					previous2->left=NULL;
				}
				sub->right=previous->right->right;
				sub->left=previous->right->left;
				previous->right=sub;
			}
		}
		else if(previous->left==temp)
		{
			if(temp->left==NULL && temp->right==NULL)
			{
				previous->left=NULL;
			}
			else if(temp->left==NULL && temp->right != NULL)
			{
				previous->left=temp->right;
			}
			else if(temp->left != NULL && temp->right==NULL)
			{
				previous->left=temp->left;
			}
			else if(temp->left != NULL && temp->right != NULL)
			{
				Tree *sub=temp->right,*previous2;
				while(sub->left != NULL)
				{
					previous2=sub;
					sub=sub->left;
				}
				if(sub->right != NULL)
				{
					previous2->left=sub->right;
				}
				else
				{
					previous2->left=NULL;
				}
				sub->right=previous->left->right;
				sub->left=previous->left->left;
				previous->left=sub;
			}
		}
	}
}
}
void IsEmpty()
{
	if(root==NULL)
	{
		std::cout<<"Tree is Empty"<<std::endl;
	}
	else
	{
		std::cout<<"Tree is not Empty"<<std::endl;
	}
}
void LevelOrder()
{
	std::queue<Tree*> temp;
	temp.push(root);
	while(!temp.empty())
	{
		Tree *z=temp.front();
		std::cout<<z->data<<" ";
		if(z->left != NULL)
		{
			temp.push(z->left);
		}
		if(z->right != NULL)
		{
			temp.push(z->right);
		}
		temp.pop();
	}
	std::cout<<std::endl;
}
void PreOrder()
{
	std::stack<Tree*> s;
	s.push(NULL);
	Tree *t=root;
	while(t != NULL)
	{
		std::cout<<t->data<<" ";
		if(t->right != NULL)
		{
			s.push(t->right);
		}
		if(t->left != NULL)
		{
			t=t->left;
		}
		else
		{
			t=s.top();
			s.pop();
		}
	}
	std::cout<<std::endl;
}
void InOrder()
{
	std::stack<Tree*> s;
	Tree *t=root;
	while(1)
	{
		if(t != NULL)
		{
			s.push(t);
			t=t->left;
		}
		else
		{
			Tree *z=s.top();
			std::cout<<z->data<<" ";
			s.pop();
			if(z->right != NULL)
			{
				t=z->right;
			}
		}
		if(s.empty() && t==NULL)
		{
			break;
		}
	}
	std::cout<<std::endl;
}
void PostOrder()
{
	std::stack<Tree*> s,s2;
	s.push(root);
	if(root->left != NULL)
	{
		s2.push(root->left);
	}
	if(root->right != NULL)
	{
		s2.push(root->right);
	}
	while(!s2.empty())
	{
		Tree *z=s2.top();
		s2.pop();
		if(z->left != NULL)
		{
			s2.push(z->left);
		}
		if(z->right != NULL)
		{
			s2.push(z->right);
		}
		s.push(z);
	}
	while(!s.empty())
	{
		Tree *t=s.top();
		std::cout<<t->data<<" ";
		s.pop();
	}
	std::cout<<std::endl;
}
int main()
{
	int choice,value;
	while(1)
	{
		std::cout<<"1.INSERT NODE"<<std::endl;
		std::cout<<"2.IS TREE EMPTY?"<<std::endl;
		std::cout<<"3.LEVEL ORDER TRAVERSAL"<<std::endl;
		std::cout<<"4.SEARCH NODE"<<std::endl;
		std::cout<<"5.SEARCH PARENT NODE"<<std::endl;
		std::cout<<"6.DELETE NODE"<<std::endl;
		std::cout<<"7.PREORDER TRAVERSAL"<<std::endl;
		std::cout<<"8.INORDER TRAVERSAL"<<std::endl;
		std::cout<<"9.POSTORDER TRAVERSAL"<<std::endl;
		std::cout<<"10.EXIT"<<std::endl;
		std::cout<<"CHOOSE YOUR OPTIONS:";
		std::cin>>choice;
		if(choice==1)
		{
			system("cls");
			std::cout<<"Enter Value for Node:";
			std::cin>>value;
			InsertNode(value);
		}
		else if(choice==2)
		{
			system("cls");
			IsEmpty();
		}
		else if(choice==3)
		{
			system("cls");
			LevelOrder();
		}
		else if(choice==4)
		{
			std::cout<<"Enter Node Value:";
			std::cin>>value;
			Search(value);
		}
		else if(choice==5)
		{
			std::cout<<"Enter Node Value:";
			std::cin>>value;
			ParentSearch(value);
		}
		else if(choice==6)
		{
			std::cout<<"Enter Node to Delete"<<std::endl;
			std::cin>>value;
			DeleteNode(value);
		}
		else if(choice==7)
		{
			system("cls");
			PreOrder();
		}
		else if(choice==8)
		{
			system("cls");
			InOrder();
		}
		else if(choice==9)
		{
			system("cls");
			PostOrder();
		}
		else if(choice==10)
		{
			return 0;
		}
	}
}
