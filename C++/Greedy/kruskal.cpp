#include <algorithm>
#include <iostream>
#include <vector>

#define edge std::pair<int, int>

class Graph
{
private:
    std::vector<std::pair<int, edge>> graph;
    std::vector<std::pair<int, edge>> MST;
    int *parent;
    int V;

public:
    Graph(int V)
    {
        parent = new int[V];
        for (int i = 0; i < V; i++)
            parent[i] = i;
        graph.clear();
        MST.clear();
    }
    void addEdge(int u, int v, int w)
    {
        graph.push_back(make_pair(w, edge(u, v)));
    }
    int find_set(int i)
    {
        if (i == parent[i])
            return i;
        else
            return find_set(parent[i]);
    }
    void union_set(int u, int v)
    {
        parent[u] = parent[v];
    }
    void kruskal()
    {
        int i, uRep, vRep;
        sort(graph.begin(), graph.end());
        for (i = 0; i < graph.size(); i++)
        {
            uRep = find_set(graph[i].second.first);
            vRep = find_set(graph[i].second.second);
            if (uRep != vRep)
            {
                MST.push_back(graph[i]);
                union_set(uRep, vRep);
            }
        }
    }
    void print()
    {
        std::cout << "Edge\tWeight" << std::endl;
        for (int i = 0; i < MST.size(); i++)
        {
            std::cout << MST[i].second.first << " - " << MST[i].second.second
                      << "\t"
                      << MST[i].first
                      << std::endl;
        }
    }
};
int main()
{
    Graph g(6);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 0, 4);
    g.addEdge(2, 0, 4);
    g.addEdge(2, 1, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 2, 3);
    g.addEdge(3, 4, 3);
    g.addEdge(4, 2, 4);
    g.addEdge(4, 3, 3);
    g.addEdge(5, 2, 2);
    g.addEdge(5, 4, 3);
    g.kruskal();
    g.print();
}