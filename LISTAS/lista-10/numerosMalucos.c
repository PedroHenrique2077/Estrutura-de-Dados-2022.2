#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int particao(int *array, int size)
{
    int left = -1, right = size - 1;
    int pivot = array[right];
    while (1)
    {
        while (array[++left] < pivot)
            ;
        while (pivot < array[--right] && right > left)
            ;

        if (left >= right)
            break;
        swap(&array[left], &array[right]);
    }
    swap(&array[left], &array[size - 1]);
    return left;
}

int removeDup(int *array, int size)
{
    int unique_size = 1;
    for (int i = 1; i < size; i++)
        if (array[i] != array[unique_size - 1])
            array[unique_size++] = array[i];
    return unique_size;
}

void quickSort(int *v, int size)
{
    if (size < 2) return;

    if (v[size - 1] < v[(size - 1) / 2])
    {
        swap(&v[size - 1], &v[(size - 1) / 2]);
    }
    if (v[(size - 1) / 2] < v[0])
    {
        swap(&v[(size - 1) / 2], &v[0]);
    }
    if (v[(size - 1) / 2] < v[size - 1])
    {
        swap(&v[(size - 1) / 2], &v[size - 1]);
    }

    int d = particao(v, size);
    
    quickSort(v, d);
    quickSort(v + d + 1, size - d - 1);
}

void merge(int *a, int sizea, int *b, int sizeb)
{
    int *v2 = (int *)malloc((sizea + sizeb) * sizeof(int));
    int i = 0, j = 0, k = 0;
    for (; i < sizea && j < sizeb; k++)
    {
        if (a[i] <= b[j])
            v2[k] = a[i++];
        else
            v2[k] = b[j++];
    }

    while (i < sizea)
        v2[k++] = a[i++];
    while (j < sizeb)
        v2[k++] = b[j++];

    for (k = 0, i = 0; i < (sizea + sizeb); i++, k++)
        a[i] = v2[k];

    free(v2);
}

int main(void)
{
    int n;
    scanf(" %d", &n);

    int *v = (int *)malloc(sizeof(int) * (2 * n));

    for (int i = 0; i < n; i++)
    {
        scanf(" %d", v + i);
    }

    quickSort(v, n);

    int tam = removeDup(v, n);

    if (tam % 2)
        v[tam++] = 1000000000;

    int c = 0;

    for (int i = 0; i < tam - 1; i += 2)
    {
        v[tam + c++] = v[i] + v[i + 1];
    }

    merge(v, tam, v + tam, c);

    tam = removeDup(v, tam + c);

    for (int i = 0; i < tam; i += 4)
    {
        printf("%d\n", v[i]);
    }

    printf("Elementos: %d\n", tam);

    return 0;
}