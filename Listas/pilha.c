#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha_st
{
    int topo;
    int capacidade;
    int *v;
} pilha_st;

int inicializar(pilha_st *pilha, int capacidade)
{
    pilha->v = (int *)malloc(capacidade * sizeof(int));
    if (pilha->v == NULL)
        return 0;
    pilha->topo = 0;
    pilha->capacidade = capacidade;
    return 1;
}

int empilha(pilha_st *pilha, int valor)
{
    if (pilha->topo == pilha->capacidade)
        return 0;
    pilha->v[pilha->topo++] = valor;
    return 1;
}

int pilhaVazia(pilha_st *pilha)
{
    return pilha->topo == 0;
}

int topo(pilha_st *pilha)
{
    if (pilhaVazia(pilha))
        return 0;
    return pilha->v[pilha->topo - 1];
}

int desempilha(pilha_st *pilha)
{
    if (pilhaVazia(pilha))
        return 0;
    int aux = pilha->v[pilha->topo-1];    
    pilha->topo--;
    return aux;
}

void imprime_pilha_ao_contrario(pilha_st *p) {
    pilha_st temp;
    inicializar(&temp, p->capacidade);
    while(!pilhaVazia(p)) {
        int aux = desempilha(p);
        printf("%d ", aux);
        empilha(&temp, aux);
    }
    while(!pilhaVazia(&temp)) {
        empilha(p, desempilha(&temp));
    }
}

void imprime_pilha_em_ordem_recursiva(pilha_st *p) {
    if(!pilhaVazia(p)) {
        int aux = desempilha(p);
        imprime_pilha_em_ordem_recursiva(p);
        printf("%d ", aux);
        empilha(p, aux);
    }
}


int main(void)
{
    pilha_st P;
    inicializar(&P, 5);
    empilha(&P, 1);
    empilha(&P, 2);
    empilha(&P, 3);
    empilha(&P, 4);
    empilha(&P, 5);
    imprime_pilha_ao_contrario(&P);
    printf("\n");
    imprime_pilha_em_ordem_recursiva(&P);

    return 0;
}

// Exercicio dos parenteses

int eh_balanceada(char *str)
{
    pilha_st P;
    int ok = 1;
    char par;
    int len = strlen(str);
    inicializar(&P, len);
    for (int i = 0; ok && str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            empilha(&P, str[i]);
        else
        {
            par = topo(&P);
            desempilha(&P);
            if (str[i] == ']' && par != '[')
                ok = 0;
            else if (str[i] == '}' && par != '{')
                ok = 0;
            else if (str[i] == ')' && par != '(')
                ok = 0;
        }
    }
    if (!pilhaVazia(&P))
        ok = 0;

    return ok;
}

//________________________________________________________________________

// pilha com lista encadeada

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

struct Stack *create_stack()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

void push(struct Stack *stack, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(struct Stack *stack)
{
    if (stack->top == NULL)
        return -1;
    int data = stack->top->data;
    struct Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

int peek(struct Stack *stack)
{
    if (stack->top == NULL)
        return -1;
    return stack->top->data;
}

int is_empty(struct Stack *stack)
{
    return (stack->top == NULL);
}
