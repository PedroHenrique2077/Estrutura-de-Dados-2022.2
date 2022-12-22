#include <stdio.h>
#include <stdlib.h>

int dif(int n1, int n2)
{
    return (n1 - n2);
}

int main()
{

    int n;
    int j;
    int z;
    int i;
    int teste = 1;
    int deposito[100];

    scanf("%d", &n);

    while (n != 0)
    {

        for (i = 1; i <= n; i++)
        {
            scanf("%d%d", &j, &z);
            deposito[i] = dif(j, z);
            if (i > 1)
                deposito[i] += deposito[i - 1];
        }
        printf("Teste %d\n", teste);
        for (i = 1; i <= n; i++)
        {
            printf("%d\n", deposito[i]);
        }
        teste++;
        scanf("%d", &n);
    }
    return 0;
}