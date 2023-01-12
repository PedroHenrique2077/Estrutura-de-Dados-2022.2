#include <stdio.h>

struct filast
{
    int *v;
    int size;
    int inicio,fim;
    int ocupados;
};

int inicializaFila(struct filast *fila, int s)
 {
    fila-> size = s;
    fila-> v = malloc(s * sizeof(int));
    if(fila-> v == NULL) return 0;
    fila-> ocupados = 0;
    fila-> inicio = 1;
    fila-> fim = 0;
    return 1;
 }

int enfila(struct filast *f, int e)
 {
    if(f -> fim == f -> inicio) return 0;
    f -> v[f -> fim++] = e;
    f -> fim = f -> fim % f -> size;
    f -> ocupados++;
    return 1;
 }

void desenfila(struct filast *f)
{
    f -> ocupados--;
    f -> inicio = (f -> inicio + 1) % f -> size;
}

int estaVazia(struct filast *f)
{
    return f -> ocupados == 0;
}

int espia(struct filast *f)
{
    return f -> v[(f -> inicio + 1) / f -> size];
}