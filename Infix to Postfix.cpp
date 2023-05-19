#include<iostream>
#include<stack>
int main()
{
	std::stack<char> s;
	s.push('\0');
	std::string expression,expression2;
	std::cout<<"Enter Expression:";
	std::cin>>expression;
	for(int i=0;i<expression.length();i++)
	{
		if(expression[i]>='a' && expression[i]<='z' || expression[i]>='A' && expression[i]<='Z')
		{
			expression2+=expression[i];
		}
		else if(expression[i]=='(')
		{
			if(s.top()=='\0')
			{
				s.pop();
			}
			s.push(expression[i]);
		}
		else if(expression[i]=='/' || expression[i]=='*')
		{
			if(s.top()=='/' || s.top()=='*')
			{
				expression2+=s.top();
				s.pop();
				s.push(expression[i]);
			}
			else if(s.empty() || s.top()=='(' || s.top()=='+' || s.top()=='-')
			{
				s.push(expression[i]);
			}
			else if(s.top()=='\0')
			{
				s.pop();
				s.push(expression[i]);
			}
		}
		else if(expression[i]=='+' || expression[i]=='-')
		{
			if(s.top()=='+' || s.top()=='-')
			{
				expression2+=s.top();
				s.pop();
				s.push(expression[i]);
			}
			else if(s.top()=='(' || s.empty())
			{
				s.push(expression[i]);
			}
			else if(s.top()=='*' || s.top()=='/')
			{
				while(s.top()=='*' || s.top()=='/')
				{
					expression2+=s.top();
					s.pop();
				}
				if(s.top()=='(' || s.empty())
				{
					s.push(expression[i]);
				}
				else if(s.top()=='+' || s.top()=='-')
				{
					expression2+=s.top();
					s.pop();
					s.push(expression[i]);
				}
			}
			else if(s.top()=='\0')
			{
				s.pop();
				s.push(expression[i]);
			}
		}
		else if(expression[i]==')')
		{
			while(s.top() !='(')
			{
				expression2+=s.top();
				s.pop();
			}
			s.pop();
		}
	}
	while(!s.empty())
	{
		expression2+=s.top();
		s.pop();
	}
	std::cout<<"Postfix Expression = "<<expression2<<std::endl;
}
