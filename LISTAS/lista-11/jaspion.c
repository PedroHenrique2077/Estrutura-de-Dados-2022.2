#include <stdio.h>

typedef struct
{
    char palavra[81];
    char traducao[81];
} dicionario;

typedef struct
{
    char linha[81];
} letra;

int main(void)
{
    int t, m, n;

    scanf("%d", &t);
    scanf("%d %d", &m, &n);

    dicionario dic[m];
    letra linhas[n];

    for(int i = 0; i < m; i++)
    {
        scanf("%s", dic[i].palavra);
        scanf("%s", dic[i].traducao);
    }

    for(int i = 0; i < n; i++)
    {
        scanf("%s", linhas[i].linha);
    }

    


}