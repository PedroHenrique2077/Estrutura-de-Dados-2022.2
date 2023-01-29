#include <stdio.h>

typedef struct no_st{
    int valor;
    no_st *anterior;
    no_st *prox;
} no_st;

typedef struct header{
    no_st *inicio;
    no_st *fim;
    int no_count;
} header;

int inicializaLista(header *h){
    h->inicio = NULL;
    h->fim = NULL;
    h->no_count = 0;
    return 1;
}

int insereInicio(header *h, int valor){
    no_st *novo = malloc(sizeof(no_st));
    if(novo == NULL) return 0;
    novo->valor = valor;
    novo->prox = h->inicio;
    h->inicio = novo;
    h->no_count++;
    return 1;
}

int insereDepois(no_st *no, int valor){
    no_st *novo = malloc(sizeof(no_st));
    if(novo == NULL) return 0;
    novo->valor = valor;
    novo->prox = no->prox;
    no->prox = novo;
    return 1;
}

int insereDepoisOuFim(header *h, int valor, int pos){
    int i = 0;
    no_st *aux = h->inicio;
    if(aux == NULL) return 0;
    while(i < pos && aux->prox != NULL){
        aux = aux->prox;
        i++;
    }

    if(insereDepois(aux, valor) == 0) return 0;
    h->no_count++;
    return 1;
}

int removeInicio(header *h){
    if(h->inicio == NULL) return 0;
    no_st *toRemove = h->inicio;
    h->inicio = h->inicio->prox;
    int ret = toRemove->valor;
    free(toRemove);
    h->no_count--;
    return ret;
}

#define equal(a, b) (a == b)

int buscaLista(header *h, int b){
    no_st *aux = h->inicio;
    int i = 0;
    while(aux != NULL && !equal(aux->valor, b)){
        aux = aux->prox;
        i++;
    }
    if(aux == NULL) return -1;
    return aux->valor;
}

no_st * busca_lista(header *h, int b){
    no_st *aux = h-> inicio;
    while(aux != NULL && !equal(b, aux->valor))
    {
        aux = aux->prox;
    }
    return aux;
}

int insere_depois_de_item(header *h, int c, int e){
    no_st *a = busca_lista(h, c);
    if(a == NULL) return 0;
    return insereDepois(a, e);
}

void removeElemento(header *h, no_st *r)
{
    if(r == h->inicio){
        removeInicio(h);
        return;
    }

    no_st *aux = h->inicio;
    while (aux->prox != r) aux = aux->prox;

    free(r);
}


//________________________________________________________

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// inverte as posições de uma lista duplamente encadeada
void reverseList(Node** head) {
    Node* current = *head;
    Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *head = temp->prev;
    }
}

// inverte as posições de uma lista encadeada

// Neste exemplo, a função "reverse" recebe como parâmetro o endereço do ponteiro para o
// início da lista. A lista é percorrida e os ponteiros de próximo de cada nó são alterados para
// apontar para o nó anterior, fazendo com que a lista seja invertida.
void reverse(struct Node** head_ref) {
    struct Node* previous = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *head_ref = previous;
}
