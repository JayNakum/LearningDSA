#include <iostream>
#include <math.h>

void printArray(double arr[], const int &n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

class Heap
{
public:
    int size;

private:
    int LEFT(int i) const
    {
        return 2 * i;
    }
    int RIGHT(int i) const
    {
        return 2 * i + 1;
    }
    int PARENT(int i) const
    {
        return floor(2 / i);
    }
    void SWAP(double &a, double &b)
    {
        double temp = a;
        a = b;
        b = temp;
    }

public:
    void maxHeapify(double arr[], int i)
    {
        int l = LEFT(i);
        int r = RIGHT(i);
        int largest = i;
        if (l < size && arr[l] > arr[i])
            largest = l;

        else
            largest = i;

        if (r < size && arr[r] > arr[largest])
            largest = r;

        if (i != largest)
        {
            SWAP(arr[i], arr[largest]);
            maxHeapify(arr, largest);
        }
    }
    void buildMaxHeap(double arr[], const int n)
    {
        size = n;
        for (int i = floor(size / 2); i >= 0; i--)
        {
            maxHeapify(arr, i);
        }
    }
    void heapSort(double arr[], const int n)
    {
        buildMaxHeap(arr, n);
        std::cout << "Binary Heap:\t";
        printArray(arr, n);
        for (int i = size - 1; i >= 0; i--)
        {
            SWAP(arr[0], arr[i]);
            size -= 1;
            maxHeapify(arr, 0);
        }
    }
};

int main()
{
    const int n = 10;
    double arr[n] = {1, 8, 9, 6, 5, 2, 3, 7, 0, 4};
    std::cout << "Input Array:\t";
    printArray(arr, n);

    Heap heap;
    heap.heapSort(arr, n);

    std::cout << "Sorted Array:\t";
    printArray(arr, n);
}