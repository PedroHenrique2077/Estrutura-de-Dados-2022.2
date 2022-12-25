#include <stdio.h>
#include <stdlib.h>

int *intercala(int *a, int la, int ra, int *b, int lb, int rb)
{
    int ta = (ra - la +1);
    int tb = (rb - lb +1);

    int *c = malloc((ta + tb) * sizeof(int));

    int lc = 0;
    int rc = (ta + tb - 1);

    int ia = la;
    int ib = lb;
    int ic = 0;

    while(ia<=ra && ib <= rb)
    {
        if(a[ia] < b[ib])
        {
            c[ic++] = a[ia++];
        }
        else{
            c[ic++] = b[ib++];
        }
    }

    while(ia<=ra)
    {
        c[ic++] = a[ia++];
    }
    while(ib<=rb)
    {
        c[ic++] = b[ib++];
    }

    return c;
}

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

void mergeSort(int *v, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        merge(v, l, m, r);
    }
}

int buscaBinaria(int *vetor, int tam, int n)
{
    int ini=0;
    int fim = tam-1;
    int meio;

    while (ini <= fim)
    {
        meio = (ini + fim)/2;

        if(n < vetor[meio])
        {
            fim = meio-1;
        } 
        else if(n > vetor[meio])
        {
            ini = meio+1;
        } 
        else return meio;

        return -1;
        
    }
}

int main(void)
{
    int v[200000];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    mergeSort(v, 0, n - 1);

    int novoi = 0;

    for(int i = 1; i < n; i++)
    {
        if(v[i] != v[novoi])
        {
            v[++novoi] = v[i];
        }
    }

    int novor = novoi;

    if(novor % 2 == 0)
    {
        v[++novor] = 1000000000;
    }

    int nmv[66000]; int nmvi = -1;

    for(int i = 0; i < novor; i +=2)
    {
        nmv[++nmvi] = v[i] + v[i + 1];
        if(buscaBinaria(v, novor, nmv[nmvi]) != -1)
        {
            nmvi--;
        }
    }

    int *c = intercala(v, 0, novor, nmv, 0, nmvi);

    for(int i = 0; i <= (novor + nmvi); i+= 4)
    {
        printf("%d\n", c[i]);
    }

    printf("Elementos: %d\n", novor + nmvi);

    return 0;
}