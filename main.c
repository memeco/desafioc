#include <stdio.h>

int main() {
    int num1, num2, soma;

    // Solicitar o primeiro número ao usuário
    printf("Digite o primeiro número inteiro: ");
    scanf("%d", &num1);

    // Solicitar o segundo número ao usuário
    printf("Digite o segundo número inteiro: ");
    scanf("%d", &num2);

    // Calcular a soma dos dois números
    soma = num1 + num2;

    // Exibir os números e a soma de forma diferente
    printf("Você digitou os números %d e %d.\n", num1, num2);
    printf("A soma deles é: %d\n", soma);

    return 0;
}
