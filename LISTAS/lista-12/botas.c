#include <stdio.h>
#include <stdlib.h>

// feito por mim
typedef struct botas_st
{
    int numero;
    char lado;
} botas_st;

int binarySearch(botas_st arr[], int l, int r, int x, char lado)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m].numero == x && arr[m].lado != lado)
            return m;
        if (arr[m].numero < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

void swap(botas_st *x, botas_st *y)
{
    botas_st temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(botas_st v[], int n)
{
    int minimum;

    for (int i = 0; i < n - 1; i++)
    {
        minimum = i;

        for (int j = i + 1; j < n; j++)
        {
            if (v[j].numero < v[minimum].numero)
            {
                minimum = j;
            }
        }
        swap(&v[minimum], &v[i]);
    }
}

int main(void)
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int output = 0;
        botas_st vetor[n];

        for (int i = 0; i < n; i++)
        {
            int numero;
            char lado;
            scanf("%d %c", &numero, &lado);
            vetor[i].numero = numero;
            vetor[i].lado = lado;
        }

        selection_sort(vetor, n);

        int m = sizeof(vetor) / sizeof(vetor[0]);

        for (int i = 0; i < n; i++)
        {
            if (vetor[i].numero != 0)
            {
                int mao = vetor[i].numero;
                vetor[i].numero = 0;

                int pos = binarySearch(vetor, 0, m - 1, mao, vetor[i].lado);

                if (pos != -1)
                {
                    output++;
                    vetor[pos].numero = 0;
                }
            }
        }

        printf("%d\n", output);
    }

    return 0;
}

int main(void)
{
    int n, i, j, pares = 0;
    char l;
    int direita[10001] = {0}, esquerda[10001] = {0};

    while (scanf("%d", &n) != EOF)
    {
        pares = 0;

        for (i = 0; i < n; i++)
        {
            int tamanho;
            scanf("%d %c", &tamanho, &l);
            if (l == 'D')
            {
                direita[tamanho]++;
            }
            else
            {
                esquerda[tamanho]++;
            }
        }

        for (i = 0; i < 10001; i++)
        {
            pares += direita[i] < esquerda[i] ? direita[i] : esquerda[i];
            direita[i] = esquerda[i] = 0;
        }

        printf("%d\n", pares);
    }

    return 0;
}
