#include <stdio.h>

void ultrapassaMinimamente(int *entrada, int soma, int maximo)
{
    if(*entrada == 0)
    {
        return;
    }

    if((*entrada + soma) > maximo)
    {
        soma = 0;
        ultrapassaMinimamente(entrada + 1, soma, maximo);
        printf("%d\n", *entrada);
    } else
    {
        soma += *entrada;
        ultrapassaMinimamente(entrada + 1, soma, maximo);
    }
}


int main(void)
{
    int entrada[1001] = {[0 ... 1000] = 0};
    int num, i = 0, maximo;
    scanf("%d", &num);
    while (num != 0)
    {
        entrada[i] = num;
        scanf("%d", &num);
        i++;
    }

    scanf("%d", &maximo);

    ultrapassaMinimamente(entrada, 0, maximo);
    
    return 0;
}