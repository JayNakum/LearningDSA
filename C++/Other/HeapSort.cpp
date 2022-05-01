#include <iostream>
#include <vector>
#include <math.h>

struct Tree
{
    int PARENT(int i)
    {
        return floor(i / 2);
    }

    int LEFT(int i)
    {
        return (2 * i) + 1;
    }

    int RIGHT(int i)
    {
        return ((2 * i) + 1) + 1;
    }
};

struct Array
{
    int length;
    int heapSize;
    double *arr;
    Tree tree;
};

void printArray(double *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void maxHeapify(Array &A, int i)
{
    int l = A.tree.LEFT(i);
    int r = A.tree.RIGHT(i);

    int largest = i;

    if (l < A.heapSize && A.arr[l] > A.arr[i])
        largest = l;

    else
        largest = i;

    if (r < A.heapSize && A.arr[r] > A.arr[largest])
        largest = r;

    if (largest != i)
    {
        double temp = A.arr[largest];
        A.arr[largest] = A.arr[i];
        A.arr[i] = temp;

        maxHeapify(A, largest);
    }
}

void buildMaxHeap(Array &A)
{
    A.heapSize = A.length;
    for (int i = floor(A.length / 2); i >= 0; i--)
    {
        maxHeapify(A, i);
    }
}

int extractMax(Array &A)
{
    if (A.heapSize >= 0)
    {
        double max = A.arr[0];
        A.heapSize -= 1;
        A.arr[0] = A.arr[A.heapSize];
        maxHeapify(A, 0);
        return max;
    }
    else
    {
        std::cout << "Underflow" << std::endl;
        return -1;
    }
}

void heapSort(Array &A)
{
    buildMaxHeap(A);
    printArray(A.arr, A.length);
    for (int i = (A.length - 1); i >= 0; i--)
    {
        double temp = A.arr[i];
        A.arr[i] = A.arr[0];
        A.arr[0] = temp;
        A.heapSize -= 1;
        maxHeapify(A, 0);
        printArray(A.arr, A.length);
    }
}

int main()
{
    Array A;
    A.length = 10;
    A.heapSize = 8;
    A.arr = new double[A.length];

    A.arr[0] = 4;
    A.arr[1] = 1;
    A.arr[2] = 3;
    A.arr[3] = 2;
    A.arr[4] = 16;
    A.arr[5] = 9;
    A.arr[6] = 10;
    A.arr[7] = 14;
    A.arr[8] = 8;
    A.arr[9] = 7;

    printArray(A.arr, A.length);
    std::cout << std::endl;
    heapSort(A);
    std::cout << std::endl;
    printArray(A.arr, A.length);

    delete[] A.arr;
}
