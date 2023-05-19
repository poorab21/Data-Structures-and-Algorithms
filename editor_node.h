#include<iostream>
class node{
	public:
		std::string text;
		node *start=NULL;
		node *next=NULL;
		node();
		node(std::string);
		~node();
};
