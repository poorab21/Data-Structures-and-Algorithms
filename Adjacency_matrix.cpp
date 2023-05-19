#include"graph.h"
graph::graph()
{
	this->size=0;
}
graph::graph(int vertices)
{
	this->size=vertices;
	arr=new int*[vertices];
	for(int i=0;i<vertices;i++)
	{
		arr[i]=new int[vertices];
	}
	for(int i=0;i<vertices;i++)
	{
		for(int j=0;j<vertices;j++)
		{
			arr[i][j]=0;
		}
	}
}
int graph::getSize()const
{
	return this->size;
}
void graph::add_vertices(int vertices)
{
	this->size=vertices;
	arr=new int*[vertices];
	for(int i=0;i<vertices;i++)
	{
		arr[i]=new int[vertices];
	}
	for(int i=0;i<vertices;i++)
	{
		for(int j=0;j<vertices;j++)
		{
			arr[i][j]=0;
		}
	}
}
void graph::add_edges(int row,int column)
{
	arr[row][column]=1;
}
void graph::Display()
{
	for(int i=0;i<(this->size);i++)
	{
		for(int j=0;j<(this->size);j++)
		{
			std::cout<<arr[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
graph::~graph()
{
	for(int i=0;i<(this->size);i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}





















