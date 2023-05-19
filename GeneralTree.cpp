#include"GeneralTree.h"
Tree::Tree()
{
	this->root=NULL;
	this->left=NULL;
	this->right=NULL;
}
Tree::Tree(int data)
{
	this->data=data;
	this->left=NULL;
	this->right=NULL;
}
Tree::~Tree(){}
Tree* Tree::Insert(int data)
{
	Tree *t=new Tree(data);
	return t;
}
void Tree::LevelOrder()
{
	if(this->root==NULL)
	{
		std::cout<<"Tree is Empty"<<std::endl;
	}
	std::queue<Tree*> q;
	q.push(this->root);
	while(!q.empty())
	{
		Tree *t=q.front();
		std::cout<<t->data<<" ";
		int size=t->child.size();
		for(int i=0;i<size;i++)
		{
			q.push(t->child[i]);
		}
		q.pop();
	}
}












