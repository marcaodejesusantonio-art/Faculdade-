#include <stdio.h>

int main() {

    // cidades
    char cidades[4][30] = {"Campinas", "Santos", "Sorocaba", "Jundiai"};

    int populacao[4] = {1200000, 500000, 700000, 450000};
    float pib[4] = {65.3, 40.8, 35.0, 30.5};

    int c1, c2;
    int op1, op2;
    int pontos1 = 0;
    int pontos2 = 0;

    printf("==== SUPER TRUNFO ====\n");

    printf("\nEscolha a primeira cidade:\n");
    for(int i = 0; i < 4; i++) {
        printf("%d - %s\n", i, cidades[i]);
    }
    scanf("%d", &c1);

    printf("\nEscolha a segunda cidade:\n");
    for(int i = 0; i < 4; i++) {
        printf("%d - %s\n", i, cidades[i]);
    }
    scanf("%d", &c2);

    printf("\nEscolha o PRIMEIRO atributo:\n");
    printf("1 - Populacao\n");
    printf("2 - PIB\n");
    scanf("%d", &op1);

    printf("\nEscolha o SEGUNDO atributo:\n");
    printf("1 - Populacao\n");
    printf("2 - PIB\n");
    scanf("%d", &op2);

    // ===== PRIMEIRA COMPARACAO =====
    if(op1 == 1) {
        if(populacao[c1] > populacao[c2])
            pontos1++;
        else
            pontos2++;
    }
    else if(op1 == 2) {
        if(pib[c1] > pib[c2])
            pontos1++;
        else
            pontos2++;
    }

    // ===== SEGUNDA COMPARACAO =====
    if(op2 == 1) {
        if(populacao[c1] > populacao[c2])
            pontos1++;
        else
            pontos2++;
    }
    else if(op2 == 2) {
        if(pib[c1] > pib[c2])
            pontos1++;
        else
            pontos2++;
    }

    // ===== RESULTADO =====
    printf("\nResultado:\n");
    printf("%s pontos: %d\n", cidades[c1], pontos1);
    printf("%s pontos: %d\n", cidades[c2], pontos2);

    (pontos1 > pontos2) ?
        printf("Vencedor: %s\n", cidades[c1]) :
        (pontos2 > pontos1) ?
            printf("Vencedor: %s\n", cidades[c2]) :
            printf("Empate!\n");

    return 0;
}