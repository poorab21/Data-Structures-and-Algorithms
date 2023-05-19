#include"graph.h"
int main()
{
	graph g;
	g.add_vertices(5);  
	g.add_edges(0,4);  
	g.add_edges(1,0);
    g.add_edges(2,0);
    g.add_edges(2,1);
	g.add_edges(2,4);
    g.add_edges(1,3);
    g.add_edges(3,4);
    g.add_edges(4,3);
	g.Display();
}
