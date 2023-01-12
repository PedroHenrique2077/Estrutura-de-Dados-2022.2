#include <stdio.h>

typedef struct
{
    int identificador;
    int votos;
} candidatos;

int urna[1000000];
int aux[1000000];

void remove_duplicates(int *vetor, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam;)
        {
            if (vetor[j] == vetor[i])
            {
                for (int k = j; k < tam; k++)
                    vetor[k] = vetor[k + 1];

                tam--;
            }
            else
            {
                j++;
            }
        }
    }
}

int main(void)
{
    int s, f, e, v, i = 0;

    scanf("%d %d %d", &s, &f, &e);

    while (scanf("%d", &v) != EOF)
    {
        urna[i] = v;
        aux[i] = v;
        i++;
    }

    remove_duplicates(aux, i - 1);

    for(int j = 0; j < i-1; j++)
    {
        printf("%d\n", aux[j]);
    }
}