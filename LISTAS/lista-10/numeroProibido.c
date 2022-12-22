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

int buscaBinaria(int *vetor, int tam, int n)
{
    int ini=0;
    int fim = tam-1;
    int meio;

    while (ini <= fim)
    {
        meio = (ini + fim)/2;
        if(n < vetor[meio])
        {
            fim = meio-1;
        } else if(n > vetor[meio])
        {
            ini = meio+1;
        } else return meio;
    } return -1;
    
}

int main(void)
{
    int n, i = 0, entrada;
    scanf("%d", &n);
    int vetor[n];

    while(i < n)
    {
        scanf("%d", &vetor[i]);
        i++;
    }

    merge_sort(vetor, 0, n-1);

    while(scanf("%d", &entrada) != EOF)
    {
        if(buscaBinaria(vetor, n, entrada) != -1)
        {
            printf("sim\n");
        }
        else
        {
            printf("nao\n");
        }
    }

    return 0;
}