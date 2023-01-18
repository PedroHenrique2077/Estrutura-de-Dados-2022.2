#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct
{
    char japones[81];
    char portugues[81];
} Dic;

void buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int buscaBinaria(Dic *dicionario, int n, char *japones)
{
    int esq = 0;
    int dir = n - 1;

    while (esq <= dir)
    {
        int meio = (esq + dir) / 2;
        int cmp = strcmp(japones, dicionario[meio].japones);

        if (cmp < 0)
        {
            dir = meio - 1;
        }
        else if (cmp > 0)
        {
            esq = meio + 1;
        }
        else
        {
            return meio;
        }
    }

    return -1;
}

int compara(void *a, void *b) {
    return strcmp(((Dic *)a)->japones, ((Dic *)b)->japones);
}

void traduzFrase(Dic *dicionario, int n, char *frase) {
    char *palavra = strtok(frase, " ");
    while (palavra != NULL) {
        int pos = buscaBinaria(dicionario, n, palavra);
        if (pos >= 0) {
            printf("%s ", dicionario[pos].portugues);
        } else {
            printf("%s ", palavra);
        }
        palavra = strtok(NULL, " ");
    }
}

int main(void)
{
    int m, n, T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d %d", &m, &n);
        buffer();

        Dic dicionario[1000];

        for (int i = 0; i < m; i++)
        {
            scanf("%[^\n]", dicionario[i].japones); // Lê a string até encontrar um '\n'
            buffer();
            scanf("%[^\n]", dicionario[i].portugues); // Lê a string até encontrar um '\n'
            buffer();
        }

        qsort(dicionario, m, sizeof(Dic), compara);

        for (int j = 0; j < n; j++)
        {
            char frase[82];
            scanf("%[^\n]", frase); // Lê a string até encontrar um '\n'
            buffer();
            traduzFrase(dicionario, m, frase);
            putchar('\n');
        }
    }

    return 0;
}