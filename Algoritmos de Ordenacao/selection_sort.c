#include <stdio.h>

typedef int Item;

void swap(int *x, int *y){ 
   int temp;
   temp=*x;
   *x=*y;
   *y=temp;
}

void selection_sort(int A[], int n)
{
    // temporary variable to store the position of minimum element

    int minimum;
    // reduces the effective size of the array by one in  each iteration.

    for (int i = 0; i < n - 1; i++)
    {

        // assuming the first element to be the minimum of the unsorted array .
        minimum = i;

        // gives the effective size of the unsorted  array .

        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[minimum])
            { // finds the minimum element
                minimum = j;
            }
        }
        // putting minimum element on its proper position.
        swap(A[minimum], A[i]);
    }
}