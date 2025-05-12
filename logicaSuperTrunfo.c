#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaração de variáveis
    unsigned long int Populacao1, Populacao2;
    int Numero_Pontos_turisticos1, Numero_Pontos_turisticos2;
    float Area1, Area2, PIB1, PIB2, Densidade_populacional1, Densidade_populacional2, PIB_per_capita1, PIB_per_capita2;
    char Estado1[10], Estado2[10], Codigo_da_Carta1[10], Codigo_da_Carta2[10], Nome_da_Cidade1[30], Nome_da_Cidade2[30];

    // Recolher dados das cartas
    printf("****** Carta 01 ******\n");
    printf("Estado: ");
    scanf("%s", Estado1);
    printf("Código da Carta: ");
    scanf("%s", Codigo_da_Carta1);
    printf("Nome da Cidade: ");
    scanf("%s", Nome_da_Cidade1);
    printf("População: ");
    scanf("%lu", &Populacao1);
    printf("Área: ");
    scanf("%f", &Area1);
    printf("PIB: ");
    scanf("%f", &PIB1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &Numero_Pontos_turisticos1);

    printf("\n****** Carta 02 ******\n");
    printf("Estado: ");
    scanf("%s", Estado2);
    printf("Código da Carta: ");
    scanf("%s", Codigo_da_Carta2);
    printf("Nome da Cidade: ");
    scanf("%s", Nome_da_Cidade2);
    printf("População: ");
    scanf("%lu", &Populacao2);
    printf("Área: ");
    scanf("%f", &Area2);
    printf("PIB: ");
    scanf("%f", &PIB2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &Numero_Pontos_turisticos2);

    // Calcular Densidade Populacional e PIB per capita
    Densidade_populacional1 = Populacao1 / Area1;
    PIB_per_capita1 = PIB1 / Populacao1;
    Densidade_populacional2 = Populacao2 / Area2;
    PIB_per_capita2 = PIB2 / Populacao2;

    // Escolha de atributos
    int escolha1, escolha2;
    printf("\nEscolha dois atributos para comparar:\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Populacional\n6. PIB per Capita\n");
    scanf("%d %d", &escolha1, &escolha2);

    // Definir valores para comparação
    float valor1_escolhido1 = (escolha1 == 1) ? Populacao1 : (escolha1 == 2) ? Area1 : (escolha1 == 3) ? PIB1 : 
                               (escolha1 == 4) ? Numero_Pontos_turisticos1 : (escolha1 == 5) ? Densidade_populacional1 : PIB_per_capita1;
    float valor2_escolhido1 = (escolha1 == 1) ? Populacao2 : (escolha1 == 2) ? Area2 : (escolha1 == 3) ? PIB2 : 
                               (escolha1 == 4) ? Numero_Pontos_turisticos2 : (escolha1 == 5) ? Densidade_populacional2 : PIB_per_capita2;

    float valor1_escolhido2 = (escolha2 == 1) ? Populacao1 : (escolha2 == 2) ? Area1 : (escolha2 == 3) ? PIB1 : 
                               (escolha2 == 4) ? Numero_Pontos_turisticos1 : (escolha2 == 5) ? Densidade_populacional1 : PIB_per_capita1;
    float valor2_escolhido2 = (escolha2 == 1) ? Populacao2 : (escolha2 == 2) ? Area2 : (escolha2 == 3) ? PIB2 : 
                               (escolha2 == 4) ? Numero_Pontos_turisticos2 : (escolha2 == 5) ? Densidade_populacional2 : PIB_per_capita2;

    // Determinar vencedores usando ternário
    int reverso1 = (escolha1 == 5) ? 1 : 0; // Inverte a lógica para Densidade Populacional
    int reverso2 = (escolha2 == 5) ? 1 : 0;

    char *vencedor1 = (valor1_escolhido1 > valor2_escolhido1 && !reverso1) || (valor1_escolhido1 < valor2_escolhido1 && reverso1) ? Nome_da_Cidade1 :
                      (valor1_escolhido1 < valor2_escolhido1 && !reverso1) || (valor1_escolhido1 > valor2_escolhido1 && reverso1) ? Nome_da_Cidade2 : "Empate";

    char *vencedor2 = (valor1_escolhido2 > valor2_escolhido2 && !reverso2) || (valor1_escolhido2 < valor2_escolhido2 && reverso2) ? Nome_da_Cidade1 :
                      (valor1_escolhido2 < valor2_escolhido2 && !reverso2) || (valor1_escolhido2 > valor2_escolhido2 && reverso2) ? Nome_da_Cidade2 : "Empate";

    // Exibir resultados de forma clara
    printf("RESULTADO DA COMPARAÇÃO \n");
    printf("Cidades: %s vs %s\n", Nome_da_Cidade1, Nome_da_Cidade2);
    printf("Atributos comparados: %d e %d\n", escolha1, escolha2);
    printf("Valores:\n");
    printf("%s - Atributo %d: %.2f | Atributo %d: %.2f\n", Nome_da_Cidade1, escolha1, valor1_escolhido1, escolha2, valor1_escolhido2);
    printf("%s - Atributo %d: %.2f | Atributo %d: %.2f\n", Nome_da_Cidade2, escolha1, valor2_escolhido1, escolha2, valor2_escolhido2);

    // Soma dos atributos de cada carta
    float soma1 = valor1_escolhido1 + valor1_escolhido2;
    float soma2 = valor2_escolhido1 + valor2_escolhido2;
    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", Nome_da_Cidade1, soma1);
    printf("%s: %.2f\n", Nome_da_Cidade2, soma2);

    // Exibir vencedores
    printf("\nVencedores por atributo:\n");
    printf("Atributo %d -> %s venceu!\n", escolha1, vencedor1);
    printf("Atributo %d -> %s venceu!\n", escolha2, vencedor2);

    // Vencedor geral
    char *vencedorFinal = (soma1 > soma2) ? Nome_da_Cidade1 : (soma1 < soma2) ? Nome_da_Cidade2 : "Empate";
    printf("Vencedor Final: %s \n", vencedorFinal);

    return 0;
}

    


