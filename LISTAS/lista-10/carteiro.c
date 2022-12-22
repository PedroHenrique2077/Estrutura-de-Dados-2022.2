#include <stdio.h>

int main(void)
{
    int n, m,tempo = 0, j = 0;

    scanf("%d %d", &n, &m);

    int vetor[n];
    int vetor1[m];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &vetor1[i]);
    }

    for (int i = 0; i < m; i++)
    {
        int encomenda = vetor1[i];
        int posicao = vetor[j];
        if(posicao < encomenda)
        {
            while(posicao < encomenda)
            {
                j++;
                posicao = vetor[j];
                tempo++;
            }
        }
        if(posicao > encomenda)
        {
            while(posicao > encomenda)
            {
                j--;
                posicao = vetor[j];
                tempo++;
            }
        }
    }
    printf("%d\n", tempo);
}