#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cstdio>

using namespace std;

struct Edge{

    char vertex1;
    char vertex2;
    int weight;

    Edge(char v1,char v2,int w)
    {
            vertex1=v1;
            vertex2=v2;
            weight=w;
    }
};

struct Graph{

        vector<char> vertics;
        vector<Edge> edges;

};

unordered_map<char,char> Parent;
unordered_map<char,char> Rank;

char Find(char vertex)
{
        if(Parent[vertex]==vertex)
                return Parent[vertex];
        else return Find(Parent[vertex]);
}

void Union(char root1,char root2)
{
        if(Rank[root1]>Rank[root2])
                Parent[root2]=root1;
        else if(Rank[root1]<Rank[root2])
                Parent[root1]=root2;
        else
        {
                Parent[root1]=root2;
                Rank[root2]++;
        }
}

void makeSet(char vertex)
{
        Parent[vertex]=vertex;
        Rank[vertex]=0;
}

bool compare(Edge x,Edge y)
{
        return x.weight<y.weight;
}


vector<Edge> kruskal(Graph& g)
{
        vector<Edge> A;

        for(auto v : g.vertics)
                makeSet(v);

        sort(g.edges.begin(),g.edges.end(),compare);

        for(Edge e : g.edges)
        {
                char root1=Find(e.vertex1);
                char root2=Find(e.vertex2);

                if(root1!=root2)
                {
                        A.push_back(e);
                        Union(root1,root2);
                }
        }

        return A;
}

int main()
{
        vector<char> v={'a','b','c','d','e','f'};
        Graph g;

        g.vertics=v;

        g.edges.push_back(Edge('a','b',4));
        g.edges.push_back(Edge('a','f',2));
        g.edges.push_back(Edge('f','b',5));
        g.edges.push_back(Edge('c','b',6));
        g.edges.push_back(Edge('c','f',1));
        g.edges.push_back(Edge('f','e',4));
        g.edges.push_back(Edge('d','e',2));
        g.edges.push_back(Edge('d','c',3));

        vector<Edge>MinTree=kruskal(g);

        for(Edge e : MinTree)
                cout<<e.vertex1<<"==>"<<e.vertex2<<" "<<e.weight<<endl;

        return 0;
}








