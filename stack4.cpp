#include<iostream>
int main()
{
	char stack[50];
	std::string expression;
	int size,stack_size=50,determine=0;
	std::cout<<"Enter Expression:"<<std::endl;
	getline(std::cin,expression);
	size=expression.length();
	for(int i=0;i<size;i++)
	{
		if(expression[i]=='(' || expression[i]=='{' || expression[i]=='[')
		{
			stack_size--;
			stack[stack_size]=expression[i];
		}
		else if(expression[i]==')' || expression[i]=='}' || expression[i]==']')
		{
			if(expression[i]==')' && stack[stack_size]=='(')
			{
				stack[stack_size]='\0';
				stack_size++;
			}
			else if(expression[i]=='}' && stack[stack_size]=='{')
			{
				stack[stack_size]='\0';
				stack_size++;
			}
			else if(expression[i]==']' && stack[stack_size]=='[')
			{
				stack[stack_size]='\0';
				stack_size++;
			}
			else
			{
				std::cout<<"Unbalanced Expression"<<std::endl;
				determine=1;
				break;
			}
		}
	}
	if(determine==0)
	{
		std::cout<<"Balanced Expression"<<std::endl;
	}
}
