#include"node.h"
node::node()
{
	this->start=NULL;
	this->next=NULL;
}
node::node(std::string text)
{
	this->text=text;
	this->next=NULL;
}
node::~node(){}

