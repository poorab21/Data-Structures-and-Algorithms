#include"editor.h"
editor::editor()
{
	this->start=NULL;
	this->next=NULL;
}
editor::~editor(){}
void editor::InsertNode(std::string text)
{
	node *temp=new node(text);
	if(this->start==NULL)
	{
		this->start=temp;
	}
	else
	{
		if(text[text.length()-1]>='a' && text[text.length()-1]<='z' || text[text.length()-1]>='A' && text[text.length()-1]<='Z')
		{
			node *temp2=this->start;
			while(temp2->next != NULL)
			{
				temp2=temp2->next;
			}
			temp2->next=temp;
		}
		else if(text[text.length()-1]=='.')
		{
			node *temp2=this->start;
			while(temp2->next != NULL)
			{
				temp2=temp2->next;
			}
			temp2->next=temp;
		}
		else if(text[text.length()-1]>='1' && text[text.length()-1]<='9')
		{
			node *temp2=this->start;
			int n=text[text.length()-1]-48;
			for(int i=1;i<n-1;i++)
			{	
				if(temp2->next==NULL)
				{
					temp2->next=new node("");
					temp2=temp2->next;
				}
				else
				{
					temp2=temp2->next;
				}
			}
			temp2->next=temp;
		}
	}
}
void editor::display()
{
	int i=1;
	for(node *temp=this->start;temp != NULL;temp=temp->next)
	{
		std::cout<<i<<")";
		std::cout<<temp->text<<std::endl;
		i++;
	}
	std::cout<<std::endl;
}
