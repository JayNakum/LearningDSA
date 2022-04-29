#include <iostream>
#include <math.h>

void merge(int A[], int p, int q, int r)
{
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = p + (r - p) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int A[] = {5, 4, 3, 2, 1, 0};
    int arr_size = sizeof(A) / sizeof(A[0]);
    printArray(A, arr_size);
    mergeSort(A, 0, arr_size - 1);
    printArray(A, arr_size);
}