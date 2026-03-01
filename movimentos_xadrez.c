#include <stdio.h>

// ===== Movimento da Torre =====
void torre() {
    int i = 0;

    printf("\nMovimento da Torre (para frente):\n");

    while(i < 5) {
        printf("Torre moveu 1 casa para frente\n");
        i++;
    }
}

// ===== Movimento do Bispo =====
void bispo() {
    printf("\nMovimento do Bispo (diagonal):\n");

    for(int i = 1; i <= 5; i++) {
        printf("Bispo moveu para diagonal (%d,%d)\n", i, i);
    }
}

// ===== Movimento da Rainha =====
void rainha() {
    int i = 1;

    printf("\nMovimento da Rainha (horizontal):\n");

    do {
        printf("Rainha moveu %d casa(s) para direita\n", i);
        i++;
    } while(i <= 5);
}

// ===== Movimento do Cavalo =====
void cavalo() {

    printf("\nMovimento do Cavalo (em L):\n");

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 1; j++) {
            printf("Cavalo move 2 casas para frente e 1 para direita\n");
        }
    }
}

// ===== Programa Principal =====
int main() {

    printf("=== SIMULADOR DE MOVIMENTOS DE XADREZ ===\n");

    torre();
    bispo();
    rainha();
    cavalo();

    return 0;
}