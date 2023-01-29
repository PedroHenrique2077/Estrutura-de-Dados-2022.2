#include <stdio.h>

int main(void) {
    int P, R, n, j, a, vencedor, contador, teste = 0;
    while (1) {
        scanf("%d %d", &P, &R);
        if (P == 0 && R == 0) {
            break;
        }
        int jogadores[P];
        for (int i = 0; i < P; i++) {
            scanf("%d", &jogadores[i]);
        }
        for (int i = 0; i < R; i++) {
            scanf("%d %d", &n, &j);
            contador = 0;
            for (int k = 0; k < n; k++) {
                scanf("%d", &a);
                if (a == j) {
                    jogadores[contador++] = jogadores[k];
                }
            }
            P = contador;
        }
        teste++;
        vencedor = jogadores[0];
        printf("Teste %d\n%d\n\n", teste, vencedor);
    }
    return 0;
}

