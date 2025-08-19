#include <stdio.h>
#include <string.h>


typedef struct {
char estado[10];
char cidade[50];
unsigned long int populacao;
float area;
float pib;
int pontos;
float densidade;
} Carta;

// Função para exibir os dados de uma carta

void exibir_carta(Carta c) {
printf("Carta: %s (%s)\n", c.cidade, c.estado);
printf("População: %lu\n", c.populacao);
printf("Area: %.2f km²\n", c.area);
printf("PIB: %.2f bilhões\n", c.pib);
printf("Pontos Turisticos: %d\n", c.pontos);
printf("Densidade Demografica: %.2f hab/km²\n", c.densidade);
}

// Função para exibir o menu e obter uma escolha válida

int escolher_atributo(int opcao_ja_escolhida) {
int opcao;
do {
printf("1. População\n");
printf("2. Area\n");
printf("3. PIB\n");
printf("4. Pontos Turisticos\n");
printf("5. Densidade Demografica\n");
printf("Digite sua opção: ");

// entrada inválida 

if (scanf("%d", &opcao) != 1) {
printf("Entrada inválida. Por favor, digite um número.\n");
while(getchar() != '\n'); // Limpa o buffer
opcao = 0; // Define como inválido para repetir o loop
}

if (opcao < 1 || opcao > 5) {
printf("Opção fora do intervalo. Tente novamente.\n");
} else if (opcao == opcao_ja_escolhida) {
 printf("Este atributo já foi escolhido. Tente novamente.\n");
}
} while (opcao < 1 || opcao > 5 || opcao == opcao_ja_escolhida);
return opcao;
}

// Função para obter o valor de um atributo

float get_valor_atributo(Carta c, int opcao) {
switch (opcao) {
case 1: return c.populacao;
case 2: return c.area;
case 3: return c.pib;
case 4: return c.pontos;
case 5: return c.densidade;
default: return 0.0;
}
}

// Função para obter o nome do atributo

const char* get_nome_atributo(int opcao) {
switch (opcao) {
case 1: return "População";
case 2: return "Area";
case 3: return "PIB";
case 4: return "Pontos Turisticos";
case 5: return "Densidade Demografica";
default: return "";
}
}

int main() {

Carta carta1 = {"SP", "Sao_Paulo", 12396372, 1521.11, 699.29, 500};
Carta carta2 = {"RJ", "Rio_de_Janeiro", 6775561, 1200.25, 359.60, 450};

// Calcular a densidade e armazenar

carta1.densidade = (float)carta1.populacao / carta1.area;
carta2.densidade = (float)carta2.populacao / carta2.area;

// Exibição das cartas

printf("--- Cartas Disponiveis ---\n");
exibir_carta(carta1);
printf("\n");
exibir_carta(carta2);

// --- Menu: Primeiro atributo ---

printf("\n--- Escolha o PRIMEIRO Atributo para Comparacao ---\n");
int opcao1 = escolher_atributo(0); // 0 significa que nenhuma opção foi escolhida ainda

// --- Menu: Segundo atributo ---

printf("\n--- Escolha o SEGUNDO Atributo para Comparacao ---\n");
int opcao2 = escolher_atributo(opcao1);

// --- Comparação dos atributos ---

float valor1_1 = get_valor_atributo(carta1, opcao1);
float valor2_1 = get_valor_atributo(carta2, opcao1);
float valor1_2 = get_valor_atributo(carta1, opcao2);
float valor2_2 = get_valor_atributo(carta2, opcao2);

float soma1 = 0.0, soma2 = 0.0;

// Acumula os valores, aplicando a lógica especial para Densidade

soma1 += (opcao1 == 5) ? (1.0 / valor1_1) : valor1_1;
soma2 += (opcao1 == 5) ? (1.0 / valor2_1) : valor2_1;
soma1 += (opcao2 == 5) ? (1.0 / valor1_2) : valor1_2;
soma2 += (opcao2 == 5) ? (1.0 / valor2_2) : valor2_2;

// --- Exibição do Resultado Final ---

printf("\n--- Comparação ---\n");
printf("Atributo 1: %s\n", get_nome_atributo(opcao1));
printf("%s: %.2f | %s: %.2f\n", carta1.cidade, valor1_1, carta2.cidade, valor2_1);

printf("\nAtributo 2: %s\n", get_nome_atributo(opcao2));
printf("%s: %.2f | %s: %.2f\n", carta1.cidade, valor1_2, carta2.cidade, valor2_2);

printf("\n--- Resultado Final ---\n");
printf("Soma dos atributos de %s: %.2f\n", carta1.cidade, soma1);
printf("Soma dos atributos de %s: %.2f\n", carta2.cidade, soma2);

 if (soma1 > soma2) {
 printf("VENCEDOR: %s!\n", carta1.cidade);
 } else if (soma2 > soma1) {
 printf("VENCEDOR: %s!\n", carta2.cidade);
 } else {
 printf("RESULTADO: Empate!\n");
 }

 return 0;
}