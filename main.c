#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void obter_fracoes();
void somar_fracoes(int x, int y, int u, int v);
void subtrair_fracoes(int x, int y, int u, int v);
void multiplicar_fracoes(int x, int y, int u, int v);
void dividir_fracoes(int x, int y, int u, int v);
void simplificar_fracao(int x, int y);

//Variável Global
int a, b, c, d;

//Função principal
int main(int args, char *arg[])
{
    char r; //Variavel para armazenar a escolha do usuario
    //Loop principal do programa
    while (1)
    {
        system("CLS"); // Limpa a tela (específico do Windows)
        printf("1. Somar\n");
        printf("2. Subtrair\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("9. Fim\n");
        printf("O que deseja? ");
        r = getche(); //Lê uma tecla do usuário sem precisar
        if (r =='9') // Sai do loop se a opção for 9
        break;

        obter_fracoes (); //Pede ao usuário que insira duas frações

        //Executa a operação conforme a escolha do usuário
        switch (r)
        {
            case '1' : somar_fracoes(a,b,c,d);break;
            case '2' : subtrair_fracoes(a,b,c,d);break;
            case '3' : multiplicar_fracoes(a,b,c,d);break;
            case '4' : dividir_fracoes (a,b,c,d); break;
        }
    }

    return 0; // Fim da função main
}
//Função para obter as duas frações do usuário
void obter_fracoes ()
{
    printf("\n1a fracao: ");
    scanf ("%d %d", &a, &b); //Lê o numerador e o denominador 1a fracao
    printf("\n2a fracao: ");
    scanf ("%d %d", &c, &d); //Lê o numerador e o denominador 2a fracao
}

//Função para somar duas frações: (x/y) + (u/v)
void somar_fracoes (int x,int y, int u, int v)
{
    int n,d;
    n= x*v + u *v; // Numerador
    d= y*v; //Denominador comum
    simplificar_fracao (n,d);
}
void subtrair_fracoes (int x,int y, int u, int v)
{
    int n,d;
    n= x*v - u *v;
    d= y*v;
    simplificar_fracao (n,d);
}

void multiplicar_fracoes (int x,int y, int u, int v)
{
    int n,d;
    n= x*u; //Multiplica os numeradores
    d= y*v; // Multiplica os denominadores
    simplificar_fracao (n,d);
}
void dividir_fracoes (int x,int y, int u, int v)
{
    int n,d;
    n= x*v;
    d= y*u;
    simplificar_fracao (n,d);
}

//Função auxiliar para calcular o Maximo divisor comum
int mdc (int x,int y)
{
    int r = 1;
    while (r!=0)
    {
        r = x % y; //Resto da divisão
        x=y;
        y=r;
    }
    return x; //Quando o resto é zero, o último divisor é o MDC
}

//Função para simplificar a fração dividino o numerador e o denominador...
void simplificar_fracao (int x, int y)
{
    int m,n,d;
    m= mdc(x,y); // Encontra o MDC entre o numerador e o denominador
    n = x/m; //Divide o numerador pelo MDC
    d = y/m; //Divide o denominador pelo MDC
    printf("Resultado ; %d / %d\n", n,d);
    system ("PAUSE"); //Aguarda o usuário pressionar uma tecla
}
