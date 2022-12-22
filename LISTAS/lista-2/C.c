#include <stdio.h>

int main()
{
    int c;

    while(scanf("%x",&c) != EOF)
    {
        char *ponteiro = &c;
        for(int i = 0; i<4; i++){
            if(ponteiro[i] == 0){
                return 0;
            }
            printf("%c", ponteiro[i]);
        }
    }
}