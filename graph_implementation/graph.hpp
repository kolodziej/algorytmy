#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

template <typename V, typename E>
struct Graph
{
	struct Edge : E
	{
		int v;	
	};

	struct Vertex : V, std::vector<Edge>
	{
		int s, t; // s = parent, t = time
	};

	std::vector<Vertex> g;

	Graph(int n) : g(n) {}

	void addEdgeU(int s, Edge e)
	{
		g[s].push_back(e);
	}

	void addEdgeD(int s, Edge e)
	{
		addEdgeU(s, e);
		Edge e2 = e;
		e2.v = s;
		addEdgeU(e.v, e2);
	}
		
};

#endif
