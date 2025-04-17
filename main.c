#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void obter_fracoes();
void somar_fracoes(int x, int y, int u, int v);
void subtrair_fracoes(int x, int y, int u, int v);
void multiplicar_fracoes(int x, int y, int u, int v);
void dividir_fracoes(int x, int y, int u, int v);
void simplificar_fracao(int x, int y);

//Vari�vel Global
int a, b, c, d;

//Fun��o principal
int main(int args, char *arg[])
{
    char r; //Variavel para armazenar a escolha do usuario
    //Loop principal do programa
    while (1)
    {
        system("CLS"); // Limpa a tela (espec�fico do Windows)
        printf("1. Somar\n");
        printf("2. Subtrair\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("9. Fim\n");
        printf("O que deseja? ");
        r = getche(); //L� uma tecla do usu�rio sem precisar
        if (r =='9') // Sai do loop se a op��o for 9
        break;

        obter_fracoes (); //Pede ao usu�rio que insira duas fra��es

        //Executa a opera��o conforme a escolha do usu�rio
        switch (r)
        {
            case '1' : somar_fracoes(a,b,c,d);break;
            case '2' : subtrair_fracoes(a,b,c,d);break;
            case '3' : multiplicar_fracoes(a,b,c,d);break;
            case '4' : dividir_fracoes (a,b,c,d); break;
        }
    }

    return 0; // Fim da fun��o main
}
//Fun��o para obter as duas fra��es do usu�rio
void obter_fracoes ()
{
    printf("\n1a fracao: ");
    scanf ("%d %d", &a, &b); //L� o numerador e o denominador 1a fracao
    printf("\n2a fracao: ");
    scanf ("%d %d", &c, &d); //L� o numerador e o denominador 2a fracao
}

//Fun��o para somar duas fra��es: (x/y) + (u/v)
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

//Fun��o auxiliar para calcular o Maximo divisor comum
int mdc (int x,int y)
{
    int r = 1;
    while (r!=0)
    {
        r = x % y; //Resto da divis�o
        x=y;
        y=r;
    }
    return x; //Quando o resto � zero, o �ltimo divisor � o MDC
}

//Fun��o para simplificar a fra��o dividino o numerador e o denominador...
void simplificar_fracao (int x, int y)
{
    int m,n,d;
    m= mdc(x,y); // Encontra o MDC entre o numerador e o denominador
    n = x/m; //Divide o numerador pelo MDC
    d = y/m; //Divide o denominador pelo MDC
    printf("Resultado ; %d / %d\n", n,d);
    system ("PAUSE"); //Aguarda o usu�rio pressionar uma tecla
}
