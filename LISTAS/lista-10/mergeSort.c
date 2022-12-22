#include <stdio.h>

void merge(int A[], int start, int mid, int end)
{
    int p = start, q = mid + 1;

    int Arr[end - start + 1], k = 0;

    for (int i = start; i <= end; i++)
    {
        if (p > mid)
            Arr[k++] = A[q++];

        else if (q > end)
            Arr[k++] = A[p++];

        else if (A[p] < A[q])
            Arr[k++] = A[p++];

        else
            Arr[k++] = A[q++];
    }
    for (int p = 0; p < k; p++)
    {
        A[start++] = Arr[p];
    }
}

void merge_sort(int A[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(A, start, mid);
        merge_sort(A, mid + 1, end);

        merge(A, start, mid, end);
    }
}

int main(void)
{
    int vetor[100000], i = 0;

    while(scanf("%d", &vetor[i]) != EOF)
    {
        i++;
    }

    merge_sort(vetor, 0, i-1);

    for(int j = 0; j < i; j++)
    {
        printf("%d ", vetor[j]);
    }
    printf("\n");

    return 0;
}