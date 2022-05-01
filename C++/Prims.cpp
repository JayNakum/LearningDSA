#include <iostream>
#include <vector>

int main()
{
    std::cout << "Prims" << std::endl;

    int v;
    std::cout << "Enter number of vertices: ";
    std::cin >> v;

    std::vector<std::vector<int>> graph;
    graph.reserve(v);
    std::cout << "Enter adjacency matrix: " << std::endl;

    for (int i = 0; i < v; i++)
    {
        std::vector<int> row;
        row.reserve(v);
        
        for (int j = 0; j < v; j++) {
            int val;
            std::cin >> val;
            row.emplace_back(val);
        }
        graph.emplace_back(row);
    }

    std::cout << std::endl << "Adjacency Matrix" << std::endl;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            std::cout << " " << graph[i][j];
        }
        std::cout << std::endl;
    }

    std::cin.get();
}