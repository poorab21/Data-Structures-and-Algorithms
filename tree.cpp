#include"tree.h"
BST::BST()
{
	this->left=NULL;
	this->right=NULL;
}
BST::BST(int data)
{
	this->left=NULL;
	this->right=NULL;
	this->data=data;
}
BST::~BST(){}
void BST::Insert(int data)
{
	BST *t=new BST(data);
	if(this->root==NULL)
	{
		this->root=t;
	}
	else
	{
		BST *z=this->root;
		while(z != NULL)
		{
			if(data<z->data && z->left==NULL)
			{
				z->left=t;
				break;
			}
			else if(data<z->data && z->left != NULL)
			{
				z=z->left;
			}
			else if(data>z->data && z->right==NULL)
			{
				z->right=t;
				break;
			}
			else if(data>z->data && z->right != NULL)
			{
				z=z->right;
			}
		}
	}
}
BST* BST::ParentFind(int data)
{
	if(this->root->data==data)
	{
		std::cout<<"Root does not have Parent"<<std::endl;
	}
	else
	{
		BST *temp=this->root,*previous=NULL;
		while(temp != NULL)
		{
			if(temp->data<data)
			{
				previous=temp;
				temp=temp->right;
			}
			else if(temp->data>data)
			{
				previous=temp;
				temp=temp->left;
			}
			else if(temp->data==data)
			{
				break;
			}
		}
		if(temp==NULL)
		{
			std::cout<<"Element not found in Tree"<<std::endl;
		}
		else
		{
			return previous;
		}
	}
}
BST* BST::Search(int data)
{
	BST *t=this->root;
	while(t != NULL)
	{
		if(data<t->data)
		{
			t=t->left;
		}
		else if(data>t->data)
		{
			t=t->right;
		}
		else if(data==t->data)
		{
			return t;
		}
	}
}
void BST::Delete(int data)
{
	BST *n1=this->Search(data);
	BST *n2=this->ParentFind(data);
	if(n1 != NULL && n2 != NULL)
	{
		if(n1->left==NULL && n1->right==NULL)
		{
			if(n2->left==n1)
			{
				n2->left=NULL;
				n1=NULL;
				delete n1;
			}
			else
			{
				n2->right=NULL;
				n1=NULL;
				delete n1;
			}
		}
		else if(n1->left==NULL && n1->right != NULL)
		{
			if(n2->left==n1)
			{
				n2->left=n1->right;
				n1->right=NULL;
				n1=NULL;
				delete n1;
			}
			else if(n2->right==n1)
			{
				n2->right=n1->right;
				n1->right=NULL;
				n1=NULL;
				delete n1;
			}
		}
		else if(n1->left != NULL && n1->right==NULL)
		{
			if(n2->left==n1)
			{
				n2->left=n1->left;
				n1->left=NULL;
				n1=NULL;
				delete n1;
			}
			else if(n2->right==n1)
			{
				n2->right=n1->left;
				n1->left=NULL;
				n1=NULL;
				delete n1;
			}
		}
		else if(n1->left != NULL && n1->right != NULL)
		{
			if(n2->left==n1)
			{
				BST *temp=n1->left;
				if(temp->right==NULL)
				{
					n2->left=temp;
					temp->left=n1->left->left;
					temp->right=n1->right;
					n1=NULL;
					delete n1;
				}
				else
				{
					while(temp->right != NULL)
					{
						temp=temp->right;
					}
					BST *temp2=this->ParentFind(temp->data);
					temp2->right=NULL;
					n2->left=temp;
					temp->left=n1->left;
					temp->right=n1->right;
					n1=NULL;
					delete n1;
				}
			}
			else if(n2->right==n1)
			{
				BST *temp=n1->left;
				if(temp->right==NULL)
				{
					n2->right=temp;
					temp->left=n1->left->left;
					temp->right=n1->right;
					n1=NULL;
					delete n1;
				}
				else
				{
					while(temp->right != NULL)
					{
						temp=temp->right;
					}
					BST *temp2=this->ParentFind(temp->data);
					temp2->right=NULL;
					n2->right=temp;
					temp->left=n1->left;
					temp->right=n1->right;
					n1=NULL;
					delete n1;
				}
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
