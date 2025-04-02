#include <stdio.h>

// Funcao que calcula o Maximo Divisor Comum (MDC) entre dois numeros
int mdc(int a, int b) {
    // Enquanto b nao for zero, aplica o algoritmo de Euclides
    while (b != 0) {
        int temp = b;
        b = a % b;  // Calcula o resto da divisao
        a = temp;   // Atualiza a com o valor de b
    }
    return a;  // Retorna o MDC
}

// Funcao para simplificar a fracao num/den
void simplificar(int num, int den) {
    int divisor = mdc(num, den);  // Encontra o MDC entre numerador e denominador
    num /= divisor;  // Divide o numerador pelo MDC
    den /= divisor;  // Divide o denominador pelo MDC
    // Se o denominador for negativo, coloca o sinal no numerador
    if (den < 0) {
        num = -num;
        den = -den;
    }
    // Imprime a fracao simplificada
    printf("%d/%d\n", num, den);
}

// Funcao para somar duas fracoes
void soma(int n1, int d1, int n2, int d2) {
    // Calcula o numerador e denominador da soma das fracoes
    int nr = n1 * d2 + n2 * d1;
    int dr = d1 * d2;
    // Simplifica a fracao resultante
    simplificar(nr, dr);
}

// Funcao para subtrair duas fracoes
void subtracao(int n1, int d1, int n2, int d2) {
    // Calcula o numerador e denominador da subtracao das fracoes
    int nr = n1 * d2 - n2 * d1;
    int dr = d1 * d2;
    // Simplifica a fracao resultante
    simplificar(nr, dr);
}

// Funcao para multiplicar duas fracoes
void multiplicacao(int n1, int d1, int n2, int d2) {
    // Calcula o numerador e denominador da multiplicacao das fracoes
    int nr = n1 * n2;
    int dr = d1 * d2;
    // Simplifica a fracao resultante
    simplificar(nr, dr);
}

// Funcao para dividir duas fracoes
void divisao(int n1, int d1, int n2, int d2) {
    // Verifica se o numerador da segunda fracao e zero (divisao por zero)
    if (n2 == 0) {
        printf("Erro: divisao por zero\n");
        return;
    }
    // Calcula o numerador e denominador da divisao das fracoes
    int nr = n1 * d2;
    int dr = d1 * n2;
    // Simplifica a fracao resultante
    simplificar(nr, dr);
}

// Funcao principal onde o programa comeca
int main() {
    int n1, d1, n2, d2, operacao;

    // Solicita ao usuario a primeira fracao (numerador e denominador)
    printf("Digite o numerador e denominador da primeira fracao: ");
    scanf("%d %d", &n1, &d1);

    // Solicita ao usuario a segunda fracao (numerador e denominador)
    printf("Digite o numerador e denominador da segunda fracao: ");
    scanf("%d %d", &n2, &d2);

    // Solicita ao usuario qual operacao deseja realizar
    printf("Escolha a operacao: \n");
    printf("1 - Soma\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    scanf("%d", &operacao);

    // Executa a operacao escolhida
    switch (operacao) {
        case 1:
            soma(n1, d1, n2, d2);  // Chama a funcao para soma
            break;
        case 2:
            subtracao(n1, d1, n2, d2);  // Chama a funcao para subtracao
            break;
        case 3:
            multiplicacao(n1, d1, n2, d2);  // Chama a funcao para multiplicacao
            break;
        case 4:
            divisao(n1, d1, n2, d2);  // Chama a funcao para divisao
            break;
        default:
            // Caso o usuario digite uma opcao invalida
            printf("Opcao invalida!\n");
            break;
    }

    return 0;
}
