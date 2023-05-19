#include"node.h"
struct graph{
	private:
		node *head;
	public:
		graph();
		~graph();
		void InsertNode(int);
		void addEdges(int,int);
		void PrintGraph();
		void countOutdegree(int);
		void countIndegree(int);
};
