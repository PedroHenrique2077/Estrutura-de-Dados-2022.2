#include <stdio.h>

int main(void)
{
    int N, A, L, P;

    scanf("%d", &N);
    scanf("%d %d %d", &A, &L, &P);

    if( N <= A && N <= L && N <= P)
    {
        printf("S\n");
    }
    else
    {
        printf("N\n");
    }

    return 0;
}