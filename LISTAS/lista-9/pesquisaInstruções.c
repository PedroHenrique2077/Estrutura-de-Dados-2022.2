#include <stdio.h>

typedef struct
{
    int cod;
    char ins[16];
} Item;

void swap(Item *x, Item *y){ 
   Item temp;
   temp=*x;
   *x=*y;
   *y=temp;
}

char* buscaBinaria(Item *vetor, int tam, int n)
{
    int ini=0;
    int fim = tam-1;
    int meio;

    while (ini <= fim)
    {
        meio = (ini + fim)/2;
        if(n < vetor[meio].cod)
        {
            fim = meio-1;
        } else if(n > vetor[meio].cod)
        {
            ini = meio+1;
        } else return vetor[meio].ins;
    } return "undefined";
    
}

void selection_sort(Item A[], int n)
{
    int minimum;

    for (int i = 0; i < n - 1; i++)
    {
        minimum = i;

        for (int j = i + 1; j < n; j++)
        {
            if (A[j].cod < A[minimum].cod)
            {
                minimum = j;
            }
        }
        swap(&A[minimum], &A[i]);
    }
}

int main(void)
{
    int n, i = 0, entrada;
    scanf("%d", &n);
    Item vetor[n];

    while(i!=n)
    {
        scanf("%d %s", &vetor[i].cod, vetor[i].ins);
        i++;
    }

    selection_sort(vetor, n);

    while(scanf("%d", &entrada) != EOF)
    {
        printf("%s\n", buscaBinaria(vetor, n, entrada));
        entrada = 0;
    }

    return 0;
}

