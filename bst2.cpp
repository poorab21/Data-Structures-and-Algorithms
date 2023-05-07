#include"bst.h"
BST::BST()
{
	this->left=NULL;
	this->right=NULL;
	this->root=NULL;
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
			if(data<z->data && z->left==NULL)
			{
				z->left=temp;
				break;
			}
			else if(data<z->data && z->left != NULL)
			{
				z=z->left;
			}
			else if(data>z->data && z->right==NULL)
			{
				z->right=temp;
				break;
			}
			else if(data>z->data && z->right != NULL)
			{
				z=z->right;
			}
			else if(data==z->data)
			{
				std::cout<<"Value already Exists"<<std::endl;
				break;
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
BST* BST::Search(int data)
{
	BST *temp=this->root;
	while(temp != NULL)
	{
		if(data<temp->data)
		{
			temp=temp->left;
		}
		else if(data>temp->data)
		{
			temp=temp->right;
		}
		else if(data==temp->data)
		{
			break;
		}
	}
	return temp;
}
int BST::find_height(BST *root)
{
	if(root==NULL) return -1;
	int maxleft=find_height(root->left);
	int maxright=find_height(root->right);
	return fmax(maxleft,maxright)+1;
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
void BST::Right_Sub_Tree(BST *root)
{
	std::cout<<"Post-Order = ";
	this->PostOrder(root->right);
	std::cout<<std::endl;
	std::cout<<"In-Order = ";
	this->InOrder(root->right);
	std::cout<<std::endl;
	std::cout<<"Pre-Order = ";
	this->PreOrder(root->right);
}
