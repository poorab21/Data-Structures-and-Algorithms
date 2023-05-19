#include<iostream>
#include<stack>
#include<queue>
struct BST{
	char data;
	BST *left;
	BST *right;
};
std::stack<BST*> s,s2;
bool isOperand(char x)
{
	if(x>='a' && x<='z' || x>='A' && x<='Z' || x>='0' && x<='9')
	{
		return true;
	}
	return false;
}
bool isOperator(char x)
{
	if(x=='+' || x=='-' || x=='*' || x=='/' || x=='(' || x==')')
	{
		return true;
	}
	return false;
}
void Evaluation(std::string expression)
{
	for(int i=0;i<expression.length();i++)
	{
		if(isOperand(expression[i]))
		{
			BST *temp=new BST;
			temp->data=expression[i];
			temp->left=NULL;
			temp->right=NULL;
			s.push(temp);
		}
		else if(isOperator(expression[i]))
		{
			if(s2.empty())
			{
				BST *temp=new BST;
				temp->data=expression[i];
				temp->left=NULL;
				temp->right=NULL;
				s2.push(temp);
			}
			else if(expression[i]=='(')
			{
				BST *temp=new BST;
				temp->data=expression[i];
				temp->left=NULL;
				temp->right=NULL;
				s2.push(temp);
			}
			else if(expression[i]=='+' || expression[i]=='-')
			{
				BST *z=s2.top();
				if(z->data=='+' || z->data=='-')
				{
					BST *operand2=s.top();
					s.pop();
					BST *operand1=s.top();
					s.pop();
					s2.pop();
					BST *temp=new BST;
					temp->data=expression[i];
					temp->left=NULL;
					temp->right=NULL;
					s2.push(temp);
					z->left=operand1;
					z->right=operand2;
					s.push(z);
				}
				else if(z->data=='*' || z->data=='/')
				{
					BST *temp=s2.top();
					while(temp->data != '+' && temp->data != '-' && !s2.empty() && temp->data != '(')
					{
						BST *operand2=s.top();
						s.pop();
						BST *operand1=s.top();
						s.pop();
						s2.pop();
						temp->left=operand1;
						temp->right=operand2;
						s.push(temp);
						if(s2.empty()) break;
						temp=s2.top();
					}
					if(temp->data=='+')
					{
						s2.pop();
						BST *temp2=new BST;
						temp2->data=expression[i];
						temp2->left=NULL;
						temp2->right=NULL;
						s2.push(temp2);
						BST *operand2=s.top();
						s.pop();
						BST *operand1=s.top();
						s.pop();
						temp->left=operand1;
						temp->right=operand2;
						s.push(temp);
					}
					else if(temp->data=='-')
					{
						s2.pop();
						BST *temp2=new BST;
						temp2->data=expression[i];
						temp2->left=NULL;
						temp2->right=NULL;
						s2.push(temp2);
						BST *operand2=s.top();
						s.pop();
						BST *operand1=s.top();
						s.pop();
						temp->left=operand1;
						temp->right=operand2;
						s.push(temp);
					}
					else if(s2.empty())
					{
						BST *temp3=new BST;
						temp3->data=expression[i];
						temp3->left=NULL;
						temp3->right=NULL;
						s2.push(temp3);
					}
					else if(temp->data=='(')
					{
						BST *temp3=new BST;
						temp3->data=expression[i];
						temp3->left=NULL;
						temp3->right=NULL;
						s2.push(temp3);
					}
				}
				else if(z->data=='(')
				{
					BST *temp3=new BST;
					temp3->data=expression[i];
					temp3->left=NULL;
					temp3->right=NULL;
					s2.push(temp3);
				}
			}
			else if(expression[i]=='*' || expression[i]=='/')
			{
				BST *temp=s2.top();
				if(temp->data=='+' || temp->data=='-' || temp->data=='(' || s2.empty())
				{
					BST *temp2=new BST;
					temp2->data=expression[i];
					temp2->left=NULL;
					temp2->right=NULL;
					s2.push(temp2);
				}
				else if(temp->data=='/' || temp->data=='*' )
				{
					s2.pop();
					BST *temp2=new BST;
					temp2->data=expression[i];
					temp2->left=NULL;
					temp2->right=NULL;
					s2.push(temp2);
					BST *operand2=s.top();
					s.pop();
					BST *operand1=s.top();
					s.pop();
					temp->left=operand1;
					temp->right=operand2;
					s.push(temp);
				}
			}
			else if(expression[i]==')')
			{
				BST *temp=s2.top();
				while(temp->data != '(')
				{
					BST *operand2=s.top();
					s.pop();
					BST *operand1=s.top();
					s.pop();
					temp->left=operand1;
					temp->right=operand2;
					s.push(temp);
					s2.pop();
					temp=s2.top();
				}
				if(temp->data=='(')
				{
					s2.pop();
				}
			}
		}
	}
	while(!s2.empty())
	{
		BST *operand2=s.top();
		s.pop();
		BST *operand1=s.top();
		s.pop();
		BST *z=s2.top();
		s2.pop();
		z->left=operand1;
		z->right=operand2;
		s.push(z);
	}
}
void LevelOrder()
{
	std::queue<BST*> q;
	q.push(s.top());
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
void PreOrder(BST *root)
{
	if(root==NULL)
	{
		return;
	}
	PreOrder(root->left);
	PreOrder(root->right);
	std::cout<<root->data<<" ";
}
void PostOrder(BST *root)
{
	if(root==NULL)
	{
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	std::cout<<root->data<<" ";
}
int main()
{
	std::string expression;
	std::cout<<"Enter Expression:";
	std::cin>>expression;
	Evaluation(expression);
	LevelOrder();
}

