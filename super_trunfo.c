#include <stdio.h>

int main() {

    // Carta 1
    char pais1[50];
    char cidade1[50];
    int populacao1;
    float area1;
    float pib1;

    // Carta 2
    char pais2[50];
    char cidade2[50];
    int populacao2;
    float area2;
    float pib2;

    // ===== Cadastro Carta 1 =====
    printf("=== Cadastro da Carta 1 ===\n");

    printf("Pais: ");
    scanf("%s", pais1);

    printf("Cidade: ");
    scanf("%s", cidade1);

    printf("Populacao: ");
    scanf("%d", &populacao1);

    printf("Area (km2): ");
    scanf("%f", &area1);

    printf("PIB: ");
    scanf("%f", &pib1);

    // ===== Cadastro Carta 2 =====
    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Pais: ");
    scanf("%s", pais2);

    printf("Cidade: ");
    scanf("%s", cidade2);

    printf("Populacao: ");
    scanf("%d", &populacao2);

    printf("Area (km2): ");
    scanf("%f", &area2);

    printf("PIB: ");
    scanf("%f", &pib2);

    // ===== Exibição =====
    printf("\n=== CARTA 1 ===\n");
    printf("Pais: %s\n", pais1);
    printf("Cidade: %s\n", cidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f\n", pib1);

    printf("\n=== CARTA 2 ===\n");
    printf("Pais: %s\n", pais2);
    printf("Cidade: %s\n", cidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f\n", pib2);

    // ===== Operadores Matemáticos =====
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    printf("\nDensidade Carta 1: %.2f\n", densidade1);
    printf("Densidade Carta 2: %.2f\n", densidade2);

    // ===== Operadores Relacionais (Super Trunfo) =====
    printf("\n=== Comparacao por Populacao ===\n");

    if (populacao1 > populacao2) {
        printf("Carta 1 venceu!\n");
    } else if (populacao2 > populacao1) {
        printf("Carta 2 venceu!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}