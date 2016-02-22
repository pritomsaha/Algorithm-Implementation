#include<bits\stdc++.h>

using namespace std;

struct Edge
{
	char vertex1,vertex2;
	int weight;

	Edge(char v1, char v2, int w)
	{
		vertex1=v1;
		vertex2=v2;
		weight=w;
	}
};

set<char> VisitedVertices;

struct  Graph
{
	std::vector<char> vertics;
	std::vector<Edge> edges;

	Graph(std::vector<char> vertices, std::vector<Edge> edges)
	{
		vertices=vertices;
		edges=edges;
	}
};

bool cmp(Edge x, Edge y)
{

	return x.weight<y.weight;
}

void kruskal(Graph& g)
{
	std::vector<Edge> MinEdges;

	sort(g.edges,cmp);

	for(Edge e: g.edges)
	{
		bool flag=false;

		if(VisitedVertices.find(e.vertex1)==VisitedVertices.end())
		{
			VisitedVertices.insert(e.vertex1);
			VisitedVertices.insert(e.vertex2);

			MinEdges.push_back(e);
		}
		else if(VisitedVertices.find(e.vertex1)==VisitedVertices.end())
		{

			VisitedVertices.insert(e.vertex2);
			MinEdges.push_back(e);
		}

	}

	
}

int main()
{

	std::vector<char> v={'a','b','c'};
	std::vector<Edge> e;

	e.push_back(new Edge('a','b',1));
	e.push_back(new Edge('a','c',2));
	e.push_back(new Edge('c','b',3));

	Graph g=new Graph(v,e); 

	kruskal(g);
	


	return 0;
}






