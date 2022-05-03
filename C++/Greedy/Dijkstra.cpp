#include <iostream>
#include <math.h>

#define max 5

void dijkstra(float adjMatrix[max][max], int n, int src)
{
    float distance[max], prevNode[max];
    bool visited[max];
    float cost[max][max];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (adjMatrix[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = adjMatrix[i][j];

    for (int i = 0; i < n; i++)
    {
        distance[i] = cost[src][i];
        prevNode[i] = src;
        visited[i] = false;
    }

    visited[src] = true;
    for (int index = 1; index < n; index++)
    {
        float minDistance = INFINITY;
        int nextNode;
        for (int i = 0; i < n; i++)
        {
            if (distance[i] < minDistance && !visited[i])
            {
                minDistance = distance[i];
                nextNode = i;
            }
        }
        visited[nextNode] = true;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (minDistance + cost[nextNode][i] < distance[i])
                {
                    distance[i] = minDistance + cost[nextNode][i];
                    prevNode[i] = nextNode;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << "Distance[" << i << "] = " << distance[i];
        std::cout << "\nPath: " << i;
        int j = i;
        do
        {
            j = prevNode[j];
            std::cout << "--" << j;
        } while (j != src);
        std::cout << std::endl;
    }
}

int main()
{
    int n = 5;
    float adjMatrix[max][max] = {
        {0, 1, 0, 3, 10},
        {1, 0, 5, 0, 0},
        {0, 5, 0, 2, 1},
        {3, 0, 2, 0, 6},
        {10, 0, 1, 6, 0},
    };
    int src = 0;
    dijkstra(adjMatrix, n, src);
}