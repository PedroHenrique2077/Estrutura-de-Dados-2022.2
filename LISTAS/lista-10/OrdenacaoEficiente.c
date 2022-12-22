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
    int n, i = 0;
    scanf("%d", &n);
    int vetor[n];

    while(i != n)
    {
        scanf("%d", &vetor[i]);
        i++;
    }
    i = 0;

    merge_sort(vetor, 0, n-1);

    while(i != n)
    {
        printf("%d ", vetor[i]);
        i++;
    }
    printf("\n");


    return 0;
}