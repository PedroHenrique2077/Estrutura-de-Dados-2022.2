#include <stdio.h>
#include <stdlib.h> // srand()
#include <time.h>

typedef struct Item {
    int l, c;
} Item;

struct fila_st
{
    Item *v;
    int size;
    int inicio;
    int fim;
    int ocupados
};

struct cel_st
{
    char valor;
    char status;
};

void inicializaFila(struct fila_st *f, int size)
{
    f->v = (Item *) malloc(size * sizeof(Item));
    f->size = size;
    f->inicio = 0;
    f->fim = 0;
    f->ocupados = 0;
    return 1;
}

int enfila(struct fila_st *f, Item e)
{
    if(f->ocupados>=f->size) return 0;

   f->v[(f->inicio+1)%f->size] = e;
   f->inicio = (f->inicio+1)%f->size;
   f->ocupados++;
   return 1;
}

void desenfila(struct fila_st *f)
{
    f->ocupados--;
    f->inicio = (f->inicio+1)%f->size;
}

Item espia(struct fila_st *f)
{
    return f->v[(f->inicio+1) % f->size];
}

int esta_vazia(struct fila_st *f)
{
    return f->ocupados == 0;
}

#define N 10
#define posValida(A, B) (A >= 0 && A < N && B >= 0 && B < N)
struct cel_st campo[N][N];

void inicializaCampo()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            campo[i][j] = (struct cel_st) {'\0', '\0'};
}

void imprimeCampo()
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(campo[i][j].status <= 0)
                printf("#");
            else {
                printf("%c", campo[i][j].valor);
            }
        printf("\n");
}

#define MAXBOMBS 20
void firstClick(int l, int c)
{
    campo[l][c].status = 1;
    srand(time(NULL));
    for(int b = 0; b < MAXBOMBS; b++)
    {
        int pl = rand() % N;
        int pc = rand() % N;
        while(campo[pl][pc].status != 0 || campo[pl][pc].valor == 9)
        {
            pl = rand() % N;
            pc = rand() % N;
        }

        campo[pl][pc].valor = 9;
        for(int i = pl-1; i < pl+2; i++)
            for(int j = pc-1; j < pc+2; j++)
            {
                if(!posValida(i, j)) continue;
                if(campo[i][j].valor == 9) continue;
                campo[i][j].valor++;
            }
    }
}

void abreClick(int l, int c)
{
    struct fila_st f;
    inicializaFila(&f, N*N);
    Item e;
    e.l = l;
    e.c = c;
    if(campo[l][c].valor > 0){
        campo[l][c].status = 1;
        imprimeCampo();
        return;
    }
    enfila(&f, e);

    while(!esta_vazia(&f)){
        e = espia(&f);
        campo[e.l][e.c].status = 1;
        imprimeCampo();
        desenfila(&f);
        for(int i = e.l-1; i<e.l+2; i++)
            for(int j = e.c-1; j<e.c+2; j++)
            {
                if(!posValida(i, j)) continue;
                if(campo[i][j].status == 0 && campo[i][j].valor == 0){
                    campo[i][j].status = -1;
                    Item xx;
                    xx.l = i;
                    xx.c = j;
                    enfila(&f, xx);
                }
            }
    }
}

int main(void)
{
    inicializaCampo();
    imprimeCampo();
    int l, c;
    scanf("%d %d", &l, &c);
    firstClick(l, c);
    abreClick(l, c);
    while(scanf("%d %d", &l, &c) == 2){
        if(!posValida(l, c)){
            printf("Coloque no lugar certo, seu burro!\n");
        }
    }
    imprimeCampo();
    printf("\n\n"); 
    return 0;
}