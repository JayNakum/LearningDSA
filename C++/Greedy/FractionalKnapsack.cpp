/** Time Complexity O(n log n) */

#include <iostream>

struct Item
{
    double p, w;
    double pw;
};

void printSolution(double *solution, const int &n)
{
    std::cout << std::endl
              << "Items: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << "\titem[" << i << "] : " << solution[i] << std::endl;
    }
}

void printItems(Item *items, const int &n)
{
    std::cout << "P: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << items[i].p << "\t";
    }
    std::cout << std::endl
              << "W: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << items[i].w << "\t";
    }
    std::cout << std::endl
              << "R: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << items[i].pw << "\t";
    }
    std::cout << std::endl;
}

void sortItems(Item *items, const int &n)
{
    std::cout << std::endl
              << "After sorting the items by p/w:" << std::endl;
    Item temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (items[j].pw > items[j - 1].pw)
            {
                temp = items[j];
                items[j] = items[j - 1];
                items[j - 1] = temp;
            }
        }
    }
    printItems(items, n);
}

double fractionalKnapsack(Item *items, const int n, double &capacity)
{
    double totalProfit = 0;
    double solution[n];

    for (int i = 0; i < n; i++)
    {
        solution[i] = 0.0;
        items[i].pw = (items[i].p / items[i].w);
    }

    sortItems(items, n);

    int i = 0;
    while (capacity >= 0)
    {
        if (items[i].w <= capacity)
        {
            totalProfit = totalProfit + items[i].p;
            capacity -= items[i].w;
            solution[i] = 1.0;
        }
        else
            break;
        i++;
    }

    if ((items[i].w - capacity) >= 0)
    {
        totalProfit = totalProfit + (capacity / items[i].w);
        solution[i] = capacity / items[i].w;
    }

    printSolution(solution, n);
    return totalProfit;
}

int main()
{
    const int item_count = 4;
    Item items[] = {
        {6, 5},
        {5, 4},
        {3, 2},
        {4, 3},
    };
    double capacity = 7;

    std::cout << "Given Items: " << std::endl;
    printItems(items, item_count);
    std::cout << "Capicity: " << capacity << std::endl;

    double maxProfit = fractionalKnapsack(items, item_count, capacity);
    std::cout << "Maximum Profit = " << maxProfit << std::endl;
}
