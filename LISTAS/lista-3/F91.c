#include <stdio.h>

int f91(int n)
{
    if(n >= 101)
    {
        return n - 10;
    }
    if(n <= 100)
    {
        return f91(f91(n+11));
    }
}

int main()
{
    int entrada = 0;
    while (scanf("%d", &entrada) && entrada != 0)
    {
        printf("f91(%d) = %d\n", entrada, f91(entrada));
    }

    return 0;
}