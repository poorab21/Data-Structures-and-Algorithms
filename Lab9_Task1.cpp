#include"Task1.h"
BST::BST()
{
	this->data='\0';
	this->left=NULL;
	this->right=NULL;
}
BST::BST(const char data)
{
	this->data=data;
	this->left=NULL;
	this->right=NULL;
}
BST::~BST(){}
BST* BST::InsertNode(const char data)
{
	BST *temp=new BST(data);
	return temp;
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
void BST::PostOrder_Conversion(BST *root)
{
	if(root==NULL)
	{
		return;
	}
	PostOrder_Conversion(root->left);
	PostOrder_Conversion(root->right);
	PostFix_Expression+=root->data;
}
