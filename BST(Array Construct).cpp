#include<iostream>
#include<queue>
struct BST{
	int data;
	BST *left;
	BST *right;
}*root=NULL;
void InsertNode(int data)
{
	BST *temp=new BST;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		BST *z=root;
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
		}
	}
}
void LevelOrder()
{
	std::queue<BST*> q;
	q.push(root);
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
	std::cout<<std::endl;
}
int main()
{
	int arr[100],size;
	std::cout<<"Enter Size:";
	std::cin>>size;
	for(int i=0;i<size;i++)
	{
		std::cout<<"Enter Element:";
		std::cin>>arr[i];
	}
	for(int i=0;i<size;i++)
	{
		std::cout<<arr[i]<<" ";
	}
	for(int i=0;i<size;i++)
	{
		InsertNode(arr[i]);
	}
	std::cout<<std::endl;
	std::cout<<"Tree Level Order Traversal"<<std::endl;
	LevelOrder();
}
