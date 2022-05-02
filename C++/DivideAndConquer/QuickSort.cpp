/** Time Complexity
 *  Worst Case: O(n^2)
 *  Average Case: O(n log n)
 *  Best Case: O(n log n)
 */

#include <iostream>

void printArray(double *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int partition(double *A, int p, int r)
{
    double temp;
    double x = A[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (A[j] <= x)
        {
            i += 1;
            temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }
    temp = A[r];
    A[r] = A[i + 1];
    A[i + 1] = temp;

    return i + 1;
}

void quickSort(double *A, int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main()
{
    double A[] = {2, 8, 7, 1, 3, 5, 6, 4};
    int arr_size = sizeof(A) / sizeof(A[0]);
    printArray(A, arr_size);
    quickSort(A, 0, arr_size - 1);
    printArray(A, arr_size);
}
