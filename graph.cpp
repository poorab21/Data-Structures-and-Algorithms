#include"graph.h"
graph::graph()
{
	this->n=NULL;
	this->start=NULL;
	this->next=NULL;
}
graph::~graph(){}
graph::graph(int data)
{
	this->data=data;
	this->n=NULL;
	this->next=NULL;
}
void graph::add_vertices(int vertices)
{
	this->vertices=vertices;
	for(int i=0;i<vertices;i++)
	{
		graph *temp=new graph(i+1);
		if(this->start==NULL)
		{
			this->start=temp;
		}
		else
		{
			graph *z=this->start;
			while(z->next != NULL)
			{
				z=z->next;
			}
			z->next=temp;
		}
	}
}
void graph::add_edges(int u,int v)
{
	graph *temp=this->start;
	graph *t=new graph(v);
	while(temp != NULL)
	{
		if(temp->data==u)
		{
			break;
		}
		temp=temp->next;
	}
	if(temp==NULL)
	{
		std::cout<<"Vertice could not be found"<<std::endl;
	}
	else
	{
		if(temp->n==NULL)
		{
			temp->n=t;
		}
		else
		{
			graph *c=temp->n;
			while(c->next != NULL)
			{
				c=c->next;
			}
			c->next=t;
		}
	}
}
void graph::Display()
{
	graph *temp=this->start;
	while(temp != NULL)
	{
		graph *c=temp->n;
		std::cout<<temp->data<<"->";
		while(c != NULL)
		{
			std::cout<<c->data<<" ";
			c=c->next;
		}
		std::cout<<std::endl;
		temp=temp->next;
	}
}
void graph::countOutdegree(int u)
{
	int i=0;
	graph *temp=this->start;
	while(temp != NULL)
	{
		if(temp->data==u)
		{
			break;
		}
		temp=temp->next;
	}
	if(temp==NULL)
	{
		std::cout<<"Vertice does not Exist"<<std::endl;
	}
	else
	{
		if(temp->n==NULL)
		{
			std::cout<<"No OutDegrees"<<std::endl;
		}
		else
		{
			graph *c=temp->n;
			while(c != NULL)
			{
				i++;
				c=c->next;
			}
		}
	}
	std::cout<<"Total OutDegrees = "<<i<<std::endl;
}
void graph::countIndegree(int u)
{
	int count=0;
	graph *temp=this->start;
	while(temp != NULL)
	{
		if(temp->n==NULL)
		{
			temp=temp->next;
		}
		else
		{
			graph *c=temp->n;
			while(c != NULL)
			{
				if(c->data==u)
				{
					count++;
				}
				c=c->next;
			}
			temp=temp->next;
		}
	}
	std::cout<<"Total InDegree = "<<count<<std::endl;
}
