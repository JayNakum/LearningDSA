#include <iostream>

int binarySearch(double *A, double search, int p, int r)
{
    int pos = -1;
    if (r >= p)
    {
        int q = p + (r - p) / 2;
        if (A[q] == search)
        {
            pos = q;
        }
        else if (search < A[q])
        {
            return binarySearch(A, search, p, q - 1);
        }
        else
        {
            return binarySearch(A, search, q + 1, r);
        }
    }
    return pos;
}

int main()
{
    double A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int arr_size = sizeof(A) / sizeof(A[0]);
    int pos = binarySearch(A, 6, 0, arr_size - 1);
    std::cout << "Element found at position " << pos << std::endl;
}