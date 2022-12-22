#include <stdio.h>
#include <string.h>

void clear_buffer(void){
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
    return;
}

int main(){

    int altura;
    int largura = 12;
    int quantidadeGalho, alturaDoGalho;
    char ladoGalho, ladoJogador;
    int troca = 0;
    int contador = 1;
    int morreu = 0;
    int temGalho = 0;
    char movimento[2000];

    scanf("%d", &altura);
    altura += 2;

    char game[altura][largura];
    int galho[altura][largura];

    for (int i = 0; i < altura; i++){

        for (int j = 0; j < largura; j++){

            game[i][j] = ' ';
            if (i == (altura - 1) || i == 0){
                game[i][j] = '~';
            }
            if ((i <= (altura - 2) && i != 0) && (j >= 4 && j <= 6)){
                game[i][j] = '|';
            }
            if (j == (largura - 1)){
                game[i][j] = '\n';
            }
        }
    }

    scanf("%d", &quantidadeGalho);
    clear_buffer();
    
    for (int k = 0; k < quantidadeGalho; k++){

        scanf("%c %d", &ladoGalho, &alturaDoGalho);
        clear_buffer();
        for (int i = 0; i < altura; i++){

            for (int j = 0; j < largura; j++){

                if (ladoGalho == 'D'){

                    if (j >= 7 && j <= 9){
                        if (i == (altura - (alturaDoGalho + 1))){
                            game[i][j] = '-';
                        }
                    }
                }
                if (ladoGalho == 'E'){
                    if (j >= 1 && j <= 3){
                        if (i == (altura - (alturaDoGalho + 1))){
                            game[i][j] = '-';
                        }
                    }
                }
            }
        }
    }

    scanf("%c", &ladoJogador);
    for (int i = 0; i < altura; i++){
        for (int j = 0; j < largura; j++){
            if (ladoJogador == 'E'){
                if (i == (altura - 2) || i == (altura - 3)){
                    if (j == 2){
                        game[i][j] = 'L';
                    }
                }
            }
            if (ladoJogador == 'D'){
                if (i == (altura - 2) || i == (altura - 3)){
                    if (j == 8){
                        game[i][j] = 'L';
                    }
                }
            }
        }
    }
    
    clear_buffer();
    fgets(movimento, 2000, stdin);

    for (int i = 0; i < altura; i++){
        for (int j = 0; j < largura; j++){
            if (i == (altura - 7) && j <= 10){
                printf("~");
                if (j == 10){
                    printf("\n");
                }
            }
            if (i > (altura - 7)){
                printf("%c", game[i][j]);
            }
        }
    }

    for (int k = 0; k < (strlen(movimento) - 1); k++){
        troca = 0;
        morreu = 0;
        temGalho = 0;
        for (int l = 0; l < altura; l++){
            for (int p = 0; p < largura; p++){
                galho[l][p] = 0;
            }
        }
        for (int i = 0; i < altura; i++){
            for (int j = 0; j < largura; j++){
                if (movimento[k] == 'T'){
                    if (i == (altura - 2)){
                        if (j == 2){
                            if (game[i][j] == 'L'){
                                if (game[i][j + 6] == '-' || game[i - 1][j + 6] == '-'){
                                    temGalho = 1;
                                }
                                else{
                                    game[i][j] = ' ';
                                    game[i - 1][j] = ' ';
                                    game[i][j + 6] = 'L';
                                    game[i - 1][j + 6] = 'L';
                                    troca = 1;
                                }
                            }
                        }
                        if (j == 8 && troca == 0){
                            if (game[i][j] == 'L'){
                                if (game[i][j - 6] == '-' || game[i - 1][j - 6] == '-'){
                                    temGalho = 1;
                                }
                                else{
                                    game[i][j] = ' ';
                                    game[i - 1][j] = ' ';
                                    game[i][j - 6] = 'L';
                                    game[i - 1][j - 6] = 'L';
                                }
                            }
                        }
                    }
                }
                if (movimento[k] == 'B'){
                    if (i == (altura - 2)){
                        if (j == 2){
                            if (game[i][j] == 'L'){
                                if (game[i][j + 2] == '>'){
                                    game[i - ((altura - 2) - contador)][j + 2] = ' ';
                                    game[i - ((altura - 2) - contador)][j + 3] = ' ';
                                    game[i - ((altura - 2) - contador)][j + 4] = ' ';
                                    game[i][j + 2] = '|';
                                    game[i][j + 3] = '|';
                                    game[i][j + 4] = '|';
                                    contador++;
                                    for (int l = 0; l < altura; l++){
                                        for (int p = 0; p < largura; p++){
                                            if (game[l][p] == '-'){
                                                game[l][p] = ' ';
                                                galho[l + 1][p] = 1;
                                            }
                                        }
                                    }
                                    for (int l = 0; l < altura; l++){
                                        for (int p = 0; p < largura; p++){
                                            if (galho[l][p] == 1){
                                                if (game[l][p] == 'L'){
                                                    morreu = 1;
                                                }
                                                else{
                                                    game[l][p] = '-';
                                                }
                                            }
                                            if (l == (altura - 1)){
                                                game[l][p] = '~';
                                                if(p == largura-1){
                                                    game[l][p] = '\n';
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }
                                if (game[i - 1][j + 2] == '|'){
                                    game[i][j + 2] = '>';
                                    break;
                                }
                            }
                        }
                        if (j == 8){
                            if (game[i][j] == 'L'){
                                if (game[i][j - 2] == '<'){
                                    game[i - ((altura - 2) - contador)][j - 2] = ' ';
                                    game[i - ((altura - 2) - contador)][j - 3] = ' ';
                                    game[i - ((altura - 2) - contador)][j - 4] = ' ';
                                    game[i][j - 2] = '|';
                                    game[i][j - 3] = '|';
                                    game[i][j - 4] = '|';
                                    contador +=1;
                                    for (int l = 0; l < altura; l++){
                                        for (int p = 0; p < largura; p++){
                                            if (game[l][p] == '-'){
                                                game[l][p] = ' ';
                                                galho[l + 1][p] = 1;
                                            }
                                        }
                                    }
                                    for (int l = 0; l < altura; l++){
                                        for (int p = 0; p < largura; p++){
                                            if (galho[l][p] == 1){
                                                if (game[l][p] == 'L'){
                                                    morreu = 1;
                                                }
                                                else{
                                                    game[l][p] = '-';
                                                }
                                            }
                                            if (l == (altura - 1)){
                                                game[l][p] = '~';
                                                if(p == largura-1){
                                                    game[l][p] = '\n';
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }
                                if (game[i - 1][j - 2] == '|'){
                                    game[i][j - 2] = '<';
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (morreu != 1 && temGalho != 1){
            for (int i = 0; i < altura; i++){
                for (int j = 0; j < largura; j++){
                    if (i == (altura - 7) && j <= 10){
                        printf("~");
                        if (j == 10){
                            printf("\n");
                        }
                    }
                    if (i > (altura - 7)){
                        printf("%c", game[i][j]);
                    }
                }
            }
        }
        else if (temGalho == 1){
            printf("**beep**\n");
            continue;
        }
        else{
            printf("**morreu**\n");
            break;
        }
    }

    return 0;
}