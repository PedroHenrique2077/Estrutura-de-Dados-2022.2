#include <stdio.h>

int vetor[50000];

void insertion_sort(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = A[i];
        int j = i;

        while (j > 0 && temp < A[j - 1])
        {
            A[j] = A[j - 1];
            j = j - 1;
        }

        A[j] = temp;
    }
}

int main(void)
{
    int i = 0, l;

    while(scanf("%d", &vetor[i]) != EOF)
    {
        i++;
    }

    insertion_sort(vetor, i);

    for (l = 0; l < i; l++)
    {
        printf("%d ", vetor[l]);
    }
    printf("\n");
}