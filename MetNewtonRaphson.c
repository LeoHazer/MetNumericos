/*
    Esse programa calcula o zero de uma função contínua f pelo método de Newton-Raphson.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>



// Definição da função diferenciável.
double f(double x){
  double result = 4629.0 * pow(x, 10.0) - 4980.0 * (pow(x, 9.0) + pow(x, 8.0) + pow(x, 7.0) + pow(x, 6.0) + pow(x, 5.0) + pow(x, 4.0) + pow(x, 3.0) + pow(x, 2.0) + x + 1.0);
  // Troque <expr> pela expressão da f(x).
  return result;
}

// Definição da função derivada de f(x) com relação à variável x.
double df(double x){
  double result = 46290.0 * pow(x, 9.0) - 4980.0 * (9.0 * pow(x, 8.0) + 8.0 * pow(x, 7.0) + 7.0 * pow(x, 6.0) + 6.0 * pow(x, 5.0) + 5.0 * pow(x, 4.0) + 4.0 * pow(x, 3.0) + 3.0 * pow(x, 2.0) + 2.0 * x + 1.0);
  return result;
}


double MetNewtonRaphson(double x0, double Erro_tol) {
    int n = 0;  // Inicializa contador de iterações.
    int
    CriterioDeParadaAtendido = 1; // Incializa controle.
    double Er = 0; // Inicializa erros.
    double Ex = 0;
    double x_n_menos_1 = x0;    // Guarda valor inicial.
    do{
        if (df(x_n_menos_1) == 0) /* Teste de admissibilidade */
        {
            printf("O método não converge. Inicie novamente com outro valor inicial.\n");
            CriterioDeParadaAtendido = 0;
            break;
        }

        ++n; // Atualiza o contador de iterações.

        // Calcula a solução aproximada com a equação iterativa.
        double x_n = x_n_menos_1 - f(x_n_menos_1)/df(x_n_menos_1);

        if (f(x_n) == 0)
        {
            printf("A solução exata é x[%2d] = %.14lf\n",n,x_n);
            CriterioDeParadaAtendido = 0;
            break;
        }

        // Cálculo dos erros associados.
        Er = fabsf(f(x_n));
        Ex = fabsf(x_n - x_n_menos_1);

        // Imprime dados parciais.
        printf("x[%2d] = %.25lf | Er[%2d] = %.14lf | Ex[%2d] = %.14lf\n",n,x_n,n,Er,n,Ex);

        x_n_menos_1 = x_n;  // Guarda o valor de x_n.

    }while(Er > Erro_tol || Ex > Erro_tol);

    if (CriterioDeParadaAtendido)
    {
        printf("O valor aproximado do zero da função é x[%2d] = %.14lf\n",n,x_n_menos_1);
    }
    return 0;
}

int main(){

    setlocale(LC_ALL, NULL);

    double x_0, Erro_tol;

    printf("Método de Newton-Raphson\n\n");
    printf("Entre com o valor Inicial.\n");
    printf("x[0] = ");
    scanf("%lf",&x_0);
    printf("Digite o erro tolerado: ");
    scanf("%lf", &Erro_tol);
    double result = MetNewtonRaphson(x_0,Erro_tol);
    return 0;
}
