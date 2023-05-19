#include"graph.h"
int main()
{
	graph *g=new graph();
	g->add_vertices(5);
	g->add_edges(1,5);
	g->add_edges(2,3);
	g->add_edges(3,5);
	g->add_edges(2,4);
	g->add_edges(4,3);
	g->add_edges(4,2);
	g->add_edges(2,5);
	g->Display();
	g->countOutdegree(2);
	g->countIndegree(3);
}
