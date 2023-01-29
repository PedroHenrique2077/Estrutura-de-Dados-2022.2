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

int pilhaVazia(pilha_st *pilha)
{
    return pilha->topo == 0;
}

int empilha(pilha_st *pilha, int valor)
{
    if (pilha->topo == pilha->capacidade)
        return 0;
    pilha->v[pilha->topo++] = valor;
    return 1;
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
    pilha->topo--;
    return 1;
}

int eh_balanceada(char *str)
{
    pilha_st P;
    int i, ok = 1;
    char par;
    int len = strlen(str);
    inicializar(&P, len);
    for (i = 0; ok && str[i] != '\0'; i++)
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

int main(void)
{
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++)
    {
        char str[100001];
        scanf("%s", str);
        if(eh_balanceada(str))
            printf("S\n");
        else
            printf("N\n");
    }

    return 0;
}