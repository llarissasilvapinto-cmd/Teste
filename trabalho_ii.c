#include <stdio.h>

// Função para calcular o IMC
float calcularIMC(float peso, float altura) {
    return peso / (altura * altura);
}

// Função para classificar o IMC
void classificarIMC(float imc) {
    if (imc < 18.5) {
        printf("Classificação: Abaixo do peso\n");
    } else if (imc >= 18.5 && imc < 24.9) {
        printf("Classificação: Peso normal\n");
    } else if (imc >= 25 && imc < 29.9) {
        printf("Classificação: Sobrepeso\n");
    } else {
        printf("Classificação: Obesidade\n");
    }
}

int main() {
    int opcao;
    int totalUsuarios = 0;
    float somaIMCs = 0.0;

    do {
        // Menu principal
        printf("\n===== CALCULADORA DE IMC =====\n");
        printf("1. Calcular IMC\n");
        printf("2. Mostrar media geral dos IMCs\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: {
                float peso, altura, imc;

                printf("\nDigite o peso (kg): ");
                scanf("%f", &peso);
                printf("Digite a altura (m): ");
                scanf("%f", &altura);

                imc = calcularIMC(peso, altura);
                printf("Seu IMC e: %.2f\n", imc);
                classificarIMC(imc);

                // Atualiza os valores para calcular média
                somaIMCs += imc;
                totalUsuarios++;
                break;
            }

            case 2:
                if (totalUsuarios > 0) {
                    float media = somaIMCs / totalUsuarios;
                    printf("\nMedia geral dos IMCs calculados: %.2f\n", media);
                } else {
                    printf("\nNenhum IMC foi calculado ainda.\n");
                }
                break;

            case 3:
                printf("\nObrigado por utilizar a Calculadora de IMC!\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while(opcao != 3);

    return 0;
}
