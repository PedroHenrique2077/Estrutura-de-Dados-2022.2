#include <stdio.h>



struct pilhaSt {
    int topo;
    int capacidade;
    int *v;
};

int inicializar(struct pilhaSt *pilha, int capacidade) {
    pilha->v = (int *) malloc(capacidade * sizeof(int));
    if(pilha->v == NULL) return 0;
    pilha->topo = 0;
    pilha->capacidade = capacidade;
    return 1;
}

int empilha(struct pilhaSt *pilha, int valor) {
    if(pilha->topo == pilha->capacidade) return 0;
    pilha->v[pilha->topo++] = valor;
    return 1;
}

int pilhaVazia(struct pilhaSt *pilha) {
    return pilha->topo == 0;
}

int topo(struct pilhaSt *pilha) {
    if(pilhaVazia(pilha)) return 0;
    return pilha->v[pilha->topo - 1];
}

int desempilha(struct pilhaSt *pilha) {
    if(pilhaVazia(pilha)) return 0;
    pilha->topo--;
    return 1;
}

void imprimePilhaAoContrario(struct pilhaSt *f)
{
    struct pilhaSt p;
    inicializar(&p, 1000);
    while(!pilhaVazia(f)) {
        empilha(&p, desenfila(f));
        desempilha(f);
    }
    while(!pilhaVazia(&p)) {
        printf("%d ", topo(&p));
        desempilha(&p);
    }

}
