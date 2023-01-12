#include <stdio.h>

void quickSort(int *v, int l, int r)
{
    int i, j, x, y;

    i = l;
    j = r;
    x = v[(l + r) / 2];

    while (i <= j)
    {
        while (v[i] < x && i < r)
        {
            i++;
        }
        while (v[j] > x && j > l)
        {
            j--;
        }
        if (i <= j)
        {
            y = v[i];
            v[i] = v[j];
            v[j] = y;
            i++;
            j--;
        }
    }

    if (j > l)
    {
        quickSort(v, l, j);
    }
    if (i < r)
    {
        quickSort(v, i, r);
    }
}

int main(void)
{
    int i = 0, l, n;

    scanf("%d", &n);

    int vetor[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    quickSort(vetor, 0, n - 1);

    for (l = 0; l < n; l++)
    {
        printf("%d ", vetor[l]);
    }
    printf("\n");
}