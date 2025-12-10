#include <stdio.h>
#include <math.h>
#include "imposto.h"

int aproximadamente_igual(double a, double b, double tol)
{
    return fabs(a - b) <= tol;
}

int main(void)
{
    int falhou = 0;

    struct caso_teste {
        double renda;
        double esperado;
    };

    /* Um valor no meio de cada faixa */
    struct caso_teste testes[] = {
        { 2000.00, 0.00 },      /* isento */
        { 2500.00, 5.34 },      /* 7,5% */
        { 3000.00, 55.84 },     /* 15%  */
        { 4000.00, 224.51 },    /* 22,5% */
        { 5000.00, 466.27 }     /* 27,5% */
    };

    int n = sizeof(testes) / sizeof(testes[0]);
    double tol = 0.05; /* tolerancia por causa de ponto flutuante */

    for (int i = 0; i < n; i++) {
        double r = testes[i].renda;
        double esperado = testes[i].esperado;
        double obtido = calcular_imposto(r);

        if (!aproximadamente_igual(obtido, esperado, tol)) {
            falhou = 1;
            printf("FALHA: renda = %.2f, esperado = %.2f, obtido = %.2f\n",
                   r, esperado, obtido);
        }
    }

    if (!falhou) {
        printf("Todos os testes em C passaram.\n");
        return 0;
    }

    return 1;
}