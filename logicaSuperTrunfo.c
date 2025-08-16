#include <stdio.h>
#include <string.h>

int main() {
    
    char estado1[10] = "SP", estado2[10] = "RJ";
    char codigo1[10] = "SP01", codigo2[10] = "RJ02";
    char cidade1[50] = "Sao_Paulo", cidade2[50] = "Rio_de_Janeiro"; 
    unsigned long int populacao1 = 12396372, populacao2 = 6775561;
    float area1 = 1521.11, area2 = 1200.25;
    float pib1 = 699.29, pib2 = 359.60;
    int pontos1 = 500, pontos2 = 450;

    // Variaveis para calculo
    float densidade1, densidade2;
    float tipo1, tipo2;

    // Calculando densidade e PIB per capita
    densidade1 = (float)populacao1 / area1;
    tipo1 = (pib1 * 1e9) / (float)populacao1; 
    
    densidade2 = (float)populacao2 / area2;
    tipo2 = (pib2 * 1e9) / (float)populacao2;
    
    int opcao;

    // Exibindo as cartas para o usuario
    printf("--- Cartas Disponiveis ---\n");
    printf("Carta 1: %s (%s)\n", cidade1, estado1);
    printf("  População: %lu\n", populacao1);
    printf("  Area: %.2f km²\n", area1);
    printf("  PIB: %.2f bilhoes\n", pib1);
    printf("  Pontos Turisticos: %d\n", pontos1);
    printf("  Densidade Demografica: %.2f hab/km²\n", densidade1);
    
    printf("\nCarta 2: %s (%s)\n", cidade2, estado2);
    printf("  População: %lu\n", populacao2);
    printf("  Area: %.2f km²\n", area2);
    printf("  PIB: %.2f bilhoes\n", pib2);
    printf("  Pontos Turisticos: %d\n", pontos2);
    printf("  Densidade Demografica: %.2f hab/km²\n", densidade2);


    // Menu interativo
    printf("\n--- Escolha um Atributo para Comparacao ---\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos Turisticos\n");
    printf("5. Densidade Demografica\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);

    // Estrutura switch para a logica de comparacao
    printf("\n--- Resultado da Comparacao ---\n");
    
    switch (opcao) {
        case 1: // Populacao
            printf("Atributo: Populacao\n");
            printf("Valores: %s: %lu | %s: %lu\n", cidade1, populacao1, cidade2, populacao2);
            if (populacao1 > populacao2) {
                printf("Vencedor: %s!\n", cidade1);
            } else if (populacao2 > populacao1) {
                printf("Vencedor: %s!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        case 2: // Area
            printf("Atributo: Area\n");
            printf("Valores: %s: %.2f km² | %s: %.2f km²\n", cidade1, area1, cidade2, area2);
            if (area1 > area2) {
                printf("Vencedor: %s!\n", cidade1);
            } else if (area2 > area1) {
                printf("Vencedor: %s!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("Valores: %s: %.2f bilhoes | %s: %.2f bilhoes\n", cidade1, pib1, cidade2, pib2);
            if (pib1 > pib2) {
                printf("Vencedor: %s!\n", cidade1);
            } else if (pib2 > pib1) {
                printf("Vencedor: %s!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        case 4: // Pontos Turisticos
            printf("Atributo: Pontos Turisticos\n");
            printf("Valores: %s: %d | %s: %d\n", cidade1, pontos1, cidade2, pontos2);
            if (pontos1 > pontos2) {
                printf("Vencedor: %s!\n", cidade1);
            } else if (pontos2 > pontos1) {
                printf("Vencedor: %s!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        case 5: // Densidade Demografica (Regra invertida!)
            printf("Atributo: Densidade Demografica\n");
            printf("Valores: %s: %.2f hab/km² | %s: %.2f hab/km²\n", cidade1, densidade1, cidade2, densidade2);
            if (densidade1 < densidade2) { // Regra invertida: menor valor vence
                printf("Vencedor: %s!\n", cidade1);
            } else if (densidade2 < densidade1) {
                printf("Vencedor: %s!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        default:
            printf("Opcao invalida! Por favor, escolha uma opcao de 1 a 5.\n");
            break;
    }

    return 0;
}