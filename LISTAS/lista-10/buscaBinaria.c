#include <stdio.h>

int buscaBinaria(int *vetor, int tam, int n)
{
    int ini = 0;
    int fim = tam - 1;
    int meio;

    while (ini <= fim)
    {
        meio = (ini + fim) / 2;
        if (n < vetor[meio])
        {
            fim = meio - 1;
        }
        else if (n > vetor[meio])
        {
            ini = meio + 1;
        }
        if(vetor[meio] == n)
        {
            return meio;
        }
    }

    if (vetor[meio] != n)
    {
        if (vetor[meio] > n)
        {
            return meio;
        }
        else
        {
            return meio + 1;
        }
    }
}

int main(void)
{
    int n, m;

    scanf("%d %d", &n, &m);

    int vetor[n], vetor2[m];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &vetor2[i]);
    }

    for(int j = 0; j < m; j++)
    {
        printf("%d\n", buscaBinaria(vetor, n, vetor2[j]));
    }
}