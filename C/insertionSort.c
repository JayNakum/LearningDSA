#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int n) {
    for(int i = 0; i<n; i++) {
        printf("%d, ", array[i]);
    }
}

void insertion(int array[], int n)
{
    int i, j;
    int key;
    for (j = 1; j <= n; j++)
    {
        key = array[j];
        i = j - 1;
        while (i >= 0 && array[i] > key)
        {
            array[i + 1] = array[i];
            i = i - 1;
            array[i + 1] = key;
        }
    }
    printArray(array, n);
}


int main() {
    int n = 5;
    int array[] = {5, 4, 3, 2, 1};
    insertion(array, n);
    return 0;
}