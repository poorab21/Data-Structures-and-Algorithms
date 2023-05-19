#include<iostream>
int top=-1;
char arr[20];
void Push(char value)
{
	top++;
	arr[top]=value;
}
void Pop()
{
	arr[top]='\0';
	top--;
}
int main()
{
	std::string Infix,PostFix;
	std::cout<<"Enter Expression:";
	std::cin>>Infix;
	for(int i=0;i<Infix.length();i++)
	{
		if(Infix[i]>=65 && Infix[i]<=90 || Infix[i]>=97 && Infix[i]<=122)
		{
			PostFix+=Infix[i];
		}
		else if(Infix[i]=='(')
		{
			Push(Infix[i]);
		}
		else if(Infix[i]==')')
		{
			while(arr[top] != '(')
			{
				PostFix+=arr[top];
				Pop();
			}
			Pop();
		}
		else if(Infix[i]=='/')
		{
			if(arr[top]=='*' || arr[top]=='/')
			{
				PostFix+=arr[top];
				Pop();
				Push('/');
			}
			else
			{
				Push('/');
			}
		}
		else if(Infix[i]=='*')
		{
			if(arr[top]=='/' || arr[top]=='*')
			{
				PostFix+=arr[top];
				Pop();
				Push('*');
			}
			else
			{
				Push('*');
			}
		}
		else if(Infix[i]=='+')
		{
			if(arr[top]=='-' || arr[top]=='+')
			{
				PostFix+=arr[top];
				Pop();
				Push('+');
			}
			else if(arr[top]=='(')
			{
				Push('+');
			}
			else
			{
				while(1)
				{
					if(arr[top]=='*' || arr[top]=='/')
					{
						PostFix+=arr[top];
						Pop();
					}
					else if(arr[top]=='-' || arr[top]=='+')
					{
						PostFix+=arr[top];
						Pop();
						Push('+');
						break;
					}
					else
					{
						Push('+');
						break;
					}
				}
			}
		}
		else if(Infix[i]=='-')
		{
			if(arr[top]=='+' || arr[top]=='-')
			{
				PostFix+=arr[top];
				Pop();
				Push('-');
			}
			else if(arr[top]=='(')
			{
				Push('-');
			}
			else
			{
				while(1)
				{
					if(arr[top]=='*' || arr[top]=='/')
					{
						PostFix+=arr[top];
						Pop();
					}
					else if(arr[top]=='+' || arr[top]=='-')
					{
						PostFix+=arr[top];
						Pop();
						Push('-');
						break;
					}
					else
					{
						Push('-');
						break;
					}
				}
			}
		}
	}
	while(top != -1)
	{
		PostFix+=arr[top];
		top--;
	}
	std::cout<<"PostFix Expression = "<<PostFix<<std::endl;
}
