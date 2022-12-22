#include <stdio.h>

char times[16] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};

char timesDasQuartas[9];

char timesDasSemis[5];

char timesDaFinal[3];

char timeVencedor[1];

void alocaTimesDasQuartas(int oitavas[16])
{
    int aux = 0;
    for (int i = 0; i < 16; i += 2)
    {
        if(oitavas[i] > oitavas[i+1])
        {
            timesDasQuartas[aux] = times[i];
            aux++;
        }
        else 
        {
            timesDasQuartas[aux] = times[i+1];
            aux++;
        }
    }
}

void alocaTimesDaSemi(int quartas[8])
{
    int aux = 0;
    for (int i = 0; i < 8; i += 2)
    {
        if(quartas[i] > quartas[i+1])
        {
            timesDasSemis[aux] = timesDasQuartas[i];
            aux++;
        }
        else 
        {
            timesDasSemis[aux] = timesDasQuartas[i+1];
            aux++;
        }
    }
}

void alocaTimesDaFinal(int semi[4])
{
    int aux = 0;
    for (int i = 0; i < 4; i += 2)
    {
        if(semi[i] > semi[i+1])
        {
            timesDaFinal[aux] = timesDasSemis[i];
            aux++;
        }
        else 
        {
            timesDaFinal[aux] = timesDasSemis[i+1];
            aux++;
        }
    }
}

void vencedor(int final[2])
{
    int aux=0;
    for (int i = 0; i < 2; i += 2)
    {
        if(final[i] > final[i+1])
        {
            timeVencedor[0] = timesDaFinal[aux];
        }
        else 
        {
            timeVencedor[0] = timesDaFinal[aux+1];
        }
    }
}

int main(void)
{
    int oitavas[16];

    for (int i = 0; i < 16; i += 2)
    {
        int aux1;
        int aux2;
        scanf("%d %d", &aux1, &aux2);
        oitavas[i] = aux1;
        oitavas[i + 1] = aux2;
    }

    int quartas[8];

    for (int i = 0; i < 8; i += 2)
    {
        int aux1;
        int aux2;
        scanf("%d %d", &aux1, &aux2);
        quartas[i] = aux1;
        quartas[i + 1] = aux2;
    }

    int semi[4];

    for (int i = 0; i < 4; i += 2)
    {
        int aux1;
        int aux2;
        scanf("%d %d", &aux1, &aux2);
        semi[i] = aux1;
        semi[i + 1] = aux2;
    }

    int final[2];

    for (int i = 0; i < 2; i += 2)
    {
        int aux1;
        int aux2;
        scanf("%d %d", &aux1, &aux2);
        final[i] = aux1;
        final[i + 1] = aux2;
    }

    alocaTimesDasQuartas(oitavas);
    alocaTimesDaSemi(quartas);
    alocaTimesDaFinal(semi);
    vencedor(final);
    printf("%c\n", timeVencedor[0]);

    return 0;
}