#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", array[i]);
    }
}

void merge(int array[], int begin, int mid, int end)
{
    int length1 = mid - begin + 1;
    int length2 = end - mid;
    int left[length1 + 1], right[length2 + 1];
    for (int i = 0; i < length1; i++)
    {
        left[i] = array[begin + i - 1];
    }
    left[length1 + 1] = (int) INFINITY;
    for (int j = 0; j < length2; j++)
    {
        right[j] = array[mid + j];
    }
    right[length2 + 1] = (int) INFINITY;

    int i = 1, j = 1;
    for (int k = begin; k < end; k++)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
    }
}

void mergeSort(int array[], int begin, int end)
{
    if(begin < end) {
        int mid = (begin + end) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
    }
    printArray(array, end);
}

int main()
{
    int begin = 1, end = 5;
    int array[] = {5, 4, 3, 2, 1};

    mergeSort(array, begin, end);

    return 0;
}