/** Time Complexity
 *  Worst Case: O(n^2)
 *  Average Case: O(n^2)
 *  Best Case: O(n)
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

void bubbleSort(double *A, int n)
{
    double temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - 1); j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main()
{
    double A[] = {5, 4, 3, 2, 1, 0};
    int n = sizeof(A) / sizeof(A[0]);
    printArray(A, n);
    bubbleSort(A, n);
    printArray(A, n);
}
