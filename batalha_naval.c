#include <stdio.h>
#include <stdbool.h>

#define TAM 10
#define MAX_JOGADAS 20

// Códigos do tabuleiro (fica bem mais legível do que "números mágicos")
#define AGUA           0
#define NAVIO          3
#define ACERTO         1
#define ERRO           2
#define AREA_EFEITO    5

void imprimirCabecalho(void) {
    printf("\n    ");
    for (int c = 0; c < TAM; c++) printf("%d ", c);
    printf("\n   ---------------------\n");
}

// Mostra o tabuleiro.
// revelarNavios = false -> navios ficam escondidos
// revelarNavios = true  -> mostra tudo no final
void mostrarTabuleiro(int tab[TAM][TAM], bool revelarNavios) {
    imprimirCabecalho();

    for (int l = 0; l < TAM; l++) {
        printf("%d | ", l);

        for (int c = 0; c < TAM; c++) {
            int celula = tab[l][c];

            if (celula == NAVIO && !revelarNavios) {
                printf("~ ");
            } else if (celula == NAVIO) {
                printf("N ");
            } else if (celula == ACERTO) {
                printf("X ");
            } else if (celula == AREA_EFEITO) {
                printf("* ");
            } else if (celula == ERRO) {
                printf("O ");
            } else {
                printf("~ ");
            }
        }

        printf("\n");
    }
}

bool coordenadaValida(int l, int c) {
    return (l >= 0 && l < TAM && c >= 0 && c < TAM);
}

// Habilidade especial: quando o jogador atira em (9,9),
// explode uma cruz no centro (4,4) (linha e coluna do centro).
void ativarHabilidadeEspecial(int tab[TAM][TAM], int *acertos) {
    printf("\n💥 >>> HABILIDADE ESPECIAL ATIVADA! Explosão em cruz no centro (4,4)! <<< 💥\n");

    const int centroL = 4;
    const int centroC = 4;

    for (int l = 0; l < TAM; l++) {
        for (int c = 0; c < TAM; c++) {
            if (l == centroL || c == centroC) {
                if (tab[l][c] == NAVIO) {
                    tab[l][c] = ACERTO;
                    (*acertos)++;
                } else if (tab[l][c] == AGUA) {
                    tab[l][c] = AREA_EFEITO;
                }
            }
        }
    }
}

int main(void) {
    int tabuleiro[TAM][TAM] = {0};

    int linha = 0, coluna = 0;
    int jogadas = 0;
    int acertos = 0;

    // Posicionando navios (como no exercício)
    tabuleiro[2][3] = NAVIO; tabuleiro[2][4] = NAVIO;
    tabuleiro[5][5] = NAVIO; tabuleiro[6][5] = NAVIO;

    printf("=== OCEANIC GAMES: BATALHA NAVAL ===\n");
    printf("Regras rápidas:\n");
    printf("- Digite linha e coluna (ex: 2 4)\n");
    printf("- Digite -1 para sair\n");
    printf("- Se você atirar em (9,9), ativa a habilidade especial!\n");

    while (jogadas < MAX_JOGADAS) {
        printf("\n--- Rodada %d/%d | Acertos: %d ---\n", jogadas + 1, MAX_JOGADAS, acertos);
        mostrarTabuleiro(tabuleiro, false);

        printf("\nDigite Linha e Coluna (ex: 2 4) ou -1 para sair: ");

        if (scanf("%d", &linha) != 1) {
            printf("\n[!] Entrada inválida. Encerrando.\n");
            break;
        }

        if (linha == -1) {
            printf("\nSaindo do jogo... até a próxima!\n");
            break;
        }

        if (scanf("%d", &coluna) != 1) {
            printf("\n[!] Entrada inválida. Encerrando.\n");
            break;
        }

        if (!coordenadaValida(linha, coluna)) {
            printf("\n[!] Coordenada fora do mapa! Tente algo entre 0 e 9.\n");
            continue; // não conta jogada
        }

        // Evita contar duas vezes a mesma casa
        if (tabuleiro[linha][coluna] == ACERTO || tabuleiro[linha][coluna] == ERRO || tabuleiro[linha][coluna] == AREA_EFEITO) {
            printf("\n[!] Você já tentou essa posição. Escolha outra!\n");
            continue; // não conta jogada
        }

        // Habilidade especial
        if (linha == 9 && coluna == 9) {
            ativarHabilidadeEspecial(tabuleiro, &acertos);
        }
        // Tiro normal
        else if (tabuleiro[linha][coluna] == NAVIO) {
            printf("\n🎯 >>> ALVO ATINGIDO! <<<\n");
            tabuleiro[linha][coluna] = ACERTO;
            acertos++;
        } else {
            printf("\n🌊 Água... nada aqui.\n");
            tabuleiro[linha][coluna] = ERRO;
        }

        jogadas++;
    }

    printf("\n=== FIM DE JOGO! ===\n");
    printf("Mapa final (com navios revelados):\n");
    mostrarTabuleiro(tabuleiro, true);

    printf("\nPlacar: %d acerto(s) em %d jogada(s).\n", acertos, jogadas);
    return 0;
}
