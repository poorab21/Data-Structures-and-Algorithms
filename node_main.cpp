#include <iostream>
#include "graph.h"
int main()
{
    graph g;
    g.InsertNode(5);
    g.addEdges(0,3);
    g.addEdges(0,1);
    g.addEdges(0,2);
    g.addEdges(1,0);
    g.addEdges(2,0);
    g.addEdges(2,1);
    g.addEdges(2,4);
    g.addEdges(2,3);
    g.addEdges(1,3);
    g.addEdges(3,4);
    g.addEdges(4,3);
    g.PrintGraph();
    g.countIndegree(3);
    g.countOutdegree(1);
}

