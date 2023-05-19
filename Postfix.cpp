#include<iostream>
#include<stack>
#include<queue>
struct BST{
	char data;
	BST *left;
	BST *right;
}*root=NULL;
std::stack<BST*> s;
void CreateNode(BST *a,BST *operand1,BST *operand2)
{
	if(operand1==NULL)
	{
		a->left=NULL;
	}
	else
	{
		a->left=operand1;
	}
	if(operand2==NULL)
	{
		a->right=NULL;
	}
	else
	{
		a->right=operand2;
	}
	s.push(a);
	root=a;
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
void Expression_Evaluation(std::string expression)
{
	for(int i=0;i<expression.length();i++)
	{
		if(expression[i]>=65 && expression[i]<=90 || expression[i]>=97 && expression[i]<=122)
		{
			BST *temp=new BST;
			temp->data=expression[i];
			temp->left=NULL;
			temp->right=NULL;
			s.push(temp);
		}
		else if(expression[i]=='*' || expression[i]=='+' || expression[i]=='-' || expression[i]=='/')
		{
			BST *temp=new BST;
			temp->data=expression[i];
			BST *operand2=s.top();
			s.pop();
			BST *operand1=s.top();
			s.pop();
			CreateNode(temp,operand1,operand2);
		}
	}
}
int main()
{
	std::string expression;
	std::cout<<"Enter Expression:";
	std::cin>>expression;
	Expression_Evaluation(expression);
	LevelOrder();
}
