#include <stdio.h>
#include <stdlib.h>

typedef struct fila_st {
    int elementos[100];
    int inicio, fim;
}fila_st;

int esta_vazia(fila_st *f) {
    return f->inicio == f->fim;
}

void enfilera(fila_st *f, int novo) {
    f->elementos[f->fim++] = novo;
}

int desenfilera(fila_st *f) {
    if(esta_vazia(f)) {
        printf("Fila vazia\n");
        return -1;
    }
    return f->elementos[f->inicio++];
}

void imprime_fila_ao_contrario(fila_st *f) {
    int aux = desenfilera(f);
    if(!esta_vazia(f)) {
        imprime_fila_ao_contrario(f);
    }
    printf("%d ", aux);
    enfilera(f, aux);
}

void imprime_fila(fila_st *f) {
    int aux = desenfilera(f);
    printf("%d ", aux);
    if(!esta_vazia(f)) {
        imprime_fila(f);
    }
    enfilera(f, aux);
}

//__________________________________________________________________
// fila implementada com lista encadeada

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void enqueue(struct Queue* q, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return 0;
    }
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}