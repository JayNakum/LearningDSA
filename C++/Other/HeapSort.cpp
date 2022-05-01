#include <iostream>
#include "Heap.h"

void printArray(int *arr, const int &n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void heapSort(int *arr, const int &length, MaxHeap &heap)
{
    heap.buildMaxHeap(arr, length);
    std::cout << "Heap: ";
    printArray(arr, length);
    for (int i = (length - 1); i >= 0; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heap.size -= 1;
        heap.maxHeapify(arr, 0);
        // printArray(arr, length);
    }
}

int main()
{
    int heapSize = 8;
    MaxHeap heap(heapSize);
    int length = 9;
    int arr1[] = {4, 1, 3, 2, 16, 9, 10, 8, 7};
    std::cout << "Input: ";
    printArray(arr1, length);
    heapSort(arr1, length, heap);
    std::cout << "Sorted: ";
    printArray(arr1, length);
}
