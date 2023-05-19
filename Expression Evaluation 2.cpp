#include<iostream>
#include<stack>
#include<stdlib.h>
int main()
{
	std::string expression;
	std::stack<char> s;
	std::stack<std::string> s2;
	s.push('\0');
	s2.push("\0");
	std::cout<<"Enter Expression:";
	std::cin>>expression;
	for(int i=0;i<expression.length();i++)
	{
		if(expression[i]=='(')
		{
			s.push(expression[i]);
		}
		else if(expression[i]=='*' || expression[i]=='/')
		{
			if(s.top()=='+' || s.top()=='-' || s.empty() || s.top()=='\0' || s.top()=='(')
			{
				s.push(expression[i]);
			}
			else if(s.top()=='*')
			{
				s.pop();
				float operand2=std::stof(s2.top());
				s2.pop();
				float operand1=std::stof(s2.top());
				s2.pop();
				std::string result=std::to_string(operand1*operand2);
				s2.push(result);
				s.push(expression[i]);
			}
			else if(s.top()=='/')
			{
				s.pop();
				float operand2=std::stof(s2.top());
				s2.pop();
				float operand1=std::stof(s2.top());
				s2.pop();
				std::string result=std::to_string(operand1/operand2);
				s2.push(result);
				s.push(expression[i]);
			}
		}
		else if(expression[i]=='+' || expression[i]=='-')
		{
			if(s.top()=='(' || s.top()=='\0' || s.empty())
			{
				s.push(expression[i]);
			}
			else if(s.top()=='+')
			{
				s.pop();
				float operand2=std::stof(s2.top());
				s2.pop();
				float operand1=std::stof(s2.top());
				s2.pop();
				std::string result=std::to_string(operand1+operand2);
				s2.push(result);
				s.push(expression[i]);
			}
			else if(s.top()=='-')
			{
				s.pop();
				float operand2=std::stof(s2.top());
				s2.pop();
				float operand1=std::stof(s2.top());
				s2.pop();
				std::string result=std::to_string(operand1-operand2);
				s2.push(result);
				s.push(expression[i]);
			}
			else if(s.top()=='*' || s.top()=='/')
			{
				while(1)
				{
					if(s.top()=='*')
					{
						s.pop();
						float operand2=std::stof(s2.top());
						s2.pop();
						float operand1=std::stof(s2.top());
						s2.pop();
						std::string result=std::to_string(operand1*operand2);
						s2.push(result);
					}
					else if(s.top()=='/')
					{
						s.pop();
						float operand2=std::stof(s2.top());
						s2.pop();
						float operand1=std::stof(s2.top());
						s2.pop();
						std::string result=std::to_string(operand1/operand2);
						s2.push(result);
					}
					else if(s.top()=='+')
					{
						s.pop();
						float operand2=std::stof(s2.top());
						s2.pop();
						float operand1=std::stof(s2.top());
						s2.pop();
						std::string result=std::to_string(operand1+operand2);
						s2.push(result);
						s.push(expression[i]);
						break;
					}
					else if(s.top()=='-')
					{
						s.pop();
						float operand2=std::stof(s2.top());
						s2.pop();
						float operand1=std::stof(s2.top());
						s2.pop();
						std::string result=std::to_string(operand1-operand2);
						s2.push(result);
						s.push(expression[i]);
						break;
					}
					else if(s.top()=='(' || s.empty() || s.top()=='\0')
					{
						s.push(expression[i]);
						break;
					}
				}
			}
		}
		else if(expression[i]==')')
		{
			while(s.top() != '(')
			{
				float operand2=std::stof(s2.top());
				s2.pop();
				float operand1=std::stof(s2.top());
				s2.pop();
				if(s.top()=='+')
				{
					s2.push(std::to_string(operand1+operand2));
				}
				else if(s.top()=='-')
				{
					s2.push(std::to_string(operand1-operand2));
				}
				else if(s.top()=='/')
				{
					s2.push(std::to_string(operand1/operand2));
				}
				else if(s.top()=='*')
				{
					s2.push(std::to_string(operand1*operand2));
				}
				s.pop();
			}
			s.pop();
		}
		else if(expression[i]>='0' && expression[i]<='9')
		{
			int x=i;
			std::string value;
			while(expression[x]>='0' && expression[x]<='9')
			{
				value+=expression[x];
				x++;
			}
			i=x-1;
			s2.push(value);
		}
	}
	while(s.top() != '\0')
	{
		float operand2=std::stof(s2.top());
		s2.pop();
		float operand1=std::stof(s2.top());
		s2.pop();
		if(s.top()=='+')
		{
			s2.push(std::to_string(operand1+operand2));
		}
		else if(s.top()=='-')
		{
			s2.push(std::to_string(operand1-operand2));
		}
		else if(s.top()=='/')
		{
			s2.push(std::to_string(operand1/operand2));
		}
		else if(s.top()=='*')
		{
			s2.push(std::to_string(operand1*operand2));
		}
		s.pop();
	}
	std::cout<<"Expression Evaluation = "<<s2.top();
}
