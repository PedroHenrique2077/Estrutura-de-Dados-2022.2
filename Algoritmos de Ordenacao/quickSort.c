#include <stdio.h>

// não é um algoritmo estável
// em geral, melhor que o mergeSort
// seu melhor caso (NlogN)
// seu pior caso é um vetor decrescente O(N²), em seu pior caso, com um vetor muito grande é possivel que ocorra segmentation fault por causa da função usar muitas variaveis.
// o melhor pivor para o quickSort é o elemento mediano de 3 pontos (o inicio, fim e do meio)

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void insertionSort(int *v, int l, int r)
{
    int i, j, x;

    for(i = l+1; i <= r; i++)
    {
        x = v[i];
        for(j = i-1; j >= l && v[j] > x; j--)
            v[j+1] = v[j];
        v[j+1] = x;
    }
}

int separa(int *v, int l, int r)
{
    int p = v[r];
    int i = l-1;
    int j = r;

    for(;;)
    {
        while(v[++i] < p);
        while(p < v[--j]) if(j == l) break;
        if(j <= i) break;
        swap(&v[i], &v[j]);
    }
    swap(&v[i], &v[r]);

    return i;
}

void quickSortA1(int *v, int l, int r)
{
    if(r <= l) return;

    int j = separa(v,l,r);

    quickSort(v, l, j-1);
    quickSort(v, j+1, r);
}

void quickSortM3(int *v, int l, int r)
{
    if(r-l+1 <= 16) return;

    swap(&v[(l+r)/2], &v[r-1]);
    if(v[l] < v[r]) swap(&v[l], &v[r]);
    if(v[l] < v[r-1]) swap(&v[l], &v[r-1]);
    if(v[r-1] < v[r]) swap(&v[r-1], &v[r]);

    int j = separa(v,l+1,r-1);
    quickSortM3(v, l, j-1);
    quickSortM3(v, j+1, r);
}

// versão do quickSort que usa insertionSort para vetores pequenos
void quickSort(int *v, int l, int r)
{
   quickSortM3(v, l, r);
   insertionSort(v, l, r);
}


int main(void)
{
    int t[5] = {3, 5, 9, 4, 1};
    int b[5] = {1, 2, 3, 4, 5};

    printf("%d\n", separa(t, 0, 4));

    return 0;
}
