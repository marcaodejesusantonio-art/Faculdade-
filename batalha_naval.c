#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 10
#define LIMITE_JOGADAS 20

// Função para desenhar o tabuleiro
void exibirTabuleiro(int tab[TAMANHO][TAMANHO], bool revelarNavios) {
    printf("\n    ");
    for (int j = 0; j < TAMANHO; j++) printf("%d ", j);
    printf("\n   ---------------------\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%d | ", i);
        for (int j = 0; j < TAMANHO; j++) {
            if (tab[i][j] == 3 && !revelarNavios) printf("~ "); 
            else if (tab[i][j] == 3) printf("N "); // Navio
            else if (tab[i][j] == 1) printf("X "); // Acerto
            else if (tab[i][j] == 5) printf("* "); // Área de Efeito
            else if (tab[i][j] == 2) printf("O "); // Água (Tiro Errado)
            else printf("~ ");
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};
    int linha, coluna, jogadas = 0;
    int acertos = 0;

    // Posicionando Navios (Conforme pede o exercício)
    tabuleiro[2][3] = 3; tabuleiro[2][4] = 3; 
    tabuleiro[5][5] = 3; tabuleiro[6][5] = 3;

    printf("--- OCEANIC GAMES: BATALHA NAVAL ---\n");

    while (jogadas < LIMITE_JOGADAS) {
        printf("\n--- RODADA %d/%d | ACERTOS: %d ---\n", jogadas + 1, LIMITE_JOGADAS, acertos);
        exibirTabuleiro(tabuleiro, false);
        
        printf("\nDigite Linha e Coluna (ex: 2 4) ou -1 para sair: ");
        if (scanf("%d", &linha) && linha == -1) break;
        scanf("%d", &coluna);

        if (linha < 0 || linha >= TAMANHO || coluna < 0 || coluna >= TAMANHO) {
            printf("\n[!] Coordenada invalida!\n");
            continue; 
        }

        // --- Lógica de Habilidade Especial (Área de Efeito em Cruz) ---
        // Se o jogador acertar a quina (9,9), ativa uma bomba em cruz no centro
        if (linha == 9 && coluna == 9) {
            printf("\n>>> HABILIDADE ESPECIAL ATIVADA NO CENTRO! <<<\n");
            int cx = 4, cy = 4; // Centro do efeito
            for(int i = 0; i < TAMANHO; i++) {
                for(int j = 0; j < TAMANHO; j++) {
                    if (i == cx || j == cy) { // Se estiver na mesma linha ou coluna do centro
                        if (tabuleiro[i][j] == 3) { 
                            tabuleiro[i][j] = 1; acertos++; 
                        } else if (tabuleiro[i][j] == 0) {
                            tabuleiro[i][j] = 5; 
                        }
                    }
                }
            }
        } 
        // Tiro Normal
        else if (tabuleiro[linha][coluna] == 3) {
            printf("\n>>> ALVO ATINGIDO! <<<\n");
            tabuleiro[linha][coluna] = 1;
            acertos++;
        } else {
            printf("\n--- Agua... ---\n");
            tabuleiro[linha][coluna] = 2;
        }

        jogadas++;
    }

    printf("\nFIM DE JOGO! Mapa final:\n");
    exibirTabuleiro(tabuleiro, true);

    return 0;
}