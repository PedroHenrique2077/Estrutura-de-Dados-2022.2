#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    char *timeA, *timeB;
    int rodadas, i, saida = 0, pontosA = 0, pontosB = 0, chancesA, chancesB;

    scanf("%d", &rodadas);
    timeA = malloc((rodadas * sizeof(char)) + 1);
    timeB = malloc((rodadas * sizeof(char)) + 1);
    chancesA = rodadas;
    chancesB = rodadas;
    scanf(" %s", timeA);
    scanf(" %s", timeB);

    for (i = 0; i < rodadas; i++)
    {
        saida++;
        if (timeA[i] == 'o')
        {
            pontosA++;
        }
        chancesA--;
        if (pontosA + chancesA < pontosB || pontosB + chancesB < pontosA)
        {
            break;
        }

        saida++;
        if (timeB[i] == 'o')
        {
            pontosB++;
        }
        chancesB--;
        if (pontosA + chancesA < pontosB || pontosB + chancesB < pontosA)
        {
            break;
        }
    }

    if (pontosA == pontosB)
    {
        printf("Empate\n");
    }
    else
    {
        printf("%d\n", saida);
    }

    return 0;
}