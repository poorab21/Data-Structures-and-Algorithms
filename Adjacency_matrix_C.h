#include<iostream>
#ifndef GRAPH_H
#define GRAPH_H
class graph{
	private:
		int **arr;
		int size;
	public:
		graph();
		graph(int);
		~graph();
		void add_vertices(int);
		void add_edges(int,int);
		void Display();
		int getSize()const;
};
#endif
