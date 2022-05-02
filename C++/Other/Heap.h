#pragma once

#include <math.h>

static int PARENT(int i)
{
    return floor(i / 2);
}

static int LEFT(int i)
{
    return (2 * i);
}

static int RIGHT(int i)
{
    return ((2 * i) + 1);
}

class MinHeap
{
public:
    int size;

public:
    MinHeap(int &heapSize)
        : size(heapSize) {}

public:
    void minHeapify(int *arr, int i) const
    {
        int l = LEFT(i);
        int r = RIGHT(i);

        int smallest = i;

        if (l < size && arr[l] < arr[i])
            smallest = l;

        else
            smallest = i;

        if (r < size && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != i)
        {
            int temp = arr[smallest];
            arr[smallest] = arr[i];
            arr[i] = temp;

            minHeapify(arr, smallest);
        }
    }

    void buildMinHeap(int *arr, int length)
    {
        size = length;
        for (int i = floor(length / 2); i >= 0; i--)
        {
            minHeapify(arr, i);
        }
    }

    int extractMin(int *arr)
    {
        if (size >= 0)
        {
            int min = arr[0];
            size -= 1;
            arr[0] = arr[size];
            minHeapify(arr, 0);
            return min;
        }
        else
        {
            return -1;
        }
    }
};

class MaxHeap
{
public:
    int size;

public:
    MaxHeap(int &heapSize)
        : size(heapSize) {}

public:
    void maxHeapify(int *arr, int i) const
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

        if (largest != i)
        {
            int temp = arr[largest];
            arr[largest] = arr[i];
            arr[i] = temp;

            maxHeapify(arr, largest);
        }
    }

    void buildMaxHeap(int *arr, int length)
    {
        size = length;
        for (int i = floor(length / 2); i >= 0; i--)
        {
            maxHeapify(arr, i);
        }
    }

    int extractMax(int *arr)
    {
        if (size >= 0)
        {
            int max = arr[0];
            size -= 1;
            arr[0] = arr[size];
            maxHeapify(arr, 0);
            return max;
        }
        else
        {
            return -1;
        }
    }
};