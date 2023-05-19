#include<iostream>
class graph{
	private:
		int data;
		graph *start=NULL;
		graph *n=NULL;
		graph *next=NULL;
		int vertices;
	public:
		graph();
		graph(int);
		~graph();
		void add_vertices(int);
		void add_edges(int,int);
		void Display();
		void countOutdegree(int);
		void countIndegree(int);
};
