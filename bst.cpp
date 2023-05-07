#include"bst.h"
BST::BST()
{
	this->root=NULL;
	this->left=NULL;
	this->right=NULL;
}
BST::BST(int data)
{
	this->data=data;
	this->left=NULL;
	this->right=NULL;
}
BST::~BST(){}
void BST::Insert(int data)
{
	BST *temp=new BST(data);
	if(this->root==NULL)
	{
		this->root=temp;
	}
	else
	{
		BST *z=this->root;
		while(1)
		{
			if(temp->data>z->data && z->right==NULL)
			{
				z->right=temp;
				break;
			}
			else if(temp->data>z->data && z->right != NULL)
			{
				z=z->right;
			}
			else if(temp->data<z->data && z->left==NULL)
			{
				z->left=temp;
				break;
			}
			else if(temp->data<z->data && z->left != NULL)
			{
				z=z->left;
			}
		}
	}
}
void BST::LevelOrder()
{
	if(this->root==NULL)
	{
		std::cout<<"Tree is Empty"<<std::endl;
	}
	else
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
void BST::PostOrder(BST *root)
{
	if(root==NULL)
	{
		return;
	}
	std::cout<<root->data<<" ";
	PostOrder(root->left);
	PostOrder(root->right);
}
bool BST::Search(int data)
{
	BST *z=this->root;
	while(z->data != data)
	{
		if(data<z->data)
		{
			z=z->left;
		}
		else if(data>z->data)
		{
			z=z->right;
		}
		if(z==NULL) break;
	}
	if(z==NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void BST::SearchParent(int data)
{
	if(this->root->data==data)
	{
		std::cout<<"Root does not have Parent"<<std::endl;
	}
	else if(!this->Search(data))
	{
		std::cout<<"Element does not Exist in Tree"<<std::endl;
	}
	else
	{
		BST *z=this->root,*previous=NULL;
		while(1)
		{
			if(z->data>data)
			{
				previous=z;
				z=z->left;
			}
			else if(z->data<data)
			{
				previous=z;
				z=z->right;
			}
			else if(z->data==data) break;
		}
			std::cout<<"Parent = "<<previous->data<<std::endl;
	}
}
