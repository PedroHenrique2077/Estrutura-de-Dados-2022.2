#include <stdio.h>

int vetor[1000];

void bubble_sort(int A[], int n)
{
    int temp;
    for (int k = 0; k < n - 1; k++)
    {
        for (int i = 0; i < n - k - 1; i++)
        {
            if (A[i] > A[i + 1])
            {
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
            }
        }
    }
}

int main(void)
{
    int i = 0, l;

    while(scanf("%d", &vetor[i]) != EOF)
    {
        i++;
    }

    bubble_sort(vetor, i);

    for (l = 0; l < i; l++)
    {
        printf("%d ", vetor[l]);
    }
    printf("\n");

}