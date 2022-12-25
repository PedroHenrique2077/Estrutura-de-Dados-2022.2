#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int l, int m, int r)
{
    int *v2 = malloc((r - l + 1) * sizeof(int));
    int i = l;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= r)
    {
        if (v[i] <= v[j])
        {
            v2[k++] = v[i++];
        }
        else
        {
            v2[k++] = v[j++];
        }
    }

    while (i <= m)
    {
        v2[k++] = v[i++];
    }
    while (j <= r)
    {
        v2[k++] = v[j++];
    }

    k = 0;
    for (int p = l; p <= r; ++p)
    {
        v[p] = v2[k++];
    }
}

int main(void)
{

    int entrada, tam = 0, vetor[1600006];

    for (int i = 0; i < 8; ++i)
    {
        scanf("%d", &entrada);
        if (entrada == 0)
            continue;
        for (int j = 0; j < entrada; ++j)
            scanf("%d", &vetor[tam + j]);
        merge(&vetor[0], 0, tam - 1, tam + entrada - 1);
        tam += entrada;
    }

    printf("%d", vetor[0]);

    for (int i = 1; i < tam; ++i)
    {
        printf(" %d", vetor[i]);
    }

    printf("\n");

    return 0;
}