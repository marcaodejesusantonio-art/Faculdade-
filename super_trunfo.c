#include <stdio.h>

// Estrutura para guardar os dados de uma carta
typedef struct {
    char pais[50];
    char cidade[50];
    int populacao;
    float area;
    float pib;
} Carta;

// Remove o '\n' que o fgets coloca no final
void removerQuebraLinha(char texto[]) {
    int i = 0;
    while (texto[i] != '\0') {
        if (texto[i] == '\n') {
            texto[i] = '\0';
            break;
        }
        i++;
    }
}

void cadastrarCarta(Carta *c, int numero) {
    printf("\n==============================\n");
    printf("   Cadastro da Carta %d\n", numero);
    printf("==============================\n");

    printf("Digite o país: ");
    fgets(c->pais, sizeof(c->pais), stdin);
    removerQuebraLinha(c->pais);

    printf("Digite a cidade: ");
    fgets(c->cidade, sizeof(c->cidade), stdin);
    removerQuebraLinha(c->cidade);

    printf("Digite a população: ");
    scanf("%d", &c->populacao);

    printf("Digite a área (km²): ");
    scanf("%f", &c->area);

    printf("Digite o PIB: ");
    scanf("%f", &c->pib);

    // Limpa o '\n' que sobra do scanf antes do próximo fgets
    getchar();

    printf("\n✅ Carta %d cadastrada com sucesso!\n", numero);
}

void mostrarCarta(Carta c, int numero) {
    printf("\n=========== CARTA %d ===========\n", numero);
    printf("País:       %s\n", c.pais);
    printf("Cidade:     %s\n", c.cidade);
    printf("População:  %d\n", c.populacao);
    printf("Área:       %.2f km²\n", c.area);
    printf("PIB:        %.2f\n", c.pib);
}

int main() {
    Carta carta1, carta2;

    printf("🎴 Bem-vindo ao cadastro do Super Trunfo!\n");
    printf("Vamos preencher duas cartas.\n");

    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    // Exibição
    mostrarCarta(carta1, 1);
    mostrarCarta(carta2, 2);

    // Densidade demográfica (com proteção contra divisão por zero)
    float densidade1 = (carta1.area > 0) ? (carta1.populacao / carta1.area) : 0;
    float densidade2 = (carta2.area > 0) ? (carta2.populacao / carta2.area) : 0;

    printf("\n📌 Densidade Demográfica:\n");
    printf("Carta 1: %.2f hab/km²\n", densidade1);
    printf("Carta 2: %.2f hab/km²\n", densidade2);

    // Comparação por população
    printf("\n⚔️  Batalha por População:\n");
    if (carta1.populacao > carta2.populacao) {
        printf("🏆 Carta 1 venceu!\n");
    } else if (carta2.populacao > carta1.populacao) {
        printf("🏆 Carta 2 venceu!\n");
    } else {
        printf("🤝 Empate!\n");
    }

    printf("\nObrigado por jogar! \n");
    return 0;
}
