#include <stdio.h>

int vetor[1000];

void swap(int *x, int *y){ 
   int temp;
   temp=*x;
   *x=*y;
   *y=temp;
}

void selection_sort(int A[], int n)
{
    int minimum;

    for (int i = 0; i < n - 1; i++)
    {
        minimum = i;

        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[minimum])
            {
                minimum = j;
            }
        }
        swap(&A[minimum], &A[i]);
    }
}

int main(void)
{
    int i = 0, l;

    while(scanf("%d", &vetor[i]) != EOF)
    {
        i++;
    }

    selection_sort(vetor, i);

    for (l = 0; l < i; l++)
    {
        printf("%d ", vetor[l]);
    }
    printf("\n");

}