/** Time Complexity
 *  Worst Case: O(n^2)
 *  Average Case: O(n^2)
 *  Best Case: O(n^2)
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

void selectionSort(double *A, int n)
{
    int min;
    double temp;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            temp = A[min];
            A[min] = A[i];
            A[i] = temp;
        }
    }
}

int main()
{
    double A[] = {5, 4, 3, 2, 1, 0};
    int n = sizeof(A) / sizeof(A[0]);
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);
}
