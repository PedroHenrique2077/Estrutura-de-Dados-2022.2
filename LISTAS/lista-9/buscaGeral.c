#include <stdio.h>

typedef struct
{
    int pos;
    int elem;
} Item;

void swap(Item *x, Item *y){ 
   Item temp;
   temp=*x;
   *x=*y;
   *y=temp;
}

int buscaBinaria(Item *vetor, int tam, int n)
{
    int ini=0;
    int fim = tam-1;
    int meio;

    while (ini <= fim)
    {
        meio = (ini + fim)/2;
        if(n < vetor[meio].elem)
        {
            fim = meio-1;
        } else if(n > vetor[meio].elem)
        {
            ini = meio+1;
        } else return vetor[meio].pos;
    } return -1;
    
}

void selection_sort(Item A[], int n)
{
    int minimum;

    for (int i = 0; i < n - 1; i++)
    {
        minimum = i;

        for (int j = i + 1; j < n; j++)
        {
            if (A[j].elem < A[minimum].elem)
            {
                minimum = j;
            }
        }
        swap(&A[minimum], &A[i]);
    }
}


int main(void)
{
    int N, M, i = 0, meio;
    scanf("%d %d", &N, &M);

    Item vetor1[N];
    int vetor2[M];

    while(i != N)
    {
        scanf("%d", &vetor1[i].elem);
        vetor1[i].pos = i;
        i++;
    }
    i = 0;
    while(i != M)
    {
        scanf("%d", &vetor2[i]);
        i++;
    }

    selection_sort(vetor1, N);


    for(int j = 0; j<M; j++)
    {
        printf("%d\n", buscaBinaria(vetor1, N, vetor2[j]));
    }
    return 0;
}