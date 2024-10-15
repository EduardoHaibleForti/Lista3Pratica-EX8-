#include <stdio.h>

#define SIZE 3


void inicializaTabuleiro(char tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}


void imprimeTabuleiro(char tabuleiro[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c", tabuleiro[i][j]);
            if (j < SIZE - 1) printf(" | ");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---------\n");
    }
    printf("\n");
}


int verificaVitoria(char tabuleiro[SIZE][SIZE], char jogador) {

    for (int i = 0; i < SIZE; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) {
            return 1;
        }
    }


    for (int i = 0; i < SIZE; i++) {
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador) {
            return 1;
        }
    }


    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) {
        return 1;
    }
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) {
        return 1;
    }

    return 0;
}


int verificaEmpate(char tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    char tabuleiro[SIZE][SIZE];
    int linha, coluna, jogada = 0;
    char jogador = 'X';

    inicializaTabuleiro(tabuleiro);

    while (1) {
        imprimeTabuleiro(tabuleiro);


        printf("Jogador %c, insira a linha (0-2) e a coluna (0-2): ", jogador);
        scanf("%d %d", &linha, &coluna);


        if (linha >= 0 && linha < SIZE && coluna >= 0 && coluna < SIZE && tabuleiro[linha][coluna] == ' ') {
            tabuleiro[linha][coluna] = jogador;
            jogada++;


            if (verificaVitoria(tabuleiro, jogador)) {
                imprimeTabuleiro(tabuleiro);
                printf("Jogador %c venceu!\n", jogador);
                break;
            }


            if (verificaEmpate(tabuleiro)) {
                imprimeTabuleiro(tabuleiro);
                printf("Empate!\n");
                break;
            }


            if (jogador == 'X') {
                jogador = 'O';
            } else {
                jogador = 'X';
            }
        } else {
            printf("Jogada inválida. Tente novamente.\n");
        }
    }

    return 0;
}

