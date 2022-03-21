#include <stdio.h>
#include <stdlib.h>

int partition(int a[], int p, int r)
{
    int x, j, i, t;
    x = a[r];
    i = p - 1;
    for (j = p; p < r; j++)
    {
        if (a[j] <= x)
        {
            i = i + 1;

            t = a[i];
            a[i] = a[j];
            a[j] = t;
        
        }
        
        t = a[i + 1];
        a[i + 1] = a[r];
        a[r] = t;
        
        return a[i + 1];
    }
}
void quicksort(int a[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}
void main()
{
    int a[] = {3, 2, 4, 5, 1, 0};
    quicksort(a, 0, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d", a[i]);
    }
}
