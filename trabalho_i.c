#include <stdio.h>

int main() {
    char nome[50];
    float preco_anterior, preco_atual, variacao;
    char situacao[30];

    // Cabeçalho da tabela
    printf("%-15s %-18s %-18s %-14s %s\n", 
           "Produto", "Preço Ant. (R$)", "Preço Atual (R$)", "Variação (%)", "Situação");
    printf("-------------------------------------------------------------------------------\n");

    // Loop para 3 produtos
    for (int i = 0; i < 3; i++) {
        // Entrada de dados
        printf("Digite o nome do produto: ");
        scanf(" %[^\n]", nome); // lê string com espaços

        printf("Digite o preço do mês anterior (R$): ");
        scanf("%f", &preco_anterior);

        printf("Digite o preço do mês atual (R$): ");
        scanf("%f", &preco_atual);

        // Cálculo da variação percentual
        variacao = ((preco_atual - preco_anterior) / preco_anterior) * 100;

        // Classificação
        if (variacao > 10) {
            sprintf(situacao, "Aumento abusivo");
        } else if (variacao == 10) {
            sprintf(situacao, "Limite de aumento");
        } else if (variacao > 0) {
            sprintf(situacao, "Aumento normal");
        } else if (variacao < 0) {
            sprintf(situacao, "Redução de preço");
        } else {
            sprintf(situacao, "Estável");
        }

        // Exibição na tabela
        printf("%-15s %-18.2f %-18.2f %-14.1f %s\n", 
               nome, preco_anterior, preco_atual, variacao, situacao);
    }

    return 0;
}
