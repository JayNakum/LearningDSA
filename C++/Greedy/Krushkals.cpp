#include <bits/stdc++.h>

typedef std::pair<int, int> vertexPair;

struct Graph
{
    int V, E;
    std::vector<std::pair<int, vertexPair>> edges;

    Graph(int V, int E)
        : V(V), E(E) {}
};

struct DisjointSets
{
    int *parent, *weight;
    int n;

    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n + 1];
        weight = new int[n + 1];

        for (int i = 0; i <= n; i++)
        {
            weight[i] = 0;
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unionSets(int x, int y)
    {
        x = find(x), y = find(y);

        if (weight[x] > weight[y])
            parent[y] = x;

        parent[x] = y;

        if (weight[x] == weight[y])
            weight[y]++;
    }
};
