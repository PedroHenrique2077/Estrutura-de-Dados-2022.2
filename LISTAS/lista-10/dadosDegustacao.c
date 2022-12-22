#include <stdio.h>
#include <string.h>

typedef struct
{
    char carac;
    int tam;
    int pos;
} bebida;

void merge(bebida vetor[], int inicio, int fim, int meio)
{
    bebida *vetorAux = malloc(sizeof(bebida) * (fim - inicio + 1));

    int i = inicio, j = meio + 1, k = 0, p;

    while (i <= meio && j <= fim)
    {
        if (vetor[i].tam >= vetor[j].tam)
        {
            vetorAux[k++] = vetor[i++];
        }
        else
        {
            vetorAux[k++] = vetor[j++];
        }
    }

    while (i <= meio)
    {
        vetorAux[k++] = vetor[i++];
    }
    while (j <= fim)
    {
        vetorAux[k++] = vetor[j++];
    }

    k = 0;
    for (p = inicio; p <= fim; ++p)
    {
        vetor[p] = vetorAux[k++];
    }

    free(vetorAux);
}

void merge_sort(bebida vetor[], int inicio, int fim)
{
    if(inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio + 1, fim);
        merge(vetor, inicio, fim, meio);
    }
}

int main(void)
{
    bebida vetor[100000];
    char entrada[100001];
    int p = 0;
    scanf("%s", entrada);

    int tam = strlen(entrada);
    for (int i = 0; i < tam; i++)
    {

        vetor[p].carac = entrada[i];
        vetor[p].pos = i;

        while (entrada[i] == vetor[p].carac)
        {
            vetor[p].tam++;
            i++;
        }
        i--;
        p++;
    }

    merge_sort(vetor, 0, p);

    for (int j = 0; j < p; j++)
    {
        printf("%d %c %d\n", vetor[j].tam, vetor[j].carac, vetor[j].pos);
    }

    return 0;
}