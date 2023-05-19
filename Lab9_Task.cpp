#include"Task2.h"
BST::BST()
{
	this->data=0;
	this->left=NULL;
	this->right=NULL;
	this->root=NULL;
}
BST::BST(int data)
{
	this->data=data;
	this->left=NULL;
	this->right=NULL;
	this->root=NULL;
}
BST::~BST(){}
void BST::InsertNode(int data)
{
	BST *node=new BST(data);
	if(this->root==NULL)
	{
		this->root=node;
	}
	else
	{
		BST *temp=root;
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
			else if(data==temp->data)
			{
				std::cout<<"Node Value already exists"<<std::endl;
				temp=NULL;
			}
		}
	}
}
void BST::LevelOrder()
{
	std::queue<BST*> q;
	q.push(this->root);
	while(!q.empty())
	{
		BST *temp=q.front();
		std::cout<<temp->data<<" ";
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
}
int BST::Height_Find(BST *t)
{
	if(t==NULL)
	{
		return -1;
	}
	int left_max=Height_Find(t->left);
	int right_max=Height_Find(t->right);
	if(left_max>=right_max)
	{
		return left_max+1;
	}
	else if(right_max>=left_max)
	{
		return right_max+1;
	}
}
void BST::PreOrder(BST *root)
{
	if(root==NULL)
	{
		return;
	}
	std::cout<<root->data<<" ";
	PreOrder(root->left);
	PreOrder(root->right);
}
void BST::InOrder(BST *root)
{
	if(root==NULL)
	{
		return;
	}
	InOrder(root->left);
	std::cout<<root->data<<" ";
	InOrder(root->right);
}
void BST::PostOrder(BST *root)
{
	if(root==NULL)
	{
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	std::cout<<root->data<<" ";
}
void BST::Right_Subtree_Order_Display()
{
	for(int i=0;i<3;i++)
	{
		if(i==0)
		{
			std::cout<<"Post-Order = ";
			PostOrder(this->root->right);
			std::cout<<std::endl;
		}
		else if(i==1)
		{
			std::cout<<"In-Order = ";
			InOrder(this->root->right);
			std::cout<<std::endl;
		}
		else if(i==2)
		{
			std::cout<<"Pre-Order = ";
			PreOrder(this->root->right);
			std::cout<<std::endl;
		}
	}
}
